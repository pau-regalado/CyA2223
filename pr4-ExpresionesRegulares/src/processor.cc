// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : Processor.cc
// Contiene la implementacion de la clase Processor

#include "../include/processor.h"

Processor::Processor(std::string dataFile, std::string outFile) : inputFile_(dataFile) {

  outFile_ = outFile;
/** Abre los ficheros de entrada y salida, obtiene cada linea, la procesa y la
 * imprime en el fichero de salida */
  // Si el fichero de entrada no existe: ERROR
  if (!inputFile_.is_open()) {
    std::cout << "[Error]: could not open " << dataFile << std::endl;
    ready_ = false;
  } else {
    // Si el fichero entrada esta vacío: ERROR
    if (inputFile_.get() == EOF) {
      std::cout << "[Error]: " << dataFile  << " is empty" << std::endl;
      ready_ = false;
    } else {
    // Si consigue leer, reinicia a la posición 0 del fichero
      inputFile_.seekg(0, inputFile_.beg); // Reiniciamos el puntero de lectura al principio para correguir la lectura de arriba
      ready_ = true;
    }
  }
  if (ready_) {
    std::string line;
    int cont = 1;
    while(std::getline(inputFile_, line)) {
      run(line, cont);
      cont++;
    }
    printData();
  }
  inputFile_.close();
}

Processor::~Processor() {}

bool Processor::isReady() {
  return ready_;
}

void Processor::run(std::string line, int& lineNum) {
  std::smatch matches;
  if (std::regex_match(line, matches, firstCommentsExp)) {
    std::string content = std::string(matches[0]);
    int startLine = lineNum;
    while(std::getline(inputFile_, line) && !std::regex_search(line, matches, lastCommentsExp)) {
      content += "\n" + line;
      lineNum++;
    }
    content += matches[0];
    Token token(Token_type::COMMENT, content, startLine, lineNum);
    if (token.startLine() == 1) {
      token.setContenido("DESCRIPTION: ");
    }
    comments_.push_back(token);
    lineNum++;

  } else if (std::regex_match(line, matches, std::regex(forExp))) {
    Token token(Token_type::FOR, "for", lineNum);
    for_.push_back(token);

  }else if (std::regex_match(line, matches, std::regex(whileExp))) {
    Token token(Token_type::WHILE, "while", lineNum);
    while_.push_back(token);  


  }else if(std::regex_search (line, matches, varExp)) {
    Token token(matches[1] == "int " ? Token_type::INT : Token_type::DOUBLE, matches[0], lineNum);
    vars_.push_back(token);

  }else if (std::regex_match(line, matches, lineCommentExp)) {
    Token token(Token_type::COMMENT, matches[0], lineNum);
    comments_.push_back(token);

  }else if (std::regex_match(line, matches, std::regex(mainExp))) {
    Token token(Token_type::MAIN, matches[0], lineNum);
    main_.push_back(token);
  } else {
  }
}

void Processor::printData(void) {
  std:: ofstream outputFile(outFile_);
  outputFile << "VARIABLES:" << std::endl;
  for (unsigned i = 0; i < vars_.size(); i++) {
    outputFile << vars_[i].to_String() << std::endl;
  }
  outputFile << "LOOPS:" << std::endl;
  outputFile << "|- FOR:" << std::endl;
  for (unsigned i = 0; i < for_.size(); i++) {
    outputFile << for_[i].to_String() << std::endl;
  }
  outputFile << "|- WHILE:" << std::endl;
  for (unsigned i = 0; i < while_.size(); i++) {
    outputFile << while_[i].to_String() << std::endl;
  }
  outputFile << "COMMENTS:" << std::endl;
  for (unsigned i = 0; i < comments_.size(); i++) {
    outputFile << comments_[i].to_String() << std::endl;
  }
  outputFile << "MAIN:" << std::endl;
  for (unsigned i = 0; i < main_.size(); i++) {
    outputFile << main_[i].to_String() << std::endl;
  }
  outputFile.close();
}

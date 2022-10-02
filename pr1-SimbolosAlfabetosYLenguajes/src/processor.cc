// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo :
// Contiene

#include "../include/processor.h"

Processor::Processor(std::string dataFile, std::string outputFile, char* opcode) {
  std::fstream inputFile(dataFile);
  if (!inputFile.is_open()) {
    std::cout << "[Error]: could not open " << dataFile << std::endl;
    _ready = false;
  } else {
    if (inputFile.get() == EOF) {
      std::cout << "[Error]: " << dataFile  << " is empty" << std::endl;
      _ready = false;
    } else {
      inputFile.seekg(0, inputFile.beg); // Reiniciamos el puntero de lectura al principio para correguir la lectura de arriba
      _ready = true;
    }
  }

  _opcode = opcode;

  if (!isReady()) {
    std::cout << "Aborting program" << std::endl;
  } else {
    std::string line, result;
    while (std::getline(inputFile, line)) {
      result = run(line);
    }
  }
}

Processor::~Processor() {
  /*if (inputFile) {
    inputFile->close();
  }*/
}

bool Processor::isReady() {
  return _ready;
}

std::string Processor::run(std::string line) {
  std::vector<std::string> stringVector; 
  unsigned character = 0; 
  while(character <= line.size()) {
    std::string aux;
    while(character <= line.size() && line[character] != ' '){
      aux.push_back(line[character]);
      character++;
    }    
    stringVector.push_back(aux);
    character++;
  }

  std::cout <<"------------------------------" << std::endl;
  std::cout <<"LINEA = " << line << std::endl;
  for (unsigned i = 0; i < stringVector.size(); i++) {
    std::cout << "[" << i << " ] = " << stringVector[i] << std::endl;
  }
      
  std::cout <<"------------------------------" << std::endl;


  switch (_opcode)
  {
  case '1':
    // LONGITUD
    //return objetocadena.size();
    break;
  
  default:
    break;
  }
  return line;
}
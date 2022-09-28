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

Processor::Processor(std::string dataFile, std::string outputFile, std::string opcode) {
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
  switch ('u')
  {
  case 'u':
    /* code */
    break;
  
  default:
    break;
  }
  std::cout << line << std::endl;
  return line;
}
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

#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include "processor.h"

Processor::Processor(std::string dataFile) {

/** Abre los ficheros de entrada y salida, obtiene cada linea, la procesa y la
 * imprime en el fichero de salida */
  std::fstream inputFile(dataFile);
  // Si el fichero de entrada no existe: ERROR
  if (!inputFile.is_open()) {
    std::cout << "[Error]: could not open " << dataFile << std::endl;
    ready_ = false;
  } else {
    // Si el fichero entrada esta vacío: ERROR
    if (inputFile.get() == EOF) {
      std::cout << "[Error]: " << dataFile  << " is empty" << std::endl;
      ready_ = false;
    } else {
    // Si consigue leer, reinicia a la posición 0 del fichero
      inputFile.seekg(0, inputFile.beg); // Reiniciamos el puntero de lectura al principio para correguir la lectura de arriba
      ready_ = true;
    }
  }
  if (ready_) {
    std::string line;
    while(std::getline(inputFile, line)) {
        //std::cout << run(line) << std::endl;
    }
  }
  inputFile.close();

}

bool Processor::isReady() {
  return ready_;
}

std::vector<std::string> Processor::run(std::string line) {
  unsigned character = 0;
  std::vector<std::string> result;  
  while(character <= line.size()) {
    std::string aux;
    while(character <= line.size() && line[character] != ' '){
      aux.push_back(line[character]);
      character++;
    }
    result.push_back(aux);
    character++;
  }
  return result;
}


int main() {
std::string target_s = "I am looking for GeeksForGeeks articles";

std::regex expression("Geeks[a-zA-Z]+ ");

std::smatch matches;

regex_search(target_s, matches, expression);
for (auto match : matches)
std::cout << match << std::endl;
return 0;
}
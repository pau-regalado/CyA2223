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

#ifndef __PROCESSOR__
#define __PROCESSOR__

#include <iostream>
#include <fstream>
#include <string>

class Processor {
  public:
    Processor(std::string dataFile, std::string outputFile, int opcode);
    ~Processor();

    // Getters
    bool isReady();
    bool validateOpcode();

    std::string run(std::string line);

  private:
    bool _ready;
    int _opcode;
    // std::fstream* inputFile, outputFile;
};

#endif
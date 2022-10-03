// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : processor.h
// Contiene la definicion de la clase Processor

#ifndef __PROCESSOR__
#define __PROCESSOR__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/alphabet.h"
#include "../include/string.h"

/**
 * Clase encargada de la lectura y escritura de ficheros, y el procesado de cada linea 
 */
class Processor {
  public:
    Processor(std::string dataFile, std::string outputFile, char opcode);
    ~Processor();

    // Getters
    bool isReady();
    bool validateOpcode();

    std::string run(std::string line);

  private:
    bool ready_;
    char opcode_;
};

#endif
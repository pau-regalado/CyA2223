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
#include <set>
#include "../include/alphabet.h"
#include "../include/string.h"
#include "../include/lenguage.h"

/**
 * Clase encargada de la lectura y escritura de ficheros, y el procesado de cada linea 
 */
class Processor {
  public:
    Processor(int argc, char** params);
    ~Processor();

    void initializer(std::string dataFile1, std::string dataFile2, std::string output);
    void help(void);

    // Getters
    bool isReady();
    //bool validateOpcode();

    std::fstream& openFile(std::string name);
    std::string run(std::string line);
    std::string runBinary(std::string line1, std::string line2);
    void createAlphabet(Alphabet& alphabet, std::string line);
    void createLanguage(Lenguage& lenguaje, std::string line);

  private:
    bool ready_;
    char opcode_;
    std::set<char> op_unarias  = {'p', 'i'};
    std::set<char> op_binarias = {'c', 'u', 'd', 's'};
};
#endif

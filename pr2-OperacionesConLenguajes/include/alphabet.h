// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : alphabet.h
// Contiene la definicion de la Clase Alphabet

#ifndef __ALPHABET__
#define __ALPHABET__

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include "string.h"

/**
 * Representa un alfabeto, un conjunto de simbolos 
 */
class Alphabet {
  public:
    Alphabet(void);
    Alphabet(std::vector<std::string> alphabet);
    Alphabet(std::string alphabet);
    ~Alphabet();

    void addSymbol(std::string symbol);

    bool belongsTo(String string);
    std::set<std::string>& getSymbols(void);

    std::string toString(void);

    Alphabet& operator=(Alphabet& a);
    friend std::ostream& operator<<(std::ostream& os, Alphabet& a);

  private:
    std::set<std::string> symbols_;
};

#endif
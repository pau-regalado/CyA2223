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
    Alphabet(std::vector<std::string> alphabet);
    Alphabet(std::string alphabet);
    ~Alphabet();

    bool belongsTo(String string);

  private:
    std::set<char> _symbols;
};

#endif
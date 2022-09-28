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

#ifndef __ALPHABET__
#define __ALPHABET__

#include <iostream>
#include <vector>

class Alphabet {
  public:
    Alphabet();
    ~Alphabet();

  private:
    std::vector<char> _simbolos;
};

#endif
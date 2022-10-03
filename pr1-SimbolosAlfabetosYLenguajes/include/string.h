// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : string.h
// Contiene la definicion de la clase String

#ifndef __STRING__
#define __STRING__

#include <iostream>
#include <vector>
#include <string>

/**
 * Representa una cadena, una secuencia de simbolos
 * que puede realizar una serie de calculos sobre ella
 */
class String {
  public:
    String(std::string self);
    String(std::vector<char> self);
    ~String();

    // Getters
    std::vector<char> getSelf(void);

    // Func methods
    std::string length(void);
    std::string reverse(void);
    std::string prefix(void);
    std::string sufix(void);
    std::string substrings(void);
    
  private:
    std::vector<char> _self;
};

#endif
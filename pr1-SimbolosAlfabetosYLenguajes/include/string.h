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

#ifndef __STRING__
#define __STRING__

#include <iostream>
#include <string>

class String {
  public:
    String(std::string self);
    ~String();

    // Func methods
    int lenght(void);
  private:
    std::string _self;
};

#endif
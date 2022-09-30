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

#include <iostream>
#include <string>

#include "../include/processor.h"

enum parser{INNAME = 1, OUTNAME, OPCODE};

int main (int argc, char** argv) {
  Processor reader(argv[INNAME], argv[OUTNAME], argv[OPCODE]);
  return 0;
}
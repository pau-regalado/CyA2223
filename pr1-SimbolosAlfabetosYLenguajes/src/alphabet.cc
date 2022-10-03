// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : alphabet.cc
// Contiene la implementacion de la clase Alphabet

#include "../include/alphabet.h"

// Obtiene los simbolos de un vector de cadenas y los almacena en
// un conjunto
Alphabet::Alphabet(std::vector<std::string> alphabet) {
  // Debemos meter siempre la cadena vacia en el alfabeto?
  _symbols.insert('&');
  for (unsigned i = 0; i < alphabet.size(); i++) {
    _symbols.insert(alphabet[i][0]);
  }
}

// Obtiene los simbolos de una cadena y los almacena en
// un conjunto
Alphabet::Alphabet(std::string string) {
  // Sacamos el alfabeto de la cadena
  _symbols.insert('&');
  for (unsigned i = 0; i < string.size(); i++) {
    _symbols.insert(string[i]);
  }
}

Alphabet::~Alphabet() {  
}

// Comprueba si una cadena esta formada por simbolos del alfabeto
bool Alphabet::belongsTo(String string) {
  for (unsigned i = 0; i < string.getSelf().size(); i++) {
    if (_symbols.count(string.getSelf()[i]) == 0)
      return false;
  }
  return true;
}
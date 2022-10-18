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

Alphabet::Alphabet(void) {
}

// Obtiene los simbolos de un vector de cadenas y los almacena en
// un conjunto
Alphabet::Alphabet(std::vector<std::string> alphabet) {
  // Debemos meter siempre la cadena vacia en el alfabeto?
  symbols_.insert("&");
  for (unsigned i = 0; i < alphabet.size(); i++) {
    symbols_.insert(std::string(1, alphabet[i][0]));
  }
}

// Obtiene los simbolos de una cadena y los almacena en
// un conjunto
Alphabet::Alphabet(std::string string) {
  // Sacamos el alfabeto de la cadena
  symbols_.insert("&");
  for (unsigned i = 0; i < string.size(); i++) {
    symbols_.insert(std::string(1, string[i]));
  }
}

Alphabet::~Alphabet() {  
}

// Añade un simbolo al alfabeto
void Alphabet::addSymbol(std::string symbol) {
  symbols_.insert(symbol);
}

// Obtiene los simbolos de un alfabeto
std::set<std::string>& Alphabet::getSymbols(void) {
  return symbols_;
}

// Comprueba si una cadena esta formada por simbolos del alfabeto
bool Alphabet::belongsTo(String string) {
  for (unsigned i = 0; i < string.getSelf().size(); i++) {
    if (symbols_.count(string.getSelf()[i]) == 0)
      return false;
  }
  return true;
}

// Convierte los datos del alfabeto en una cadena
std::string Alphabet::toString(void) {
  std::string aux = "{ ";
  for (auto i = symbols_.cbegin(); i != symbols_.cend(); i++) {
    aux += (*i) + " ";
  }
  return aux += "}";
}

Alphabet& Alphabet::operator=(Alphabet& a) {
  this->symbols_ = a.getSymbols();
  return *this;
}

std::ostream& operator<<(std::ostream& os, Alphabet& a) {
  os << "Alfabeto: " << a.getSymbols().size() << " { ";
  for (auto i = a.getSymbols().cbegin(); i != a.getSymbols().cend(); i++) {
    os << "'" << *i << "' ";
  }
  os << "}" << std::endl;
  return os;
}
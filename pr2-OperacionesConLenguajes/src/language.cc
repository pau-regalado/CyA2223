// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : lenguaje.cc
// Contiene la implementacion de la clase lenguaje

#include "../include/lenguage.h"

// Obtiene los simbolos de un vector de cadenas y los almacena en
// un conjunto
Lenguage::Lenguage(void) {}

Lenguage::Lenguage(std::set<String> lenguage) {
  self_ = lenguage;
}

Lenguage::~Lenguage() {  
}

void Lenguage::setAlphabet(Alphabet& alphabet) {
  alphabet_ = alphabet;
}

// Actualiza el alfabeto del lenguaje añadiendo todos
// los simbolos que aparecen en las cadenas
void Lenguage::updateAlphabet(void) {
  for (auto it = self_.begin(); it != self_.end(); it++) {
    for (unsigned c = 0; c < (*it).getSelf().size(); c++) {
      alphabet_.addSymbol((*it).getSelf()[c]);
    }
  }
}

// Añade una cadena al lenguaje
void Lenguage::addString(String string) {
  self_.insert(string);
  updateAlphabet();
}

// Elimina una cadena del lenguaje
void Lenguage::removeString(String string) {
  self_.erase(string);
  updateAlphabet();
}

// Obtiene el conjunto de cadenas del lenguaje
std::set<String>& Lenguage::getSelf(void) {
  return self_;
}

// Obtiene el alfabeto del lenguaje
Alphabet& Lenguage::getAlphabet(void) {
  return alphabet_;
}

// A cada cadena del lenguaje invocador, le concatena cada cadena del
// lenguaje especificado
Lenguage Lenguage::concatenate(Lenguage& lenguaje) {
  Lenguage result;
  for (String str1: self_) {
    for (String str2: lenguaje.getSelf()) {
      result.addString(str1.concatenate(str2));
    }
  }
  result.updateAlphabet();
  return result;
}

// Calcula el lenguaje resultante de la union
// añade los elementos del lenguaje especificado al del invocador
Lenguage Lenguage::lunion(Lenguage& lenguaje) {
  Lenguage result(self_);
  for (auto it = lenguaje.getSelf().begin(); it != lenguaje.getSelf().end(); it++) {
    result.addString(*it);
  }
  result.updateAlphabet();
  return result;
}

// Calcula el lenguaje resultante de la interseccion
// Crea un lenguaje con las cadenas que estan en ambos
Lenguage Lenguage::interssection(Lenguage& lenguaje) {
  Lenguage result;
  for (auto it = lenguaje.getSelf().begin(); it != lenguaje.getSelf().end(); it++) {
    if (self_.count(*it) == 1) {
      result.addString(*it);
    }
  }
  result.updateAlphabet();
  return result;
}

// Calcula el lenguaje resultante de la interseccion
// Elimina los elementos del lenguaje especificado del invocador
Lenguage Lenguage::difference(Lenguage& lenguaje) {
  Lenguage result(self_);
  for (auto it = lenguaje.getSelf().begin(); it != lenguaje.getSelf().end(); it++) {
    result.removeString(*it);
  }
  result.updateAlphabet();
  return result;
}

// Calcula el lenguaje inverso
Lenguage Lenguage::reverse(void) {
  Lenguage result;
  for (auto i = self_.cbegin(); i != self_.cend(); i++) {
    result.addString((*i).reverse());
  }
  return result;
}

// Calcula la potencia power del lenguaje
Lenguage Lenguage::power(unsigned power) {
  Lenguage result;
  std::set<String>::iterator i;
  // Cada cadena del invocador desde la cadena vacia inicializada en string
  // se le concatena esa misma cadena
  for (i = self_.begin(); i != self_.end(); i++) {
    String string;
    for (unsigned j = 0; j < power; j++) {
      String base((*i).getSelf());
      string = string.concatenate(base);
    }
    result.addString(string);
  }
  return result;
}

// Convierte los datos del lenguaje en una cadena
std::string Lenguage::toString(void) {
  std::string aux = "{ ";
  for (auto i = self_.cbegin(); i != self_.cend(); i++) {
    aux += (*i).toString() + " ";
  }
  return aux += "}";
}

// Convierte los datos del lenguaje en una cadena
std::string Lenguage::toString(void) const {
  std::string aux = "{ ";
  for (auto i = self_.cbegin(); i != self_.cend(); i++) {
    aux += (*i).toString() + " ";
  }
  return aux += "}";
}

// Sobrecarga del operador =
Lenguage& Lenguage::operator=(Lenguage l) {
  self_ = l.getSelf();
  alphabet_ = l.getAlphabet();
  return *this;
}

// Sobrecarga del operador<< para mostrar por consola
std::ostream& operator<<(std::ostream& os, Lenguage& a) {
  os << "Lenguaje: " << a.getSelf().size() << " { ";
  for (auto i = a.getSelf().cbegin(); i != a.getSelf().cend(); i++) {
    os << "'" << *i << "' ";
  }
  os << "}" << std::endl;
  return os;
}

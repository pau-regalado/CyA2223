#include "../include/string.h"

// Inicializa el vector de simbolos con el vector de simbolos recibido
String::String(std::vector<std::string> self): self_(self) {}

// Inicializa el vector de simbolos con los simbolos de la cadena recibida
String::String(std::string self) {
  for (unsigned i = 0; i < self.size(); i++)
    self_.push_back(std::string(1, self[i]));
}

// Vacia el vector
String::~String() {
  self_.clear();
}

// Devuelve la informacion de la clase
std::vector<std::string> String::getSelf(void) {
  return self_;
}


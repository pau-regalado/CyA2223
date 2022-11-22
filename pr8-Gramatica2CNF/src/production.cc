#include "../include/production.h"

Production::Production(void){}

Production::Production(std::string noTerminal, std::vector<std::string> prod) {
  noTerminal_ = noTerminal;
  producciones_ = prod;
}

Production::~Production(){}

// Obtiene el atributo producciones
std::vector<std::string> Production::getProducciones(void) const {
  return producciones_;
}

std::vector<std::string>& Production::getProducciones(void) {
  return producciones_;
}

std::string Production::getNonTerminal (void) const {
  return noTerminal_;
}

// Muestra por pantalla las producciones expresadas correctamente
std::ostream& operator<<(std::ostream& os, Production& p) {
  os << p.getNonTerminal();
  os << " -> ";
  for (std::string prod : p.getProducciones()) {
    os << prod;
  }
  return os;
}
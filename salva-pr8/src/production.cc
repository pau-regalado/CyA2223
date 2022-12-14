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

void Production::setProduccion(unsigned index, std::string prod) {
  producciones_[index] = prod;
}

void Production::addProduccion(std::string prod) {
  producciones_.push_back(prod);
}

std::string Production::getNonTerminal (void) const {
  return noTerminal_;
}

void Production::setNonTerminal(std::string nonTerminal) {
  noTerminal_ = nonTerminal;
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
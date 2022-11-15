#include "../include/production.h"

Production::Production(void){}

Production::Production(std::string terminal, std::string nonTerminal) {
  producciones_[terminal] = nonTerminal;
}

Production::~Production(){}

void Production::addProducction(std::string terminal, std::string nonTerminal) {
  producciones_[terminal] = nonTerminal;
}

// Obtiene el atributo producciones
std::map<std::string, std::string> Production::getProducciones(void) {
  return producciones_;
}

// Muestra por pantalla las producciones expresadas correctamente
std::ostream& operator<<(std::ostream& os, Production& p) {
  std::string result;
  for (auto prod : p.getProducciones()) {
    result += prod.first + prod.second + " | ";
  }
  result.erase(result.find_last_of("|") - 1);
  os << result;
  return os;
}
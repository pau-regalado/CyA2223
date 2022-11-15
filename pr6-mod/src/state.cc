#include "../include/state.h"
// Constructor de estado inicializando el atributo id y aceptación
State::State(unsigned id, bool aceptacion) {
  id_ = id;
  aceptacion_ = aceptacion;
}

State::State(void){
}
// Destructor del estado
State::~State() {}
// Obtener valor de ID
unsigned State::getID(void) {
  return id_;
}
// Comprueba si el estado es de aceptación
bool State::isAccept(void) {
  return aceptacion_;
}
//
void State::addTransition(std::string symbol, unsigned estado) { 
  transiciones_[symbol].push_back(estado);  
}
//
std::vector<unsigned> State::getTransition(std::string symbol) {
  return transiciones_[symbol];
}
//
std::map<std::string, std::vector<unsigned>> State::getTransitions(void) {
  return transiciones_;
} 

    
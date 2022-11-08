#include "../include/state.h"

State::State(unsigned id, bool aceptacion) {
  id_ = id;
  aceptacion_ = aceptacion;
}

State::State(void){
}

State::~State() {}

unsigned State::getID(void) {
  return id_;
}

bool State::isAccept(void) {
  return aceptacion_;
}

void State::addTransition(std::string symbol, unsigned estado) { 
  transiciones_[symbol].push_back(estado);  
}

std::vector<unsigned> State::getTransition(std::string symbol) {
  return transiciones_[symbol];
}

std::vector<unsigned> State::getStates(std::string symbol) {
  return transiciones_[symbol];  
}


    
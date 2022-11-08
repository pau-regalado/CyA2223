#include "../include/automata.h"

Automata::Automata(std::string Automata, std::string strings) {
  std::ifstream automataDesc(Automata);
  if (!automataDesc.is_open()) {
    std::cout << "Error. No se puede abrir el fichero: " << Automata << std::endl;
  } else {
    std::string line;
    std::getline(automataDesc, line);
    Alphabet alfabeto(line);
    int nEntradas, estadoaArranque;
    automataDesc >> nEntradas;
    automataDesc >> start_;
    
    unsigned nombreEstado, nombreEstadoActual;
    int estadoaAceptacion, nTransiciones;
    std::string transicion;
    for (int i = 0; i < nEntradas; i++) {
      automataDesc >> nombreEstado;
      automataDesc >> estadoaAceptacion;
      
      //map.find("nombreestadp" == map.end())
      states_[nombreEstado] = new State(nombreEstado, estadoaAceptacion);
      automataDesc >> nTransiciones;
      //std::cout << "nTransiciones '" << nTransiciones << "'" << std::endl;

      for (int j = 0; j < nTransiciones; j++) {
        automataDesc >> transicion;
        automataDesc >> nombreEstadoActual;
        states_[nombreEstado]->addTransition(transicion, nombreEstadoActual);
      }
    }

    // Por cada cadena la analizamos con el Automata
    std::ifstream inputStrings(strings);
    if (!inputStrings.is_open()) {
      std::cout << "Error. No se puede abrir el fichero: " << strings << std::endl;
    } else {
      std::string line;
      while (std::getline(inputStrings, line)) {
        evaluate(line);
      }
      inputStrings.close();
    }
  }
  automataDesc.close();
}

Automata::~Automata() {}

bool Automata::evaluate(std::string string) {
  bool ok = false;
  actualStates_.clear();
  actualStates_.insert(start_);
  std::set<unsigned> transitedStates;
  std::string symbol;
  // Calculamos para cada estado actual, el conjunto transitado
  for (int i = 0; i < string.size(); i++) {
    symbol = string[i];
    // Transitamos al propio estado
    if (symbol == "&") {
      transitedStates = actualStates_;
    }
    for (unsigned state : actualStates_) {
      for (unsigned stateIDs : states_[state]->getTransition(symbol)){
        transitedStates.insert(stateIDs);
      }
    }
    actualStates_ = transitedStates;
    transitedStates.clear();
  }

  // Chequeamos si estamos en un estado de aceptación
  for (unsigned state : actualStates_)
    if (states_[state]->isAccept())
      ok = true;

  std::cout << string << ((ok)?" --- Accepted" : " --- Rejected") << std::endl;
  return ok;
}
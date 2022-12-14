#include "../include/automata.h"

Automata::Automata(std::string Automata) {
  // Lee el fichero .fa y comprueba si tiene contenido
  std::ifstream automataDesc(Automata);
  if (!automataDesc.is_open()) {
    std::cout << "Error. No se puede abrir el fichero: " << Automata << std::endl;
  } else {
    std::string line;
    // Obtener simbolos de la primera linea y guardarlo en el objeto alfabeto
    std::getline(automataDesc, line);
    Alphabet alfabeto(line);
    alfabeto_ = alfabeto;
    // Obtiene el numero de estados y el estado de arranque
    int nEntradas;
    automataDesc >> nEntradas;
    automataDesc >> start_;
    
    
    unsigned nombreEstado, nombreEstadoActual;
    int estadoaAceptacion, nTransiciones;
    std::string transicion;
    // Con el numero de estado hacemos un for y recorremos
    // con otro for los transiciones y al estado al que llega
    for (int i = 0; i < nEntradas; i++) {
      automataDesc >> nombreEstado;
      automataDesc >> estadoaAceptacion;
      states_[nombreEstado] = new State(nombreEstado, estadoaAceptacion);
      automataDesc >> nTransiciones;

      for (int j = 0; j < nTransiciones; j++) {
        automataDesc >> transicion;
        automataDesc >> nombreEstadoActual;
        states_[nombreEstado]->addTransition(transicion, nombreEstadoActual);
      }
    }
  }
  automataDesc.close();
}
 // Desctructor del automata
Automata::~Automata() {}

void Automata::evaluateFromFile(std::string strings) {
  // Por cada cadena la analizamos con el Automata
  std::ifstream inputStrings(strings);
  // Comprueba que existe el fichero
  if (!inputStrings.is_open()) {
    std::cout << "Error. No se puede abrir el fichero: " << strings << std::endl;
  } else {
    std::string line;
    // Mientras haya algo en la línea, se comprueba si es aceptado por el dfa
    while (std::getline(inputStrings, line)) {
      evaluate(line);
    }
    inputStrings.close();
  }
}

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

Gramatica Automata::convertToGrammar(void) {
  std::map<unsigned, std::string> estadosnombre;
  // Creamos el objeto gramatica y le pasamos los atributos del automata
  // que puede reutilizar gramatica
  Gramatica result;
  result.setAlphabet(alfabeto_);
  result.setStart(start_);
  std::string nTerminal;
  for (auto p: states_) {
    State* state = p.second;
    nTerminal = "Q" + std::to_string(state -> getID());
    result.addNonTerminalSymbol(nTerminal);
    for (auto transition : state->getTransitions()) {
      for (unsigned transitedState : transition.second) {
        std::string auxNonTerminal = "Q" + std::to_string(transitedState);
        // Si el estado es de aceptacion, añade una cadena vacia
        if (states_[transitedState]->isAccept()) {
          result.addProduction(auxNonTerminal, "&", "");
        }
        result.addNonTerminalSymbol(auxNonTerminal);
        result.addProduction(nTerminal, transition.first, auxNonTerminal);
      }
    } 
  }
  return result;
}
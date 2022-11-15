#include "../include/gramatica.h"
#include "../include/alphabet.h"


Gramatica::Gramatica(void) {}

Gramatica::~Gramatica() {}

//Obtiene el alfabeto
void Gramatica::setAlphabet(Alphabet alphabet) {
  alfabeto_ = alphabet;
}

// Obtiene el simbolo de arranque
void Gramatica::setStart(unsigned start) {
  start_ = start;
}

// Obtiene las producciones de la gramatica
void Gramatica::addProduction(std::string state, std::string terminal, std::string noTerminal) {
  if (producciones_[state] != nullptr) {
    producciones_[state]->addProducction(terminal, noTerminal);
  } else {
    Production* p = new Production(terminal, noTerminal);
    producciones_[state] = p;
  }
}

// Obtiene los simbolos no terminales
void Gramatica::addNonTerminalSymbol(std::string noTerminal) {
  nonTerminalSymbol_.insert(noTerminal);
}

void Gramatica::writeOnFile(std::string outputFileName) {
  std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
      std::cout << "Error. No se puede abrir el fichero: " << outputFileName << std::endl;
    } else {
      // Muestra el numero de simbolos del alfabeto y cada uno de ellos
      outputFile << "Número de simbolos terminales: ";
      outputFile << alfabeto_.getSymbols().size() << std::endl;
      outputFile << "Alfabeto: {";
      for (std::string symbol : alfabeto_.getSymbols()) {
        outputFile << symbol << " ";
      }
      outputFile << "}" << std::endl;
      // Muestra el numero de estados y sus nombres
      outputFile << "Número de simbolos no terminales: ";
      outputFile << nonTerminalSymbol_.size() << std::endl;
      outputFile << "V: {";
      for (std::string symbol : nonTerminalSymbol_) {
        outputFile << symbol << " ";
      }
      outputFile << "}" << std::endl;
      // Muestra el numero de producciones y sus detalles
      outputFile << producciones_.size() << std::endl;
      for (auto prod : producciones_) {
        outputFile << prod.first << " -> " << *prod.second << std::endl;
      }
      outputFile.close();
    }
}
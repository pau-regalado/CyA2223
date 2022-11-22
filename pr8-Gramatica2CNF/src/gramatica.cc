#include "../include/gramatica.h"

Gramatica::Gramatica(void) {}

Gramatica::~Gramatica() {}

void Gramatica::readOnFile(std::string inputFileName) {
std::ifstream gramaticaDesc(inputFileName);
  if (!gramaticaDesc.is_open()) {
    std::cout << "Error. No se puede abrir el fichero: " << inputFileName << std::endl;
  } else {
    std::string line;
    // Obtener simbolos de la primera linea y guardarlo en el objeto alfabeto
    Alphabet alfabeto;
    // Obtiene el numero de estados y el estado de arranque
    int nAlfabeto, nNonTerminal, nProduc;
    std::string alfabet, nonTerminal;
    std::vector<std::string> produc;
    gramaticaDesc >> nAlfabeto;
    for (int i = 0; i < nAlfabeto; i++) {
      gramaticaDesc >> alfabet;
      alfabeto.addSymbol(alfabet);
    }
      alfabeto_ = alfabeto;
    
    gramaticaDesc >> nNonTerminal;
    gramaticaDesc >> start_;
    addNonTerminalSymbol(start_);
    for (int i = 0; i < nNonTerminal - 1; i++) {
      gramaticaDesc >> nonTerminal;
      addNonTerminalSymbol(nonTerminal);
    }

    gramaticaDesc >> nProduc;
    for (int i = 0; i < nProduc; i++) {
      std::string noTerminal;
      std::string auxProd;
      gramaticaDesc >> noTerminal;
      //Guarda el "->"
      gramaticaDesc >> auxProd;
      gramaticaDesc >> auxProd;
      produc.resize(auxProd.length());
      for (int i = 0; i < auxProd.length(); i++) {
        produc[i] = std::string(1, auxProd[i]);
        if (produc[i] == "&" && noTerminal != start_) {
          std::cout << "PRODUCCION VACIA" << std::endl;
        }
      }     
      if (produc.size() == 1 && nonTerminalSymbol_.count(produc[0]) == 1) {
        std::cout << "PRODUCCION UNITARIA" << std::endl;
      }
      addProduction(noTerminal, produc);
    }
  }
  gramaticaDesc.close();
}

//Obtiene el alfabeto
void Gramatica::setAlphabet(Alphabet alphabet) {
  alfabeto_ = alphabet;
}

// Obtiene el simbolo de arranque
void Gramatica::setStart(unsigned start) {
  start_ = start;
}

// Obtiene las producciones de la gramatica
void Gramatica::addProduction(std::string noTerminal, std::vector<std::string> prod) {
  Production p = Production(noTerminal, prod);
  producciones_.push_back(p);
}

// Obtiene los simbolos no terminales
void Gramatica::addNonTerminalSymbol(std::string noTerminal) {
  nonTerminalSymbol_.insert(noTerminal);
}

bool Gramatica::isEmpty() {
  return empty_;
}

void Gramatica::convert2CFG() {
  for (auto prod : producciones_){
    if (prod.getProducciones().size() >= 2) {
      for (unsigned i = 0; i < prod.getProducciones().size(); i++) {
        if (alfabeto_.getSymbols().find(prod.getProducciones()[i]) != alfabeto_.getSymbols().end()) {
          char last = (*(nonTerminalSymbol_.crbegin()))[0];
          char next = last+1;
          addProduction(std::string(1, next), {prod.getProducciones()[i]});
          nonTerminalSymbol_.insert(std::string(1, next));  
          prod.getProducciones()[i] = std::string(1, next);
        }
      }
    }
  }
  for (auto produc : producciones_){
    if (produc.getProducciones().size() >= 3) {
      char last = (*(nonTerminalSymbol_.crbegin()))[0];
      char next = last;
      std::vector<std::string> siguientes;
      for (unsigned i = 0; i <= produc.getProducciones().size() - 2; i++) {
        next = next + 1;
        siguientes.push_back(std::string(1, next));
        while(produc.getProducciones().size() > 2) {
          auto p = produc.getProducciones();
          auto last = p[p.size() - 1];
          auto antelast = p[p.size() - 2];
          auto new_prod = {antelast, last};
          produc.getProducciones().pop_back();
          produc.getProducciones().pop_back();
          auto nonTerminal = siguientes.back();
          siguientes.pop_back();
          addProduction(nonTerminal, new_prod);
          nonTerminalSymbol_.insert(nonTerminal);
          produc.getProducciones().push_back(nonTerminal);

        }
      }
    }
  }
}

void Gramatica::writeOnFile(std::string outputFileName) {
  std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
      std::cout << "Error. No se puede abrir el fichero: " << outputFileName << std::endl;
    } else {
      // Muestra el numero de simbolos del alfabeto y cada uno de ellos
      outputFile << alfabeto_.getSymbols().size() << std::endl;
      for (std::string symbol : alfabeto_.getSymbols()) {
        outputFile << symbol << std::endl;
      }
      // Muestra el numero de estados y sus nombres
      outputFile << nonTerminalSymbol_.size() << std::endl;
      for (std::string symbol : nonTerminalSymbol_) {
        outputFile << symbol << std::endl;
      }
      // Muestra el numero de producciones y sus detalles
      outputFile << producciones_.size() << std::endl;
      for (Production prod : producciones_) {
        outputFile << prod << std::endl;
      }
      outputFile.close();
    }
}
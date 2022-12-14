#include "../include/gramatica.h"

Gramatica::Gramatica(void) {}

Gramatica::~Gramatica() {}

bool Gramatica::readOnFile(std::string inputFileName) {
  bool ok = true;
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
          ok = false;
        }
      }     
      if (produc.size() == 1 && nonTerminalSymbol_.count(produc[0]) == 1) {
        std::cout << "PRODUCCION UNITARIA" << std::endl;
        ok = false;
      }
      addProduction(noTerminal, produc);
    }
  }
  gramaticaDesc.close();
  return ok;
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

bool Gramatica::isInFNCProds(std::string p) {
  for (Production prod : FNCproducciones_) {
    if (prod.getProducciones()[0] == p) {
      return true;
    }
  }
  return false;
}

std::string Gramatica::returnFNCProd(std::string p) {
  std::string result;
  for (Production prod : FNCproducciones_) {
    if (prod.getProducciones()[0] == p) {
      result = prod.getNonTerminal();
    }
  }
  return result;
}

void Gramatica::convert2CFG() {
  lastProdName_ = (*nonTerminalSymbol_.rbegin())[0];
  for (int prod = 0; prod < producciones_.size(); prod++) {
    if (producciones_[prod].getProducciones().size() >= 2) {
      for (std::string p : producciones_[prod].getProducciones()) {
        if (alfabeto_.getSymbols().count(p) == 1) { // si es un terminal
          if (!isInFNCProds(p)) { //Si no existe ya un nuevo estado hacia ese terminal
            FNCproducciones_.push_back(Production(std::string(1, ++lastProdName_), {p}));
            for (int i = 0; i < producciones_[prod].getProducciones().size(); i++) {
              if (producciones_[prod].getProducciones()[i] == p){
                producciones_[prod].getProducciones()[i] = std::string(1, lastProdName_);
              }
            }
          } else {
            std::string name = returnFNCProd(p);
            for (int i = 0; i < producciones_[prod].getProducciones().size(); i++) {
              if (producciones_[prod].getProducciones()[i] == p){
                producciones_[prod].getProducciones()[i] = name;
              }
            }
          }
        }
      }
    }
  }
  /*
  for (auto produc : producciones_){
    if (produc.getProducciones().size() >= 3) {
      char last = (*(nonTerminalSymbol_.rbegin()))[0];
      char next = last;
      std::vector<std::string> siguientes;
      Production newProd;
      newProd.setNonTerminal(produc.getNonTerminal());
      for (unsigned i = 0; i <= produc.getProducciones().size() - 2; i++) {
        siguientes.push_back(std::string(1, ++next));
        while(produc.getProducciones().size() > 2) {
          auto p = produc.getProducciones();
          auto last = p[p.size() - 1];
          auto antelast = p[p.size() - 2];
          auto new_prod = {antelast, last};
          newProd.addProduccion(antelast);
          newProd.addProduccion(last);
          produc.getProducciones().pop_back();
          produc.getProducciones().pop_back();
          auto nonTerminal = siguientes.back();
          siguientes.pop_back();
          addProduction(nonTerminal, new_prod);
        }
      }
    }
  }
  std::cout << "producciones: " << producciones_.size() << std::endl;
  */
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
      outputFile << producciones_.size() + FNCproducciones_.size() << std::endl;
      for (Production prod : producciones_) {
        outputFile << prod << std::endl;
      }
      for (Production prod : FNCproducciones_) {
        outputFile << prod << std::endl;
      }
      outputFile.close();
    }
}

/*

for (auto prod : producciones_){
    if (prod.getProducciones().size() >= 2) {
      std::cout << "AQUI" << std::endl;
      for (auto p : prod.getProducciones()) {
        if (alfabeto_.getSymbols().count(p) == 1) {
          bool ok = false;
          for (Production produccion : producciones_)
            if (produccion.getProducciones().size() == 1)
              if (produccion.getProducciones()[0] == p)
                ok = true;
          if (!ok) {
            char last = (*(nonTerminalSymbol_.crbegin()))[0];
            std::cout << "last " << last <<  std::endl;
            char next = last+1;
            std::cout << "next " << next << std::endl;
            addProduction(std::string(1, next), {p});
            nonTerminalSymbol_.insert(std::string(1, next));
            std::cout << "SI" << std::endl;
            prod.setProduccion(i, std::string(1, next));
            std::cout << "NO" << std::endl;
          }
        }
      }
    }
  }
  std::cout << "producciones: " << producciones_.size() << std::endl;
  std::cout << "AQUI2" << std::endl;
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
        }
      }
    }
  }
  std::cout << "producciones: " << producciones_.size() << std::endl;

*/
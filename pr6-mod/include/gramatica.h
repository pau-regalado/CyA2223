#ifndef __GRAMATICA__
#define __GRAMATICA__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include "alphabet.h"
#include "string.h"
#include "state.h"
#include "production.h"

class Gramatica {
  public:
    Gramatica(void);
    ~Gramatica();

    // Getters
    void setAlphabet(Alphabet alphabet);
    void setStart(unsigned start);
    void addProduction(std::string state, std::string terminal, std::string noTerminal);
    void addNonTerminalSymbol(std::string noTerminal);

    void writeOnFile(std::string outputFile);

  private:
    bool ready_;
    std::map<std::string, Production*> producciones_;
    std::set<std::string> nonTerminalSymbol_;
    std::string start_;
    Alphabet alfabeto_;
};

#endif
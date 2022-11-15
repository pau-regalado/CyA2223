#ifndef __AUTOMATA__
#define __AUTOMATA__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include "../include/alphabet.h"
#include "../include/string.h"
#include "../include/state.h"
#include "../include/gramatica.h"

class Automata {
  public:
    Automata(std::string Automata);
    ~Automata();

    // Getters
    bool isReady();

    bool evaluate(std::string string);
    void evaluateFromFile(std::string string);

    std::string run(std::string line);

    Gramatica convertToGrammar(void);

  private:
    bool ready_;
    std::map<unsigned, State*> states_;
    unsigned start_;
    std::set<unsigned> actualStates_;
    Alphabet alfabeto_;
};

#endif
#ifndef __Automata__
#define __Automata__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include "../include/alphabet.h"
#include "../include/string.h"
#include "../include/state.h"

class Automata {
  public:
    Automata(std::string Automata);
    ~Automata();

    // Getters
    bool isReady();

    bool evaluate(std::string string);

    std::string run(std::string line);

  private:
    bool ready_;
    std::map<unsigned, State*> states_;
    unsigned start_;
    std::set<unsigned> actualStates_;
};

#endif
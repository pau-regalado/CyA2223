#ifndef __State__
#define __State__

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#include "string.h"

class State {
  public:
    State(void);
    State(unsigned id, bool aceptacion = false);
    ~State();

    void addTransition(std::string symbol, unsigned estado);
    std::vector<unsigned> getStates(std::string symbol);
    std::vector<unsigned> getTransition(std::string symbol);
    unsigned getID(void);
    bool isAccept(void);
    
    State& operator=(State& a);
    friend std::ostream& operator<<(std::ostream& os, State& a);

  private:
    unsigned id_;
    bool aceptacion_;
    std::map<std::string, std::vector<unsigned>> transiciones_;
};

#endif
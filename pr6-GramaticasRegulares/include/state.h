#ifndef __STATE__
#define __STATE__

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
    // Constructor de estado inicializando el atributo id y aceptación
    State(unsigned id, bool aceptacion = false);
    // Destructor del estado
    ~State();

    void addTransition(std::string symbol, unsigned estado);
    std::vector<unsigned> getStates(std::string symbol);
    std::vector<unsigned> getTransition(std::string symbol);
    std::map<std::string, std::vector<unsigned>> getTransitions(void);
    unsigned getID(void);
    // Comprueba si el estado es de aceptación
    bool isAccept(void);
    
    State& operator=(State& a);
    friend std::ostream& operator<<(std::ostream& os, State& a);

  private:
    unsigned id_;
    bool aceptacion_;
    std::map<std::string, std::vector<unsigned>> transiciones_;
};

#endif
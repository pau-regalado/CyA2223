#ifndef __PRODUCTION__
#define __PRODUCTION__

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#include "string.h"

class Production {
  public:
    Production(void);
    Production(std::string terminal, std::string nonTerminal);
    // Production(std::string start, std::string terminal, std::string nonTerminal);
    ~Production();
    
    void setTerminal(std::string terminal);
    void setNonTerminal(std::string nonTerminal);
    void addProducction(std::string terminal, std::string nonTerminal);

    std::map<std::string, std::string> getProducciones(void);

    friend std::ostream& operator<<(std::ostream& os, Production& p);

  private:
    std::map<std::string, std::string> producciones_;
};

#endif
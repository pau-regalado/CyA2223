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
    Production(std::string noTerminal, std::vector<std::string> prod);
    ~Production();
    
    std::vector<std::string> getProducciones(void) const;
    std::vector<std::string>& getProducciones(void);
    
    std::string getNonTerminal (void) const;

    friend std::ostream& operator<<(std::ostream& os, Production& p);

  private:
    std::string noTerminal_;
    std::vector<std::string> producciones_;
};

#endif
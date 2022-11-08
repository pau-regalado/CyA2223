#ifndef __ALPHABET__
#define __ALPHABET__

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include "string.h"

class Alphabet {
  public:
    Alphabet(void);
    Alphabet(std::vector<std::string> alphabet);
    Alphabet(std::string alphabet);
    ~Alphabet();

    void addSymbol(std::string symbol);

    bool belongsTo(String string);
    std::set<std::string>& getSymbols(void);

    std::string toString(void);

    Alphabet& operator=(Alphabet& a);
    friend std::ostream& operator<<(std::ostream& os, Alphabet& a);

  private:
    std::set<std::string> symbols_;
};

#endif
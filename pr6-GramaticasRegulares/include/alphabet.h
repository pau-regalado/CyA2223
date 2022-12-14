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
    // Obtiene los simbolos de un vector de cadenas y los almacena en
    // un conjunto
    Alphabet(std::vector<std::string> alphabet);
    // Obtiene los simbolos de una cadena y los almacena en
    // un conjunto
    Alphabet(std::string alphabet);
    //Elimina el objeto alfabeto
    ~Alphabet();

    // Añade un simbolo al alfabeto
    void addSymbol(std::string symbol);
    // Comprueba si una cadena esta formada por simbolos del alfabeto
    bool belongsTo(String string);
    // Obtiene los simbolos de un alfabeto
    std::set<std::string>& getSymbols(void);
    // Convierte los datos del alfabeto en una cadena
    std::string toString(void);
    // Asigna un valor a una variable
    Alphabet& operator=(Alphabet& a);
    friend std::ostream& operator<<(std::ostream& os, Alphabet& a);

  private:
    std::set<std::string> symbols_;
};

#endif
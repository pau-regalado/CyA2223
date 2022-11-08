#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#include "../include/automata.h"

int main(int argc, char *argv[]) {
  std::string dfaDesc1 = argv[1];
  std::string dfaDesc2 = argv[2];
  std::string strings = argv[3];

  Automata automata1(dfaDesc1);
  Automata automata2(dfaDesc2);

      // Por cada cadena la analizamos con el Automata
    std::ifstream inputStrings(strings);
    bool iguales = true;
    if (!inputStrings.is_open()) {
      std::cout << "Error. No se puede abrir el fichero: " << strings << std::endl;
    } else {
      std::string line;
      while (std::getline(inputStrings, line)) {
        if (automata1.evaluate(line) != automata2.evaluate(line)) {
          iguales = false;
        }
      }
      inputStrings.close();
    }

    std::cout << ((iguales)?"IGUALES" : "DIFERENTES") << std::endl;

  return 0;
}



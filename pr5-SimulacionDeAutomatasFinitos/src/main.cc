#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#include "../include/automata.h"

int main(int argc, char *argv[]) {
  std::string dfaDesc = argv[1];
  std::string inputStrings = argv[2];

  Automata automata(dfaDesc, inputStrings);
  return 0;
}



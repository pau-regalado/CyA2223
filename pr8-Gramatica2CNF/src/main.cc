#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#include "../include/gramatica.h"

void printUsage() {
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << "Exec: ./dfa2grammar input.dfa output.gra" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
}

int main(int argc, char *argv[]) {

  if (argc != 3) {
    std::cerr << "[ERROR] Wrong number of parameters. Expected 3, got " << argc + 1 << std::endl;
    printUsage();
    return 1;
  } else {
    std::string inputFileName = argv[1];
    std::string outputFile = argv[2];

    Gramatica gramatica;
    gramatica.readOnFile(inputFileName);
    gramatica.convert2CFG();
    gramatica.writeOnFile(outputFile);
  }
  return 0;
}



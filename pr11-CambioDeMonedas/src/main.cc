#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#include "../include/cambioGreedy.h"

void printUsage() {
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << "Exec: ./monedas <n>" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cerr << "[ERROR] Wrong number of parameters. Expected 2, got " << argc + 1 << std::endl;
    printUsage();
    return 1;
  } else {
    std::string cantidad = argv[1];

    CambioDeMonedas* cambio;

    cambio = new CambioDeMonedas(cantidad);
    std::cout << cambio->cambioDeMonedas() << std::endl;
    cambio = new CambioGreedy(cantidad);
    std::cout << cambio->cambioDeMonedas() << std::endl;
  }
  return 0;
}



#include "../include/cambioGreedy.h"

// 
CambioGreedy::CambioGreedy(std::string cantidad): CambioDeMonedas(cantidad) {}



// Vacia el vector
CambioGreedy::~CambioGreedy() { }

// Devuelve la informacion de la clase
std::string CambioGreedy::cambioDeMonedas(void) {
  return "Greedy";
}


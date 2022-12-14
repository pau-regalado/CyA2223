#include "../include/cambioDeMonedas.h"

// 
CambioDeMonedas::CambioDeMonedas(std::string cantidad): cantidad_(cantidad) {}

// Vacia el vector
CambioDeMonedas::~CambioDeMonedas() { }

// Devuelve la informacion de la clase
std::string CambioDeMonedas::cambioDeMonedas(void) {
  return "Normal";
}


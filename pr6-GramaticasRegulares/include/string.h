#ifndef __STRING__
#define __STRING__

#include <iostream>
#include <vector>
#include <string>

class String {
  public:
    // Inicializa el vector de simbolos con el vector de simbolos recibido
    String(std::string self);
    // Inicializa el vector de simbolos con los simbolos de la cadena recibida
    String(std::vector<std::string> self);
    // Vacia el vector
    ~String();

    // Getters
    std::vector<std::string> getSelf(void);
    
  private:
    std::vector<std::string> self_;
};

#endif

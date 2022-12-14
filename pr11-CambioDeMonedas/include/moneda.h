#ifndef __MONEDA__
#define __MONEDA__

#include <iostream>
#include <vector>
#include <string>

class Moneda {
  public:
    Moneda(void);
    Moneda(unsigned valor);
    ~Moneda();

    std::string toString(void);
    Moneda& operator=(Moneda& a);
    friend std::ostream& operator<<(std::ostream& os, Moneda& a);

  private:
    unsigned valor_;
};

#endif
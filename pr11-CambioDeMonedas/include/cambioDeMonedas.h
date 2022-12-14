#ifndef __CAMBIODEMONEDAS__
#define __CAMBIODEMONEDAS__

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class CambioDeMonedas {
  public:
    CambioDeMonedas(void);
    CambioDeMonedas(std::string cantidad);
    ~CambioDeMonedas();

    virtual std::string cambioDeMonedas(void);

    friend std::ostream& operator<<(std::ostream& os, CambioDeMonedas& a);

  private:
    std::string cantidad_;
};

#endif
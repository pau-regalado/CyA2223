#ifndef __CAMBIOGREEDY__
#define __CAMBIOGREEDY__

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "cambioDeMonedas.h"

class CambioGreedy : public CambioDeMonedas{
  public:
    CambioGreedy(void);
    CambioGreedy(std::string cantidad);
    ~CambioGreedy();

    virtual std::string cambioDeMonedas(void);
};

#endif
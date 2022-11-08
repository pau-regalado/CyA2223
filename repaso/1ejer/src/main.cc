#include <iostream>
#include "../include/fraction.h"

int main (int argc, const char* argv[]) {
  int num, den;
  std::cout << "Indique el numerador de la fracción: " << std::endl;
  std::cin >> num;
  std::cout << "Indique el numerador de la fracción: " << std::endl;
  std::cin >> den;
  Fraction f1(num, den);

  std::cout << "Indique el numerador de la fracción: " << std::endl;
  std::cin >> num;
  std::cout << "Indique el numerador de la fracción: " << std::endl;
  std::cin >> den;
  Fraction f2(num, den);

  std::cout << "f1 = " << f1 << std::endl;
  std::cout << "f2 = " << f2 << std::endl;
  std::cout << "f1 + f2= " << f1 + f2 << std::endl;


  
  
}
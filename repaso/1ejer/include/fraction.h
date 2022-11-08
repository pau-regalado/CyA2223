#include <iostream>
class Fraction
{
private:
  float numerador_;
  float denominador_;
  
public:
  Fraction(float numerador);
  Fraction(float numerador, float denominador);
  Fraction(const Fraction& fraccion); //porque no se le puede pasar por valor y solo por referencia
  ~Fraction() = default; 

  float getNum() const;
  float getDen() const;
  void setNum(float numerador);
  void setDen(float denominador);
  
  Fraction add(Fraction f1, Fraction f2);
  Fraction subtract(Fraction f1, Fraction f2);
  Fraction multiply(Fraction f1, Fraction f2);
  Fraction divide(Fraction f1, Fraction f2);

  Fraction operator+(Fraction f);
  Fraction operator-(Fraction f);
  Fraction operator*(Fraction f);
  Fraction operator/(Fraction f);
  bool operator<(Fraction f);
};

std::ostream& operator<<(std::ostream& os, Fraction f);

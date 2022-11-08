#include "../include/fraction.h"
#include <iostream>

Fraction::Fraction(float numerador) {
  numerador_ = numerador;
  denominador_ = 1;
}

Fraction::Fraction(float numerador, float denominador) {
  numerador_ = numerador;
  denominador_ = denominador;
}

Fraction::Fraction(const Fraction& fraccion) {
  numerador_ = fraccion.getNum();
  denominador_ = fraccion.getDen();
}

float Fraction::getNum() const {
  return numerador_;
}

float Fraction::getDen() const {
  return denominador_;
}

void Fraction::setNum(float numerador) {
  numerador_ = numerador;
}

void Fraction::setDen(float denominador) {
  denominador_ = denominador;
}

Fraction Fraction::add(Fraction f1, Fraction f2) {
  Fraction f((f1.getNum() * f2.getDen()) + (f1.getDen() * f2.getNum()), (f1.getDen() * f2.getDen()));
  return f;
}

Fraction Fraction::subtract(Fraction f1, Fraction f2) {
  Fraction f((f1.getNum() * f2.getDen()) - (f1.getDen() * f2.getNum()) , (f1.getDen() * f2.getDen()));
  return f;
}

Fraction Fraction::multiply(Fraction f1, Fraction f2) {
  Fraction f((f1.getNum() * f2.getNum()), (f1.getDen() * f2.getDen()));
  return f;
}

Fraction Fraction::divide(Fraction f1, Fraction f2) {
  
  return ((f1.getNum() * f2.getDen()), (f1.getDen() * f2.getNum()));
}


Fraction Fraction::operator+(Fraction f) {
  return add(*this, f);
}

Fraction Fraction::operator-(Fraction f) {
  return subtract(*this, f);
}

Fraction Fraction::operator*(Fraction f) {
  return multiply(*this, f);
}

Fraction Fraction::operator/(Fraction f) {
  return divide(*this, f);
}

bool Fraction::operator<(Fraction f){
  return ((getNum() / getDen()) < (f.getNum() / f.getDen())); 
}

std::ostream& operator<<(std::ostream& os, Fraction f) {
  os << f.getNum() << "/" << f.getDen();
  return os;
}


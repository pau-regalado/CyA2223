// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : string.cc
// Contiene la implementación de la clase String

#include "../include/string.h"

// Inicializa el vector de simbolos con el vector de simbolos recibido
String::String(std::vector<char> self): _self(self){
 
}

// Inicializa el vector de simbolos con los simbolos de la cadena recibida
String::String(std::string self) {
  for (unsigned i = 0; i < self.size(); i++)
    _self.push_back(self[i]);
}

// Vacia el vector
String::~String(){
  _self.clear();
}

// Devuelve la informacion de la clase
std::vector<char> String::getSelf(void) {
  return _self;
}

// Calcula la longitud de la cadena
std::string String::length() {
  return std::to_string((int)_self.size());
}

// Calcula la cadena inversa
std::string String::reverse(void){
  std::string aux;
  for (int i = _self.size() - 1; i >= 0; i--){
    aux += _self[i];
  }
  return aux;
}

// Calcula la cadena formada por el conjunto de prefijos de la cadena
std::string String::prefix(void){
  std::string aux;
  aux.append("& ");
  for (unsigned i = 0; i < _self.size(); i++) {
    for (unsigned j = 0; j <= i; j++) {
      aux += _self[j];
    }
    aux += ' ';
  }
  return aux;
}

// Calcula la cadena formada por el conjunto de sufijos de la cadena
std::string String::sufix(void){
  std::string aux;
  aux.append("& ");
  for (int i = _self.size() - 1; i >= 0; i--) {
    for (unsigned j = i; j < _self.size(); j++) {
      aux += _self[j];
    }
    aux += ' ';
  }
  return aux;
}

// Calcula la cadena formada por el conjunto de subcadenas de la cadena
std::string String::substrings(void){
  std::string aux;
  for (unsigned i = 0; i < _self.size(); i++) {
    for (unsigned j = i; j < _self.size(); j++) {
      for (unsigned k = i; k <= j; k++) {
        aux += _self[k];
      }
      aux += ' ';
    }
    aux += ' ';
  }
  return aux;
}
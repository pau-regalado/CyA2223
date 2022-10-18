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
String::String(void){}

String::String(std::vector<std::string> self): self_(self){}

// Inicializa el vector de simbolos con los simbolos de la cadena recibida
String::String(std::string self) {
  if(self == "&") {
    self_.push_back("");
  } else {
  for (unsigned i = 0; i < self.size(); i++)
    self_.push_back(std::string(1, self[i]));
  }
}

// Vacia el vector
String::~String(){
  self_.clear();
}

// Devuelve la informacion de la clase
std::vector<std::string>& String::getSelf(void) {
  return self_;
}

std::vector<std::string> String::getSelf(void) const{
  return self_;
}

// Calcula la longitud de la cadena
std::string String::length() {
  return std::string(1, (int)self_.size());
}

// Calcula la cadena inversa
String String::reverse(void) const{
  std::string aux;
  for (int i = self_.size() - 1; i >= 0; i--){
    aux += self_[i];
  }
  return String(aux);
}

// Calcula la cadena formada por el conjunto de prefijos de la cadena
String String::prefix(void){
  std::string aux;
  aux.append("& ");
  for (unsigned i = 0; i < self_.size(); i++) {
    for (unsigned j = 0; j <= i; j++) {
      aux += self_[j];
    }
    aux += ' ';
  }
  return String(aux);
}

// Calcula la cadena formada por el conjunto de sufijos de la cadena
String String::sufix(void){
  std::string aux;
  aux.append("& ");
  for (int i = self_.size() - 1; i >= 0; i--) {
    for (unsigned j = i; j < self_.size(); j++) {
      aux += self_[j];
    }
    aux += ' ';
  }
  return String(aux);
}

// Calcula la cadena formada por el conjunto de subcadenas de la cadena
std::string String::substrings(void){
  std::string aux;
  for (unsigned i = 0; i < self_.size(); i++) {
    for (unsigned j = i; j < self_.size(); j++) {
      for (unsigned k = i; k <= j; k++) {
        aux += self_[k];
      }
      aux += ' ';
    }
    aux += ' ';
  }
  return aux;
}

// Convierte los datos del objeto cadena en una cadena
std::string String::toString(void) {
  std::string aux;
  if (self_.size() == 0) {
    return "&";
  } else {
    for (unsigned i = 0; i < self_.size(); i++) {
      aux += self_[i];
    }
  }
  return aux;
}

// Convierte los datos del objeto cadena en una cadena
std::string String::toString(void) const{
  std::string aux;
  if (self_.size() == 0) {
    return "&";
  } else {
    for (unsigned i = 0; i < self_.size(); i++) {
      aux += self_[i];
    }
  }
  return aux;
}

// El metodo modifica el objeto invocante y a la vez retorna el objeto creado
String String::concatenate(String string) {
  String result(self_);
  for (unsigned i = 0; i < string.getSelf().size(); i++){
    result.getSelf().push_back(string.getSelf()[i]);
  }
  return result;
}

// Para comparar cadenas
bool String::operator==(String& a) {
  if (this->self_.size() != a.getSelf().size())
    return false;
  for(unsigned i = 0; i < this->self_.size(); i++)
    if (self_[i] != a.getSelf()[i])
      return false;
  return true;
}

bool String::operator!=(String& a) {
  return !(*this == a);
}

// Sobrecarga necesaria para poder insertar cadenas en un std::set
bool operator<(const String &left, const String &right) {
  // Aprovechamos que std::vector tiene la sobrecarga implementada
  if (left.getSelf() < right.getSelf()){
    return true;
  }
  return false;
}

String& String::operator=(const String& a) {
  self_ = a.getSelf();
  return *this;
}

std::ostream& operator<<(std::ostream& os, String a)  {
  if (a.getSelf().size() == 0) {
    os << "&";
  } else if (a.getSelf().size() == 1 && a.getSelf()[0] == "") {
    os << "&";
  } else {
    for (unsigned i = 0; i < a.getSelf().size(); i++) {
      os << a.getSelf()[i];
    }
  }
  return os;
}
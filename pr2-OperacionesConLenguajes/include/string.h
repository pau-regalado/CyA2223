// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : string.h
// Contiene la definicion de la clase String

#ifndef __STRING__
#define __STRING__

#include <iostream>
#include <vector>
#include <string>

/**
 * Representa una cadena, una secuencia de simbolos
 * que puede realizar una serie de calculos sobre ella
 */
class String {
  public:
    String(void);
    String(std::string self);
    String(std::vector<std::string> self);
    ~String();

    // Getters
    std::vector<std::string>& getSelf(void);
    std::vector<std::string> getSelf(void) const;

    // Func methods
    std::string length(void);
    String reverse(void) const;
    String prefix(void);
    String sufix(void);
    std::string substrings(void);
    std::string toString(void);
    std::string toString(void) const;

    String concatenate(String string);

    bool operator==(String& a);
    bool operator!=(String& a);
    bool operator<(String& a);
    String& operator=(const String& a);
    friend std::ostream& operator<<(std::ostream& os, String a);
    friend bool operator< (const String &left, const String &right);
  private:
    std::vector<std::string> self_;
};
#endif

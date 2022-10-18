// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : lenguaje.h
// Contiene la definicion de la clase lenguaje

#ifndef __LENGUAGE__
#define __LENGUAGE__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "../include/alphabet.h"
#include "../include/string.h"
/**
 * Clase encargada de la lectura y escritura de ficheros, y el procesado de cada linea 
 */
class Lenguage {
  public:
    Lenguage(void);
    Lenguage(std::set<String> lenguage);
    Lenguage(std::string nombre, std::set<String> lenguage);
    ~Lenguage();

    // Getters
    bool isReady();
    void addString(String string);
    void removeString(String string);
    void setNombre(std::string string);

    std::string getNombre(void);
    std::string getNombre(void) const;

    std::set<String>& getSelf(void);
    std::set<String> getSelf(void) const;
    Alphabet& getAlphabet(void);
    void setAlphabet(Alphabet& alphabet);

    void updateAlphabet(void);

    // Binarias
    Lenguage concatenate(Lenguage& lenguaje2);
    Lenguage lunion(Lenguage& lenguaje2);
    Lenguage interssection(Lenguage& lenguaje);
    Lenguage difference(Lenguage& lenguaje);

    Lenguage operator+(Lenguage& lenguaje2);
    Lenguage operator|(Lenguage& lenguaje2);
    Lenguage operator^(Lenguage& lenguaje);
    Lenguage operator-(Lenguage& lenguaje);
    Lenguage operator*(unsigned power);
    
    Lenguage reverse(void);
    Lenguage power(unsigned power);

    // Unarias
    std::string toString(void);
    std::string toString(void) const;

    Lenguage& operator=(Lenguage a);
    friend std::ostream& operator<<(std::ostream& os, Lenguage a);
    friend bool operator<(const Lenguage &left, const Lenguage &right);

  private:
    std::set<String> self_;
    std::string nombre_;
    Alphabet alphabet_;
};
#endif
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

#ifndef __CALCULATOR__
#define __CALCULATOR__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <cstdlib>
#include "../include/alphabet.h"
#include "../include/string.h"
#include "../include/lenguage.h"

const std::string AUX_PREFFIX = "__aux";

class Calculator {
  public:
    Calculator(void);
    Calculator(std::string name);
    ~Calculator();
    
    std::fstream& openFile(std::string name);
    void runLanguage(Lenguage& lenguaje, std::string line);
    std::string run(std::string line);
    std::vector<std::string> read(std::string line);
    void createAlphabet(Alphabet& alphabet, std::string line);
    void createLanguage(Lenguage& lenguaje, std::string line);
    
    Lenguage getOperandByName(std::string name);
    bool isReady();
    bool isOperand(std::string name);
    bool isOperator(std::string name);
    unsigned nOperan(std::string op);
    //void showOperandos(void);

  private:
    std::set<Lenguage> operandos_;
    std::set<char> operadores_ = {'|', '+', '^', '-', '!', '*'};
    bool ready_;
    char opcode_;
    std::stack<std::string> stack;
    int acc = 0;

};
#endif


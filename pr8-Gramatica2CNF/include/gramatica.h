/**
 * @file gramatica.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __GRAMATICA__
#define __GRAMATICA__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map> 
#include "alphabet.h"
#include "string.h"
#include "production.h"

/**
 * @brief 
 * 
 */
class Gramatica {
  public:
  
  /** @brief Constructor por defecto de la clase Gramatica**/
    Gramatica(void);

    ~Gramatica();
    
    /**
     * @brief Funcion para leer una Gramatica a partir de un fichero
     * 
     * @param inputFileName Nombre del fichero a leer
     */
    void readOnFile(std::string inputFileName);
    // Getters
    void setAlphabet(Alphabet alphabet);
    void setStart(unsigned start);
    void addProduction(std::string noTerminal, std::vector<std::string> prod);
    void addNonTerminalSymbol(std::string noTerminal);
    void convert2CFG();
    bool isEmpty();
   
    void writeOnFile(std::string outputFile);

  private:
    bool empty_ = false;
    std::vector<Production> producciones_;
    std::set<std::string> nonTerminalSymbol_;
    std::string start_;
    Alphabet alfabeto_;
};

#endif
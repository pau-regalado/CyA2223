// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : processor.cc
// Contiene la implementacion de la clase Processor

#include "../include/processor.h"

/**
 * Crea el procesador de ficheros
 * Abre el fichero de entrada, obtiene cada linea, la procesa y la
 * imprime en el fichero de salida
 */

Processor::Processor(std::string dataFile, std::string output, char opcode) {
  std::fstream inputFile(dataFile);
  // Si el fichero de entrada no existe: ERROR
  if (!inputFile.is_open()) {
    std::cout << "[Error]: could not open " << dataFile << std::endl;
    _ready = false;
  } else {
    // Si el fichero entrada esta vacío: ERROR
    if (inputFile.get() == EOF) {
      std::cout << "[Error]: " << dataFile  << " is empty" << std::endl;
      _ready = false;
    } else {
    // Si consigue leer, reinicia a la posición 0 del fichero
      inputFile.seekg(0, inputFile.beg); // Reiniciamos el puntero de lectura al principio para correguir la lectura de arriba
      _ready = true;
    }
  }
  // Abre fichero para escritura, sobreescribiendo el contenido
  std::fstream outputFile(output, std::fstream::trunc | std::fstream::out);
  if (!outputFile.is_open()) {
    std::cout << "[Error]: could not open " << dataFile << std::endl;
    _ready = false;
  }

  _opcode = opcode;

  if (!isReady()) {
    std::cout << "Aborting program" << std::endl;
  } else {
    // Obtiene cada linea del fichero, la procesa y escribe en el fichero de salida
    // su contenido
    std::string line;
    while (std::getline(inputFile, line)) {
      outputFile << run(line) << std::endl;
    }
  }

  outputFile.close();
  inputFile.close();
}

Processor::~Processor() {
}

// Obtiene el estado del procesador, si ha habido algun error
bool Processor::isReady() {
  return _ready;
}

// Procesa una linea leida por el procesador y devuelve el resultado
std::string Processor::run(std::string line) {
  std::vector<std::string> stringVector; 
  unsigned character = 0;
  // Añadimos al vector todas las cadenas leidas separadas por espacio ' '
  while(character <= line.size()) {
    std::string aux;
    while(character <= line.size() && line[character] != ' '){
      aux.push_back(line[character]);
      character++;
    }
    stringVector.push_back(aux);
    character++;
  }

  Alphabet* alfabeto;
  String* string;
  // Si solo tiene una cadena, le pasamos a ambos objetos el último elemento
  if(stringVector.size() == 1) {
    string = new String(stringVector.back().erase(stringVector.back().size() - 1));
    alfabeto = new Alphabet(stringVector.back());
  } else {
    // Si tenemos más de una cadena, creamos la cadena con el ultimo elemento, borramos este ultimo
    // y creamos el alfabeto con el resto de elementos del vector
    string = new String(stringVector.back().erase(stringVector.back().size() - 1));
    stringVector.pop_back();
    alfabeto = new Alphabet(stringVector);
  }
  
  // Si la cadena tiene elementos que no existen en el alfabeto da error
  if (!alfabeto->belongsTo(*string)) {
    return "[Error] La cadena tiene simbolos no reconocidos";
  }

  // Realiza la operacion correspondiente al opcode
  switch (_opcode) {
  case 'l':
    return string->length();
    break;
  case 'r':
    return string->reverse();
    break;
  case 'p':
    return string->prefix();
    break;
  case 's':
    return string->sufix();
    break;
  case 'c':
    return string->substrings();
    break;
  
  default:
    return "[Error] Opcode incorrecto";
    break;
  }
}
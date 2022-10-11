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

// Muestra al usuario como se usa el programa
void Processor::help(void) {
  std::cout << "=================================================================================" << std::endl;
  std::cout << "| Help:                                                                         |" << std::endl;
  std::cout << "| Unarial Op Usage: ./main filein1.txt fileout.txt opcode                       |" << std::endl;
  std::cout << "|                                                  i [reverse]                  |" << std::endl;
  std::cout << "|                                                  p [power]                    |" << std::endl;
  std::cout << "| Biarial Op Usage: ./main filein1.txt filein2.txt fileout.txt opcode           |" << std::endl;
  std::cout << "|                                                              u [union]        |" << std::endl;
  std::cout << "|                                                              d [difference]   |" << std::endl;
  std::cout << "|                                                              c [concatenation]|" << std::endl;
  std::cout << "|                                                              s [interssection]|" << std::endl;
  std::cout << "=================================================================================" << std::endl;
}

/**
 * Crea el procesador de ficheros
 * procesando la linea de comandos
 */

Processor::Processor(int argc, char** params) {
  std::string dataFile1, dataFile2, output;
  if (argc == 4) {
    if (op_binarias.count(params[3][0]) == 1) {
      std::cout << "Error. Bad arguments" << std::endl;
      help();
    } else if (op_unarias.count(params[3][0]) == 1) {
      ready_ = true;
      dataFile1 = params[1];
      output = params[2];
      opcode_ = params[3][0];
      initializer(dataFile1, dataFile2, output);
    } else {
      std::cout << "Error. Bad opcode" << std::endl;
      help();
    }
  } else if (argc == 5) {
      ready_ = true;
      dataFile1 = params[1];
      dataFile2 = params[2];
      output = params[3];
      opcode_ = params[4][0];
      initializer(dataFile1, dataFile2, output);
  }
}

Processor::~Processor() {
}

/**
 * Abre los ficheros de entrada y salida, obtiene cada linea, la procesa y la
 * imprime en el fichero de salida
 */
void Processor::initializer(std::string dataFile1, std::string dataFile2, std::string output) {
  std::fstream inputFile(dataFile1);
  std::fstream secondInputFile;
  // Si el fichero de entrada no existe: ERROR
  if (!inputFile.is_open()) {
    std::cout << "[Error]: could not open " << dataFile1 << std::endl;
    ready_ = false;
  } else {
    // Si el fichero entrada esta vacío: ERROR
    if (inputFile.get() == EOF) {
      std::cout << "[Error]: " << dataFile1  << " is empty" << std::endl;
      ready_ = false;
    } else {
    // Si consigue leer, reinicia a la posición 0 del fichero
      inputFile.seekg(0, inputFile.beg); // Reiniciamos el puntero de lectura al principio para correguir la lectura de arriba
      ready_ = true;
    }
  }
  // Abre fichero para escritura, sobreescribiendo el contenido
  std::fstream outputFile(output, std::fstream::trunc | std::fstream::out);
  if (!outputFile.is_open()) {
    std::cout << "[Error]: could not open " << output << std::endl;
    ready_ = false;
  }

  std::string line1;
  if (op_binarias.count(opcode_) == 1) {
    secondInputFile.open(dataFile2);
    // Si el fichero de entrada no existe: ERROR
    if (!secondInputFile.is_open()) {
      std::cout << "[Error]: could not open " << dataFile2 << std::endl;
      ready_ = false;
    } else {
      // Si el fichero entrada esta vacío: ERROR
      if (secondInputFile.get() == EOF) {
        std::cout << "[Error]: " << dataFile2  << " is empty" << std::endl;
        ready_ = false;
      } else {
      // Si consigue leer, reinicia a la posición 0 del fichero
        secondInputFile.seekg(0, secondInputFile.beg); // Reiniciamos el puntero de lectura al principio para correguir la lectura de arriba
        ready_ = true;
      }
    }
    std::string line2;
    // Comprobamos si los ficheros tienen el mismo numero de lineas
    unsigned nlines1 = 0, nlines2 = 0;
/*
    while (std::getline(inputFile, line1)) { nlines1++; }
    while (std::getline(secondInputFile, line2)) { nlines2++; }

    inputFile.open(dataFile1);
    secondInputFile.open(dataFile2);
*/
    if (nlines1 != nlines2) {
      ready_ = false;
      std::cout  << "Error. Files has not the same number of lines." << std::endl;
      outputFile << "Error. Files has not the same number of lines." << std::endl;
    }

    if (ready_) {
      // Obtiene cada linea del fichero, la procesa y escribe en el fichero de salida
      // su contenido
      // Implicitamente si tienen las mismas lineas solo hara que hacer el while para todas las del f1
      while (std::getline(inputFile, line1) && std::getline(secondInputFile, line2)) {
        outputFile << runBinary(line1, line2) << std::endl;
      }
    }
  } else {
    while (std::getline(inputFile, line1)) {
      outputFile << run(line1) << std::endl;
    }
  }

  outputFile.close();
  inputFile.close();

  if (secondInputFile.is_open()) {
    secondInputFile.close();
  }
}

// Obtiene el estado del procesador, si ha habido algun error
bool Processor::isReady() {
  return ready_;
}

// Procesa una linea leida por el procesador y devuelve el resultado
std::string Processor::run(std::string line) {
  Alphabet alfabeto;
  createAlphabet(alfabeto, line);
  Lenguage lenguaje;
  lenguaje.setAlphabet(alfabeto);
  // Quitamos hasta el primer } y los 4 siguientes => '} { '
  line.erase(0, line.find_first_of('}') + 4);

  createLanguage(lenguaje, line);
  Lenguage result;
  // Realiza la operacion correspondiente al opcode
  switch (opcode_) {
  case 'i':
    result = lenguaje.reverse();
    break;
  case 'p':
    unsigned n;
    std::cout << "Introduzca N: ";
    std::cin >> n;
    result = lenguaje.power(n);
    break;
  default:
    return "[Error] Opcode incorrecto";
    break;
  }
  return result.getAlphabet().toString() + result.toString();
}

// Creara los objetos alfabetos y lenguajes, invocara sus metodos para calcular la operacion
// requerida y devolvera la string procesada
std::string Processor::runBinary(std::string line1, std::string line2) {
  Alphabet alfabeto1, alfabeto2;
  createAlphabet(alfabeto1, line1);
  createAlphabet(alfabeto2, line2);
  Lenguage lenguaje1, lenguaje2;
  lenguaje1.setAlphabet(alfabeto1);
  lenguaje2.setAlphabet(alfabeto2);
  // Quitamos hasta el primer } y los 4 siguientes => '} { '
  line1.erase(0, line1.find_first_of('}') + 4);
  line2.erase(0, line2.find_first_of('}') + 4);

  createLanguage(lenguaje1, line1);
  createLanguage(lenguaje2, line2);

  Lenguage result;
  // Realiza la operacion correspondiente al opcode
  switch (opcode_) {
  case 'c':
    result = lenguaje1.concatenate(lenguaje2);
    break;
  case 'u':
    result = lenguaje1.lunion(lenguaje2);
    break;
  case 's':
    result = lenguaje1.interssection(lenguaje2);
    break;
  case 'd':
    result = lenguaje1.difference(lenguaje2);
    break;
  default:
    return "[Error] Opcode incorrecto";
    break;
  }

  return result.getAlphabet().toString() + result.toString();
}

// Con los datos de la linea de un fichero de entrada crea el objeto alfabeto
void Processor::createAlphabet(Alphabet& alphabet, std::string line){
  for (unsigned i = line.find_first_of('{') + 1; i < line.find_first_of('}') - 1; i++) {
    if (line[i] != ' ') {
      alphabet.addSymbol(std::string(1, line[i]));
    }
  }
}

// Con los datos de la linea restantes despues del alfabeto crea el objeto lenguaje
void Processor::createLanguage(Lenguage& lenguaje, std::string line){
  unsigned character = 0;
  while(character <= line.size() && line[character] != '}') {
    std::string aux;
    while(character <= line.size() && line[character] != ' '){
      aux.push_back(line[character]);
      character++;
    }
    lenguaje.addString(String(aux));
    character++;
  }
}
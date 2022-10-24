// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Símbolos, alfabetos y cadenas
// Autor:Paula Regalado de León
// Correo: alu0101330174@ull.es
// Fecha: 28/09/2022
// Archivo : Calculator.cc
// Contiene la implementacion de la clase Calculator

#include "../include/calculator.h"

Calculator::Calculator(std::string dataFile) {

/** Abre los ficheros de entrada y salida, obtiene cada linea, la procesa y la
 * imprime en el fichero de salida */
  std::fstream inputFile(dataFile);
  // Si el fichero de entrada no existe: ERROR
  if (!inputFile.is_open()) {
    std::cout << "[Error]: could not open " << dataFile << std::endl;
    ready_ = false;
  } else {
    // Si el fichero entrada esta vacío: ERROR
    if (inputFile.get() == EOF) {
      std::cout << "[Error]: " << dataFile  << " is empty" << std::endl;
      ready_ = false;
    } else {
    // Si consigue leer, reinicia a la posición 0 del fichero
      inputFile.seekg(0, inputFile.beg); // Reiniciamos el puntero de lectura al principio para correguir la lectura de arriba
      ready_ = true;
    }
  }
  if (ready_) {
    std::string line;
    while(std::getline(inputFile, line)) {
      if(line.find('=') != std::string::npos) {
        Lenguage lenguaje;
        runLanguage(lenguaje, line);
        operandos_.insert(lenguaje);
      } else { // Lectura operaciones
        std::cout << run(line) << std::endl;
        std::cout << "-------------------------------" << std::endl;
      }
    }
  }
  inputFile.close();

}

Calculator::~Calculator() {}

// Obtiene el estado del procesador, si ha habido algun error
bool Calculator::isReady() {
  return ready_;
}

void Calculator::runLanguage(Lenguage& lenguaje, std::string line){
  std::string aux;
  aux = line.substr(0, line.find_first_of('=') - 1); 
  lenguaje.setNombre(aux);
  line.erase(0, line.find_first_of('{') + 1);
  line.replace(line.find_first_of('}'), 3, " }");
  unsigned pos = 0;
   while(line.find(',') != std::string::npos) {
      pos = line.find(',');
      line = line.replace(pos, 1, "");
    }
  createLanguage(lenguaje, line);
}

// Procesa una linea leida por el procesador y devuelve el resultado
std::string Calculator::run(std::string line) {
  std::cout << "OPERACION = " <<  line << "\n";

  while(!stack.empty()){ stack.pop(); }
  std::vector<std::string> elementos = read(line);
  unsigned element_pos = 0;
  while(element_pos < elementos.size()){
    if(isOperand(elementos[element_pos])){
      stack.push(elementos[element_pos]);
    } else if (isOperator(elementos[element_pos])) {
      if (stack.size() < nOperan(elementos[element_pos])) {
        std::cout << "ERROR. Operandos insuficientes en la expresión" << std::endl;
        std::cout << "Pila: " << stack.size() << std::endl;
        while (!stack.empty()) {
          std::cout << "Elemento en la pila: " << stack.top() << std::endl;
          stack.pop();
        }
      } else {          
        Lenguage lenguaje1, lenguaje2, result;
        std::string newName;
        switch (elementos[element_pos][0]) {
          case '+': {
            lenguaje2 = getOperandByName(stack.top()); stack.pop();
            lenguaje1 = getOperandByName(stack.top()); stack.pop();
            newName = AUX_PREFFIX + std::to_string(acc);
            acc++;
            result = lenguaje1 + lenguaje2;
            result.setNombre(newName);

            operandos_.insert(result);
            std::cout << lenguaje1 << " + " << lenguaje2 << " = " << getOperandByName(newName) << std::endl;
            stack.push(newName); 
            break;
          }
          case '|': {
            lenguaje2 = getOperandByName(stack.top()); stack.pop();
            lenguaje1 = getOperandByName(stack.top()); stack.pop();
            newName = AUX_PREFFIX + std::to_string(acc);
            acc++;
            result = lenguaje1 | lenguaje2;
            result.setNombre(newName);
            operandos_.insert(result);
            std::cout << lenguaje1 << " | " << lenguaje2 << " = " << getOperandByName(newName) << std::endl;
            stack.push(newName);           
            break;
          }
          case '^': {
            lenguaje2 = getOperandByName(stack.top()); stack.pop();
            lenguaje1 = getOperandByName(stack.top()); stack.pop();
            newName = AUX_PREFFIX + std::to_string(acc);
            acc++;
            result = lenguaje1 ^ lenguaje2;
            result.setNombre(newName);
            operandos_.insert(result);
            std::cout << lenguaje1 << " ^ " << lenguaje2 << " = " << getOperandByName(newName) << std::endl;
            stack.push(newName);     
            break;
          }
          case '-': {
            lenguaje2 = getOperandByName(stack.top()); stack.pop();
            lenguaje1 = getOperandByName(stack.top()); stack.pop();
            newName = AUX_PREFFIX + std::to_string(acc);
            acc++;
            result = lenguaje1 - lenguaje2;
            result.setNombre(newName);
            operandos_.insert(result);
            std::cout << lenguaje1 << " - " << lenguaje2 << " = " << getOperandByName(newName) << std::endl;
            stack.push(newName);     
            break;
          }
          case '!': {
            lenguaje1 = getOperandByName(stack.top()); stack.pop(); 
            newName = AUX_PREFFIX + std::to_string(acc); 
            acc++;    
            result = lenguaje1.reverse();
            result.setNombre(newName);
            operandos_.insert(result);
            std::cout << lenguaje1 << " ! " << " = " << getOperandByName(newName) << std::endl;
            stack.push(newName);     
            break;
          }
          case '*': {
            unsigned n = std::atoi(stack.top().c_str()); stack.pop();
            lenguaje1 = getOperandByName(stack.top()); stack.pop();
            newName = AUX_PREFFIX + std::to_string(acc);
            acc++;
            result = lenguaje1 * n;
            result.setNombre(newName);
            operandos_.insert(result);
            std::cout << lenguaje1 << " * " << n << " = " << getOperandByName(newName) << std::endl;
            stack.push(newName);     
            break;
          }
          default: 
            std::cout << "ERROR. Operador desconocido";
        }
      }
    } else {
      stack.push(elementos[element_pos]);
    }
    element_pos++;
  }
  if(stack.size() >= 1) {
    return getOperandByName(stack.top()).toString();
  } else {
    return "ERROR. Expresión incorrecta";
  }
}

std::vector<std::string> Calculator::read(std::string line) {
  unsigned character = 0;
  std::vector<std::string> result;  
  while(character <= line.size()) {
    std::string aux;
    while(character <= line.size() && line[character] != ' '){
      aux.push_back(line[character]);
      character++;
    }
    result.push_back(aux);
    character++;
  }
  return result;
}

// Con los datos de la linea de un fichero de entrada crea el objeto alfabeto
void Calculator::createAlphabet(Alphabet& alphabet, std::string line){
  for (unsigned i = line.find_first_of('{') + 1; i < line.find_first_of('}') - 1; i++) {
    if (line[i] != ' ') {
      alphabet.addSymbol(std::string(1, line[i]));
    }
  }
}

// Con los datos de la linea restantes despues del alfabeto crea el objeto lenguaje
void Calculator:: createLanguage(Lenguage& lenguaje, std::string line){
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


// Retorna si existe un operando registrado con ese hombre
Lenguage Calculator::getOperandByName(std::string name){
  Lenguage never;
  for (auto it = operandos_.begin(); it != operandos_.end(); it++) {
    if (it->getNombre() == name)
      never = *it;
  }
  // No todos los flujos devuelven lo mismo, pero
  // implicitamente sabemos que estara
  return never;
}

// Comprueba si el valor recibido por parámetro es un operador contemplado en la clase
bool Calculator::isOperator(std::string isOperator) {
  if (operadores_.count(isOperator[0]) == 1){
    return true;
  } else {
    return false;
  }
}

// Comprueba si existe un operando registrado con ese hombre
bool Calculator::isOperand(std::string name){
  for (auto it = operandos_.begin(); it != operandos_.end(); it++) {
    if (it->getNombre() == name)
      return true;
  }
  return false;
}

//Devuelve el número de parámetros que tiene la función
unsigned Calculator::nOperan(std::string op) {
  switch (op[0])
  {
  case '+':
    return 2; break;
  case '|':
    return 2; break;
  case '^':
    return 2; break;
  case '-':
    return 2; break;
  case '!':
    return 1; break;
  case '*':
    return 2; break;
  default:
  return 0;
    break;
  }
}

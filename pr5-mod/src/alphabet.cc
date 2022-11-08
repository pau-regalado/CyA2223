#include "../include/alphabet.h"

Alphabet::Alphabet(void) {
}


Alphabet::Alphabet(std::vector<std::string> alphabet) {
  symbols_.insert("&");
  for (unsigned i = 0; i < alphabet.size(); i++) {
    symbols_.insert(std::string(1, alphabet[i][0]));
  }
}


Alphabet::Alphabet(std::string string) {
  symbols_.insert("&");
  for (unsigned i = 0; i < string.size(); i++) {
    if (string[i] != ' ')
      symbols_.insert(std::string(1, string[i]));
  }
}

Alphabet::~Alphabet() {  
}

void Alphabet::addSymbol(std::string symbol) {
  symbols_.insert(symbol);
}

std::set<std::string>& Alphabet::getSymbols(void) {
  return symbols_;
}

bool Alphabet::belongsTo(String string) {
  for (unsigned i = 0; i < string.getSelf().size(); i++) {
    if (symbols_.count(string.getSelf()[i]) == 0)
      return false;
  }
  return true;
}

std::string Alphabet::toString(void) {
  std::string aux = "{ ";
  for (auto i = symbols_.cbegin(); i != symbols_.cend(); i++) {
    aux += (*i) + " ";
  }
  return aux += "}";
}

Alphabet& Alphabet::operator=(Alphabet& a) {
  this->symbols_ = a.getSymbols();
  return *this;
}

std::ostream& operator<<(std::ostream& os, Alphabet& a) {
  os << "Alfabeto: " << a.getSymbols().size() << " { ";
  for (auto i = a.getSymbols().cbegin(); i != a.getSymbols().cend(); i++) {
    os << "'" << *i << "' ";
  }
  os << "}" << std::endl;
  return os;
}
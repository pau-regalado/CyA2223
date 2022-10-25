#include "../include/token.h"

Token::Token(void){}

Token::Token(Token_type tipo, std::string contenido, unsigned line):
  tipo_(tipo), contenido_(contenido), startLine_(line), endLine_(0){
}

Token::Token(Token_type tipo, std::string contenido, unsigned startLine, unsigned endLine):
  tipo_(tipo), contenido_(contenido), startLine_(startLine), endLine_(endLine) {}

Token::~Token(void){}

unsigned Token::startLine() const {
  return startLine_;
}

unsigned Token::endLine() const {
  return endLine_;
}

std::string Token::getContenido() const {
  return contenido_;
}

void Token::setContenido(std::string contenido){
  contenido_ = contenido + contenido_;
}

Token_type Token::tipo() const {
  return tipo_;
}

std::string Token::to_String() const {
  if (endLine_ > 0)
    return "  -----\n[Line " + std::to_string(startLine_) + " - " + std::to_string(endLine_) + "] " + contenido_ + "\n-----";
  return "  [Line " + std::to_string(startLine_) + "] " + contenido_;
}

#ifndef __TOKEN__
#define __TOKEN__

#include <string>

enum Token_type {INT, DOUBLE, WHILE, FOR, COMMENT, MAIN, INCLUDE, IFNDEF};

class Token{

private:
  Token_type tipo_;
  std::string contenido_;
  unsigned startLine_;
  unsigned endLine_;

public:
  Token(void);
  Token(Token_type tipo, std::string contenido, unsigned line);
  Token(Token_type tipo, std::string contenido, unsigned startLine, unsigned endLine);
  ~Token(void);

  unsigned startLine() const;
  unsigned endLine() const;
  std::string getContenido() const;
  void setContenido(std::string contenido);
  Token_type tipo() const;
  std::string to_String() const;
};

#endif
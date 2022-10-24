#ifndef __PROCESSOR__
#define __PROCESSOR__

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <fstream>

#include "./token.h"

  const std::regex varExp ("[[:s:]]*(int|double)[[:s:]]+[[:w:]]+([[:s:]]*=[[:s:]]*[[:d:]]+)*[[:s:]]*;");
  const std::regex forExp ("[[:s:]]*(for)[[:s:]]+[(].*[)][[:s:]]*[{]");
  const std::regex whileExp ("[[:s:]]*(while)[[:s:]]*[(].*[)][[:s:]]*[{]");
  const std::regex lineCommentExp ("//[[:print:]]*");
  // const std::regex commentsExp ("[*][[:s:]]+[[:print:]]");
  const std::regex firstCommentsExp("/[*][[:print:]]*");
  const std::regex lastCommentsExp("[[:print:]]*[*]/");
  const std::regex mainExp ("[[:s:]]*(int)[[:s:]]+main[[:s:]]*[(][[:print:]]*[)][[:s:]]*[{]");

class Processor {
   
  public:
    Processor(std::string dataFile, std::string outFile);
    ~Processor();
    bool isReady();
    void run(std::string line, int& lineNum);
    void printData(void);

    Token processVar(std::string line, std::smatch matches);
    Token processLoop(std::string line, std::smatch matches);
    Token processComment(std::string line, std::smatch matches);

  private:
    bool ready_;
    std::fstream inputFile_;
    std::string outFile_;

    std::vector<Token> vars_;
    std::vector<Token> comments_;
    std::vector<Token> for_;
    std::vector<Token> while_;
    std::vector<Token> main_;
    Token desc_;
    
};

#endif
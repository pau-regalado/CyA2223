#ifndef __PROCESSOR__
#define __PROCESSOR__

#include <iostream>
#include <string>
#include <vector>
#include <regex>

class Processor {

  public:
    Processor(std::string dataFile, std::string outFile);
    bool isReady();
    std::vector<std::string> run(std::string line);

  private:
    bool ready_;
    std::string varExp = "(int|double)\s+([a-zA-Z_][\w_]\s((=\s*\d+(\.\d+)?)|\{\d+(\.\d+)?\})?);\s*\n";
    std::string loopExp = "\s*(for|while)\s+(.;.;.*)";
    std::string commentExp = "\/\[\s\S]?\*\/";
    std::string mainExp = "(void|int)\s+main \((void|int argc. char\*+argv\[\])?\)";
};

#endif
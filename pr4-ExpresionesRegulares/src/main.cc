#include <iostream>
#include <string>

#include "../include/processor.h"

int main(int argc, char** argv) {
  Processor reader(std::string(argv[1]), argv[2]);
  return 0;
}
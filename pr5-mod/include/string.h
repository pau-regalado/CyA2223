#ifndef __STRING__
#define __STRING__

#include <iostream>
#include <vector>
#include <string>

class String {
  public:
    String(std::string self);
    String(std::vector<std::string> self);
    ~String();

    // Getters
    std::vector<std::string> getSelf(void);
    
  private:
    std::vector<std::string> self_;
};

#endif

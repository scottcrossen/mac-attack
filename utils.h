#pragma once

#include <iostream>
#include <sstream>

using namespace std;

namespace utils {
  uint32_t hex_to_int(string);
  uint8_t byte_to_int(string);
  string char_to_hex(char);
  string string_to_hex(string);
  string binary_to_hex(string);
  string int_to_hex(unsigned int num, unsigned int pad);
}

class log {
public:
  log(std::string module, std::string message);
  static bool verbose;
};

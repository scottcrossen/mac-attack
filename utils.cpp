#include "utils.h"

uint32_t utils::hex_to_int(string hex_string) {
  // Just alias the C call
  return strtol(hex_string.c_str(), NULL, 16);
}

string utils::int_to_hex(unsigned int number, unsigned int pad_length = 0) {
  // Build string from stream.
  stringstream converter;
  converter << hex << number;
  string output = converter.str();
  // pad_length if necessary
  for (unsigned int index = output.length(); index < pad_length; index++) output = "0" + output;
  // Return
  return output;
}

string utils::binary_to_hex(string binary) {
  string output;
  // pad_length to be a multiple of a nibble
  while (binary.length() % 4 != 0) binary = "0" + binary;
  for (unsigned int index = binary.length(); index > 0; index-=4) {
    // Process each nibble one at a time
    string chunk;
    // Treat first index differently
    if (index < 4) {
      chunk = binary.substr(0, index);
    } else {
      chunk = binary.substr(index-4, 4);
    }
    // Build return
    output = int_to_hex(byte_to_int(chunk), 1) + output;
  }
  return output;
}

string utils::char_to_hex(char character) {
  // Wrap the int_to_hex function and pad_length with leading zero
  string output = int_to_hex(character);
  if (output.length() < 2) {
    return "0" + output;
  } else {
    return output;
  }
}

string utils::string_to_hex(string input) {
  // Build from stringstream
  stringstream converter;
  // Decompose piece-by-piece
  for (unsigned int index = 0; index < input.length(); index++) {
    converter << char_to_hex(input.c_str()[index]);
  }
  return converter.str();
}

uint8_t utils::byte_to_int(string byte) {
  // alias the base C call
  return stoi(byte, nullptr, 2);
}

log::log(std::string module, std::string message) {
  if (log::verbose) {
    // Only display if verbose is on
    std::cout << "[debug] " << module << ": " << message << std::endl;
  }
}

// Global verbosity variable
bool log::verbose;

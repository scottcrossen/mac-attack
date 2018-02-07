#include "sha1.h"
#include <iostream>
#include <sstream>
#include "utils.h"

#define SHA1_BLOCK_LENGTH 512
#define SHA1_MESSAGE_LENGTH_SIZE 64

using namespace std;

int main(int argc, char ** argv) {

  // Testing variables
  uint64_t key_length = 128;
  string initial_mac = "f4b645e89faaec2ff8e443c595009c16dbdfba4b";
  string initial_message = "No one has completed lab 2 so give them all a 0";
  string to_append = "P. S. Except for Scott, go ahead and give him the full 100 points.";

  // Main routine for program.
  if (argc == 2) {
    if (string(argv[1]) == "-v" || string(argv[1]) == "--verbose") { // Test if verbose is set.
      log::verbose = true;
    } else {
      cout << "Usage: macappend [-v|--verbose]" << endl;
      return 0;
    }
  } else if (argc != 1) {
    cout << "Usage: macappend [-v|--verbose]" << endl;
    return 0;
  }

  // Calculate length of message. Should come out to 376 or so. Then calculate padding length.
  uint64_t initial_message_length = initial_message.length()*8;
  uint64_t initial_pad_length = SHA1_BLOCK_LENGTH - ((key_length + initial_message_length + SHA1_MESSAGE_LENGTH_SIZE) % SHA1_BLOCK_LENGTH);

  // Output debug statement
  stringstream debug_string;
  debug_string << "Initial message padding: " << initial_pad_length;
  log("main", debug_string.str()); debug_string.str("");

  // Print the output of program
  cout << "new message: " << utils::string_to_hex(initial_message);
  stringstream padding;
  padding << "1";
  // Pad with zeros if necessary
  for (unsigned int index = 1; index < initial_pad_length; index++) padding << "0";
  // Print new message
  cout << utils::binary_to_hex(padding.str()) << utils::int_to_hex(initial_message_length + key_length, 64/4) << utils::string_to_hex(to_append) << endl;
  // Compute the new hash. Start by initializing with previous MAC.
  SHA1 hash(initial_mac);
  // Update and calculate the new hash.
  hash.update(to_append);
  // Display the new MAC after padding.
  cout << "new MAC: " << hash.final(key_length + initial_message_length + initial_pad_length + SHA1_MESSAGE_LENGTH_SIZE + to_append.length()*8) << endl;

  return 0;
}

/*
  Design and flow credit to github.com/mcrossen
*/

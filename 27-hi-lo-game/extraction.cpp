#include <iostream>
#include <limits>

// Ignore all input up to and including the next newline character
void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Return true if extraction failed, false otherwise
bool clear_failed_extraction() {
  // Check for failed extraction
  // If the previous extraction failed
  if (!std::cin) { 
    // If the stream was closed
    if (std::cin.eof()) {
      std::exit(0); // Shut down the program now
    }

    // Handle the failure
    std::cin.clear(); // Put it back in 'normal' operation mode
    ignore_line();    // Remove the bad input

    return true;
  }

  return false;
}

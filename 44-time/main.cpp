#include <iostream>
#include <ctime>

int main() {
  // Obtain the total seconds since the midnight, Jan 1, 1970 (UNIX Epoch)
  long total_seconds { std::time(0) };
  long current_second { total_seconds % 60 };
  long total_minutes { total_seconds / 60 };
  long current_minute { total_minutes % 60 };
  long total_hours { total_minutes / 60 };
  long current_hour { total_hours % 24 };

  std::cout << "Current time is " << current_hour << ':' << current_minute << ':' << current_second << " GMT\n";
  return 0;
}

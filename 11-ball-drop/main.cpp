#include <iostream>

namespace Constants {
  // gravitational acceleration on Earth in meters/second^2
  constexpr double g { 9.8 };
}

double get_tower_height() {
  std::cout << "Enter the height of the tower in meters: ";
  double h{};
  std::cin >> h;
  return h;
}

// Calculate the height of a ball dropped from rest
// initial_height is in meters
// time is in seconds
constexpr double height(double initial_height, double time) {
  return initial_height - Constants::g * (time * time) / 2;
}

int main() {
  double y_0 { get_tower_height() }; // Get the starting height

  int t { 0 }; // Store the time in seconds
  double y; // Create a variable to store the current height
  do {
    y = height(y_0, t) ; // Calculate the current height

    // If the ball is above the ground, print the time and height
    // If the height is negative, print the time and that the ball is on the ground
    if (y > 0.0)
      std::cout << "At " << t << " seconds, the ball is at height: " << y << " meters." << '\n';
    else
      std::cout << "At " << t << " seconds, the ball is on the ground." << '\n';
    
    ++t; // Increment the time
  } while (y > 0.0); // Stop looping when the ball hits the ground

  return 0;
}

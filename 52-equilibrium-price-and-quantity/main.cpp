#include <iostream>

struct Coefficients {
  double slope{};
  double intercept{};
};

Coefficients get_coefficients() {
  Coefficients temp{};

  std::cout << "Enter the slope: ";
  std::cin >> temp.slope;
  std::cout << "Enter the vertical intercept: ";
  std::cin >> temp.intercept;

  return temp;
}

double get_equilibrium_price(const Coefficients& supply, const Coefficients& demand) {
  return (supply.slope * demand.intercept - demand.slope * supply.intercept) / (supply.slope - demand.slope);
}

double get_equilibrium_quantity(const Coefficients& supply, const Coefficients& demand) {
  return (demand.intercept - supply.intercept) / (supply.slope - demand.slope);
}

double get_consumer_surplus(const Coefficients& supply, const Coefficients& demand) {
  double eq_price { get_equilibrium_price(supply, demand) };
  double eq_quantity { get_equilibrium_quantity(supply, demand) };
  return 0.5 * (demand.intercept - eq_price) * eq_quantity;
}

double get_producer_surplus(const Coefficients& supply, const Coefficients& demand) {
  double eq_price { get_equilibrium_price(supply, demand) };
  double eq_quantity { get_equilibrium_quantity(supply, demand) };
  return 0.5 * (eq_price - supply.intercept) * eq_quantity;
}

int main() {
  std::cout << "This model assumes that the supply and demand curves are both linear.\n";

  std::cout << '\n';
  std::cout << "For the supply curve...\n";
  Coefficients supply { get_coefficients() };

  std::cout << '\n';
  std::cout << "For the demand curve...\n";
  Coefficients demand { get_coefficients() };

  std::cout << '\n';
  std::cout << "Equilibrium Quantity: " << get_equilibrium_quantity(supply, demand) << '\n';
  std::cout << "Equilibrium Price: " << get_equilibrium_price(supply, demand) << '\n';
  std::cout << "Consumer Surplus: " << get_consumer_surplus(supply, demand) << '\n';
  std::cout << "Producer Surplus: " << get_producer_surplus(supply, demand) << '\n';

  return 0;
}

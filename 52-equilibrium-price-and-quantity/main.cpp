#include <iostream>

struct Coefficients {
  double slope{};
  double intercept{};
};

// Section: Functions to get user input

Coefficients get_coefficients() {
  Coefficients temp{};

  std::cout << "Enter the slope: ";
  std::cin >> temp.slope;
  std::cout << "Enter the vertical intercept: ";
  std::cin >> temp.intercept;

  return temp;
}

Coefficients get_supply_coefficients() {
  std::cout << "For the supply curve...\n";
  return get_coefficients();
}

Coefficients get_demand_coefficients() {
  std::cout << "For the demand curve...\n";
  return get_coefficients();
}

double get_tax() {
  std::cout << "Enter the tax: ";
  double tax{};
  std::cin >> tax;
  return tax;
}

// Section: Functions to calculate important quantities 

double get_equilibrium_quantity(const Coefficients& supply, const Coefficients& demand, double tax=0.0) {
  return (demand.intercept - supply.intercept - tax) / (supply.slope - demand.slope);
}

double get_equilibrium_price(const Coefficients& supply, const Coefficients& demand, double tax=0.0) {
  return (supply.slope * demand.intercept - demand.slope * (supply.intercept + tax)) / (supply.slope - demand.slope);
}

double get_price_producers_receive(const Coefficients& supply, const Coefficients& demand, double tax=0.0) {
  return get_equilibrium_price(supply, demand, tax) - tax;
}

double get_consumer_surplus(const Coefficients& supply, const Coefficients& demand, double tax=0.0) {
  double eq_price { get_equilibrium_price(supply, demand, tax) };
  double eq_quantity { get_equilibrium_quantity(supply, demand, tax) };
  return 0.5 * (demand.intercept - eq_price) * eq_quantity;
}

double get_producer_surplus(const Coefficients& supply, const Coefficients& demand, double tax=0.0) {
  double price_producers_receive { get_price_producers_receive(supply, demand, tax)};
  double eq_quantity { get_equilibrium_quantity(supply, demand, tax) };
  return 0.5 * (price_producers_receive - supply.intercept) * eq_quantity;
}

double get_government_revenue(const Coefficients& supply, const Coefficients& demand, double tax=0.0) {
  return get_equilibrium_quantity(supply, demand, tax) * tax;
}

double get_dead_weight_loss(const Coefficients& supply, const Coefficients& demand, double tax=0.0) {
  double eq_quantity { get_equilibrium_quantity(supply, demand, tax) };
  double eq_quantity_no_tax { get_equilibrium_quantity(supply, demand, 0.0) };
  return 0.5 * tax * (eq_quantity_no_tax - eq_quantity);
}

// Section: main

int main() {
  std::cout << "This model assumes that the supply and demand curves are both linear, and that a constant tax may added on the producers.\n";

  Coefficients supply { get_supply_coefficients() };
  Coefficients demand { get_demand_coefficients() };
  double tax { get_tax() };

  std::cout << '\n';
  std::cout << "Equilibrium Quantity: " << get_equilibrium_quantity(supply, demand, tax) << '\n';
  std::cout << "Equilibrium Price: " << get_equilibrium_price(supply, demand, tax) << '\n';
  std::cout << "Price Producers Receive: " << get_price_producers_receive(supply, demand, tax) << '\n';
  std::cout << "Consumer Surplus: " << get_consumer_surplus(supply, demand, tax) << '\n';
  std::cout << "Producer Surplus: " << get_producer_surplus(supply, demand, tax) << '\n';
  std::cout << "Government Revenue: " << get_government_revenue(supply, demand, tax) << '\n';
  std::cout << "Dead Weight Loss: " << get_dead_weight_loss(supply, demand, tax) << '\n';

  return 0;
}

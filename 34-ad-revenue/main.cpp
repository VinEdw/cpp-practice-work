#include <iostream>

struct Ad_Data {
  int ads_shown {};
  double click_through_rate_percent {};
  double avg_earnings_per_click {};
};

Ad_Data input_ad_data() {
  Ad_Data temp{};

  std::cout << "How many ads were shown: ";
  std::cin >> temp.ads_shown;

  std::cout << "What percentage of ads were clicked on by users: ";
  std::cin >> temp.click_through_rate_percent;

  std::cout << "What was the average earnings per click: ";
  std::cin >> temp.avg_earnings_per_click;

  return temp;
}

constexpr double total_earnings(const Ad_Data& ad_data) {
  return ad_data.ads_shown * ad_data.click_through_rate_percent / 100.0 * ad_data.avg_earnings_per_click;
}

void print_ad_data(const Ad_Data& ad_data) {
  std::cout << "Number of ads shown: " << ad_data.ads_shown << '\n';
  std::cout << "Click through rate: " << ad_data.click_through_rate_percent << "%\n";
  std::cout << "Average earnings per clicked ad: $" << ad_data.avg_earnings_per_click << '\n';
  std::cout << "Total earnings: $" << total_earnings(ad_data) << '\n';
}

int main() {
  Ad_Data data { input_ad_data() };
  std::cout << '\n';
  print_ad_data(data);

  return 0;
}

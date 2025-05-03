#include <iostream>

#include "search_statistic.hpp"

int main() {
  std::vector<double> v = {5, 3, 1, 4, 2};
  std::cout << SearchNStatistics(v, 0) << std::endl;  // 1
  std::cout << SearchNStatistics(v, 2) << std::endl;  // 3
  std::cout << SearchNStatistics(v, 4) << std::endl;  // 5
  return 0;
}

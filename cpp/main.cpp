#include "linreg/linreg.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<double> X = {1, 2, 3, 4, 5, 6, 7};
  std::vector<double> y = {1.5, 3.8, 6.7, 9.0, 11.2, 13.6, 16};

  LinearRegression linreg(X, y);

  auto [b0, b1, y_predicted] = linreg.leastsq();

  std::cout << std::endl;
  std::cout << b0 << std::endl;
  std::cout << b1 << std::endl << std::endl;
  for (size_t i = 0; i < y_predicted.size(); ++i) {
    std::cout << y_predicted[i] << " | " << y[i] << std::endl;
  }
  return 0;
}

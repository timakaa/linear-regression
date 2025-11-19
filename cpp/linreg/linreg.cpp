#include "linreg.h"
#include <cmath>
#include <iostream>

// Private methods

std::vector<double> LinearRegression::xy_product() {
  std::vector<double> xy_product;
  xy_product.reserve(X.size());
  for (size_t i = 0; i < X.size(); i++) {
    xy_product.push_back(X[i] * y[i]);
  }
  return xy_product;
}

std::vector<double> LinearRegression::x_squared() {
  std::vector<double> result;
  result.reserve(X.size());
  for (size_t i = 0; i < X.size(); i++) {
    result.push_back(std::pow(X[i], 2));
  }
  return result;
}

double LinearRegression::x_sum() {
  double result = 0;
  for (double v : X) {
    result += v;
  }
  return result;
}

double LinearRegression::y_sum() {
  double result = 0;
  for (double v : y) {
    result += v;
  }
  return result;
}

double LinearRegression::xy_sum() {
  double result = 0;
  for (double v : xy_product()) {
    result += v;
  }
  return result;
}

double LinearRegression::x_squared_sum() {
  double result = 0;
  for (double v : x_squared()) {
    result += v;
  }
  return result;
}

double LinearRegression::get_b1() {
  double len = static_cast<double>(X.size());
  return (len * xy_sum() - x_sum() * y_sum()) /
         (len * x_squared_sum() - std::pow(x_sum(), 2));
}

double LinearRegression::get_b0() {
  double len = static_cast<double>(X.size());
  return (y_sum() - get_b1() * x_sum()) / len;
}

// Public methods

LinearRegression::LinearRegression(std::vector<double> &x_values,
                                   std::vector<double> &y_values)
    : X(x_values), y(y_values) {

  for (double v : X)
    std::cout << v << " ";
  std::cout << std::endl;

  for (double v : y)
    std::cout << v << " ";
  std::cout << std::endl;
}

std::vector<double> LinearRegression::get_y_predicted() {
  std::vector<double> y_predicted;
  y_predicted.reserve(X.size());

  double b0 = get_b0();
  double b1 = get_b1();

  for (double v : X) {
    y_predicted.push_back(b0 + b1 * v);
  }
  return y_predicted;
}

std::tuple<double, double, std::vector<double>> LinearRegression::leastsq() {
  double b0 = get_b0();
  double b1 = get_b1();
  return std::make_tuple(b0, b1, get_y_predicted());
}

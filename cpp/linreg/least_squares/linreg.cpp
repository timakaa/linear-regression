#include "linreg.h"
#include <cmath>
#include <iostream>

// Private methods

std::vector<double> LeastSquares::xy_product() const {
  std::vector<double> xy_product;
  xy_product.reserve(X.size());
  for (size_t i = 0; i < X.size(); i++) {
    xy_product.push_back(X[i] * y[i]);
  }
  return xy_product;
}

std::vector<double> LeastSquares::x_squared() const {
  std::vector<double> result;
  result.reserve(X.size());
  for (size_t i = 0; i < X.size(); i++) {
    result.push_back(std::pow(X[i], 2));
  }
  return result;
}

double LeastSquares::x_sum() const {
  double result = 0;
  for (double v : X) {
    result += v;
  }
  return result;
}

double LeastSquares::y_sum() const {
  double result = 0;
  for (double v : y) {
    result += v;
  }
  return result;
}

double LeastSquares::xy_sum() const {
  double result = 0;
  for (double v : xy_product()) {
    result += v;
  }
  return result;
}

double LeastSquares::x_squared_sum() const {
  double result = 0;
  for (double v : x_squared()) {
    result += v;
  }
  return result;
}

double LeastSquares::get_b1() const {
  size_t len = X.size();
  return (len * xy_sum() - x_sum() * y_sum()) /
         (len * x_squared_sum() - std::pow(x_sum(), 2));
}

double LeastSquares::get_b0() const {
  size_t len = X.size();
  return (y_sum() - get_b1() * x_sum()) / len;
}

// Public methods

LeastSquares::LeastSquares(const std::vector<double> &X_,
                           const std::vector<double> &y_)
    : LinearRegression(X_, y_) {
  for (double v : X)
    std::cout << v << " ";
  std::cout << std::endl;

  for (double v : y)
    std::cout << v << " ";
  std::cout << std::endl;
}

std::vector<double> LeastSquares::get_y_predicted() const {
  std::vector<double> y_predicted;
  y_predicted.reserve(X.size());

  double b0 = get_b0();
  double b1 = get_b1();

  for (double v : X) {
    y_predicted.push_back(b0 + b1 * v);
  }
  return y_predicted;
}

std::tuple<double, double, std::vector<double>> LeastSquares::predict() const {
  double b0 = get_b0();
  double b1 = get_b1();
  return std::make_tuple(b0, b1, get_y_predicted());
}

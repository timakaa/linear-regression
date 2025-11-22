#include "linreg.h"
#include <cmath>

// Private methods

double LeastSquares::get_b1() const {
  size_t len = X.size();
  return (len * sum_vec(mul_vecs(X, y)) - sum_vec(X) * sum_vec(y)) /
         (len * sum_vec(pow_vec(X, 2)) - std::pow(sum_vec(X), 2));
}

double LeastSquares::get_b0() const {
  size_t len = X.size();
  return (sum_vec(y) - get_b1() * sum_vec(X)) / len;
}

// Public methods

LeastSquares::LeastSquares(const std::vector<double> &X_,
                           const std::vector<double> &y_)
    : LinearRegression(X_, y_) {}

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

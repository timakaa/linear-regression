#include "linreg.h"
#include <vector>

// Private methods

double CorrelationCoefficient::get_b0() const {
  return mean(y) - get_b1() * mean(X);
}

double CorrelationCoefficient::get_b1() const {
  return correlation(X, y) * (std(y) / std(X));
}

// Public methods

CorrelationCoefficient::CorrelationCoefficient(const std::vector<double> &X_,
                                               const std::vector<double> &y_)
    : LinearRegression(X_, y_) {}

std::vector<double> CorrelationCoefficient::get_y_predicted() const {
  std::vector<double> result;
  result.reserve(X.size());

  double b1 = get_b1();
  double b0 = get_b0();

  for (double p : X) {
    result.push_back(b0 + b1 * p);
  }

  return result;
}

std::tuple<double, double, std::vector<double>>
CorrelationCoefficient::predict() const {
  return std::make_tuple(get_b0(), get_b1(), get_y_predicted());
}

#include "linreg.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

// Private methods

double CorrelationCoefficient::sum_vec(const std::vector<double> &vec) const {
  double result;

  for (double v : vec) {
    result += v;
  }

  return result;
}

double CorrelationCoefficient::mean(const std::vector<double> &vec) const {
  return sum_vec(vec) / X.size();
}

double CorrelationCoefficient::std(const std::vector<double> &vec) const {
  double result = 0;
  double m = mean(vec);

  for (double p : vec) {
    result += pow((p - m), 2);
  }

  return sqrt(result / X.size());
}

double CorrelationCoefficient::correlation(const std::vector<double> &X,
                                           const std::vector<double> &y) {
  double result = 0;
  double x_mean = mean(X);
  double y_mean = mean(y);
  double x_std = std(X);
  double y_std = std(y);

  for (size_t i = 0; i < X.size(); ++i) {
    result += ((X[i] - x_mean) / x_std) * ((y[i] - y_mean) / y_std);
  }

  return result;
}

std::vector<double>
CorrelationCoefficient::mul_vecs(const std::vector<double> &vec) const {
  return vec;
}

template <typename... Vectors>
std::vector<double>
CorrelationCoefficient::mul_vecs(const std::vector<double> &first,
                                 const Vectors &...rest) const {
  std::vector<double> result = mul_vecs(rest...);

  if (first.size() != result.size()) {
    throw std::invalid_argument("Vectors must be the same size");
  }

  for (size_t i = 0; i < result.size(); ++i) {
    result[i] *= first[i];
  }

  return result;
}

std::vector<double>
CorrelationCoefficient::pow_vec(const std::vector<double> &vec) const {
  std::vector<double> result;
  result.reserve(X.size());

  for (double v : vec) {
    result.push_back(pow(v, 2));
  }

  return result;
}

// Public methods

CorrelationCoefficient::CorrelationCoefficient(const std::vector<double> &X_,
                                               const std::vector<double> &y_)
    : LinearRegression(X_, y_) {}

std::vector<double> CorrelationCoefficient::get_y_predicted() {
  double corr = correlation(X, y);

  double b1 = corr * (std(y) / std(X));
  double b0 = mean(y) - b1 * mean(X);

  // get_b1, get_b0 implementation;
}

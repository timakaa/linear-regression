// LinearRegression.h
#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <tuple>
#include <vector>

class LinearRegression {
protected:
  std::vector<double> X;
  std::vector<double> y;

public:
  LinearRegression(const std::vector<double> &X_, const std::vector<double> &y_)
      : X(X_), y(y_){};

  virtual std::vector<double> get_y_predicted() const = 0;
  virtual std::tuple<double, double, std::vector<double>> predict() const = 0;
  virtual ~LinearRegression() = default; // virtual destructor
};

#endif // LINEARREGRESSION_H

// LinearRegression.h
#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include "../math_utils/math_utils.h"
#include <tuple>
#include <vector>

class LinearRegression : public MathUtils {
private:
  virtual double get_b0() const = 0;
  virtual double get_b1() const = 0;

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

#ifndef LINREG_H
#define LINREG_H

#include "../main.h"
#include <tuple>
#include <vector>

class LeastSquares : public LinearRegression {
private:
  // Private method declarations
  std::vector<double> xy_product() const;
  std::vector<double> x_squared() const;
  double x_sum() const;
  double y_sum() const;
  double xy_sum() const;
  double x_squared_sum() const;
  double get_b1() const;
  double get_b0() const;

public:
  LeastSquares(const std::vector<double> &X_, const std::vector<double> &y_);

  std::vector<double> get_y_predicted() const override;

  std::tuple<double, double, std::vector<double>> predict() const override;
};

#endif // LINREG_H

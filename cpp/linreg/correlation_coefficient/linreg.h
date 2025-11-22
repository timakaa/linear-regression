#ifndef LINREGCOEF_H
#define LINREGCOEF_H

#include "../main.h"
#include <tuple>
#include <vector>

class CorrelationCoefficient : public LinearRegression {
private:
  // Private method declarations
  double get_b1() const override;
  double get_b0() const override;

public:
  CorrelationCoefficient(const std::vector<double> &X_,
                         const std::vector<double> &y_);

  std::vector<double> get_y_predicted() const override;

  std::tuple<double, double, std::vector<double>> predict() const override;
};

#endif // LINREG_H

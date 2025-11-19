#ifndef LINREG_H
#define LINREG_H

#include <tuple>
#include <vector>

class LinearRegression {
private:
  std::vector<double> X;
  std::vector<double> y;

  // Private method declarations
  std::vector<double> xy_product();
  std::vector<double> x_squared();
  double x_sum();
  double y_sum();
  double xy_sum();
  double x_squared_sum();
  double get_b1();
  double get_b0();

public:
  LinearRegression(std::vector<double> &x_values,
                   std::vector<double> &y_values);

  std::vector<double> get_y_predicted();

  std::tuple<double, double, std::vector<double>> leastsq();
};

#endif // LINREG_H

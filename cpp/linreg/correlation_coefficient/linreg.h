#ifndef LINREGCOEF_H
#define LINREGCOEF_H

#include "../main.h"
#include <tuple>
#include <vector>

class CorrelationCoefficient : public LinearRegression {
private:
  // Private method declarations
  double sum_vec(const std::vector<double> &vec) const;

  double mean(const std::vector<double> &vec) const;

  double std(const std::vector<double> &vec) const;

  double correlation(const std::vector<double> &X,
                     const std::vector<double> &y) const;

  double get_b1() const;
  double get_b0() const;

  std::vector<double> mul_vecs(const std::vector<double> &vec) const;

  template <typename... Vectors>
  std::vector<double> mul_vecs(const std::vector<double> &first,
                               const Vectors &...rest) const;

  std::vector<double> pow_vec(const std::vector<double> &vec) const;

public:
  CorrelationCoefficient(const std::vector<double> &X_,
                         const std::vector<double> &y_);

  std::vector<double> get_y_predicted() const override;

  std::tuple<double, double, std::vector<double>> predict() const override;
};

#endif // LINREG_H

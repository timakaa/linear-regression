#include <iostream>
#include <vector>

class LinearRegression {
private:
  std::vector<double> X;
  std::vector<double> y;

  std::vector<double> xy_product() {
    std::vector<double> xy_product;
    for (int i = 0; i < static_cast<int>(X.size()); i++) {
      xy_product.push_back(X[i] * y[i]);
    }
    return xy_product;
  }

  std::vector<double> x_squared() {
    std::vector<double> result;
    for (int i = 0; i < static_cast<int>(X.size()); i++) {
      result.push_back(pow(X[i], 2));
    }
    return result;
  }

  double x_sum() {
    double result = 0;
    for (int i = 0; i < static_cast<int>(X.size()); i++) {
      result += X[i];
    }
    return result;
  }

  double y_sum() {
    double result = 0;
    for (int i = 0; i < static_cast<int>(X.size()); i++) {
      result += y[i];
    }
    return result;
  }

  double xy_sum() {
    double result = 0;
    std::vector<double> xy_prod = xy_product();
    for (int i = 0; i < static_cast<int>(xy_prod.size()); i++) {
      result += xy_prod[i];
    }
    return result;
  }

  double x_squared_sum() {
    double result = 0;
    std::vector<double> x_sq = x_squared();
    for (int i = 0; i < static_cast<int>(x_sq.size()); i++) {
      result += x_sq[i];
    }
    return result;
  }

  double get_b1() {
    double len = static_cast<int>(X.size());
    double result = (len * xy_sum() - x_sum() * y_sum()) /
                    (len * x_squared_sum() - pow(x_sum(), 2));
    return result;
  }

  double get_b0() {
    double len = static_cast<int>(X.size());
    double result = (y_sum() - get_b1() * x_sum()) / len;
    return result;
  }

public:
  LinearRegression(std::vector<double> x_values, std::vector<double> y_values) {
    this->X = x_values;
    for (int i = 0; i < static_cast<int>(this->X.size()); i++) {
      std::cout << x_values[i] << " ";
    };
    std::cout << std::endl;

    this->y = y_values;
    for (int i = 0; i < static_cast<int>(this->y.size()); i++) {
      std::cout << y_values[i] << " ";
    };
    std::cout << std::endl;
  }

  std::vector<double> get_y_predicted() {
    std::vector<double> y_predicted;
    for (int i = 0; i < static_cast<int>(X.size()); i++) {
      y_predicted.push_back(get_b0() + get_b1() * X[i]);
    }
    return y_predicted;
  }

  std::tuple<double, double, std::vector<double>> leastsq() {
    double b0 = get_b0();
    double b1 = get_b1();

    return std::make_tuple(b0, b1, get_y_predicted());
  }
};

int main() {
  std::vector<double> X = {1, 2, 3, 4, 5, 6, 7};
  std::vector<double> y = {1.5, 3.8, 6.7, 9.0, 11.2, 13.6, 16};

  LinearRegression linreg(X, y);
  auto [b0, b1, y_predicted] = linreg.leastsq();
  std::cout << b0 << std::endl;
  std::cout << b1 << std::endl;

  return 0;
}

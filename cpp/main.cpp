#include "./external/matplotlibcpp.h"
#include "linreg/correlation_coefficient/linreg.h"
#include "linreg/least_squares/linreg.h"
#include <Python.h>
#include <random>
#include <vector>

namespace plt = matplotlibcpp;

int main() {
  // Initialize Python manually
  Py_Initialize();

  // Fix Python path so it sees your .venv packages
  PyRun_SimpleString("import sys");
  //! change path to you actual enviroment
  PyRun_SimpleString(
      "sys.path.insert(0, './.venv/lib/python3.14/site-packages')");

  const int n = 100;

  std::vector<double> X(n);
  std::vector<double> y(n);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dist_x(0.0, 2.0);
  std::normal_distribution<> dist_noise(0.0, 0.5);

  for (int i = 0; i < n; i++) {
    double x = dist_x(gen);
    double noise = dist_noise(gen);
    double yy = 3.0 * x + 5.0 + noise;

    X[i] = x;
    y[i] = yy;
  }

  LeastSquares linreg(X, y);

  auto [b0, b1, y_predicted] = linreg.predict();

  CorrelationCoefficient linregcoef(X, y);

  auto [b0_corr, b1_corr, y_predicted_corr] = linregcoef.predict();

  // Least Squares plot
  plt::title("Least Squares");
  plt::scatter(X, y);
  plt::plot(X, y_predicted, "r");
  plt::show();

  // Correlation Coefficient plot
  plt::title("Correlation Coefficient");
  plt::scatter(X, y);
  plt::plot(X, y_predicted_corr, "r");
  plt::show();

  return 0;
}

#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <cmath>
#include <stdexcept>
#include <vector>

class MathUtils {
protected:
  double sum_vec(const std::vector<double> &vec) const {
    double result = 0;

    for (double v : vec) {
      result += v;
    }

    return result;
  }

  double mean(const std::vector<double> &vec) const {
    return sum_vec(vec) / vec.size();
  }

  double std(const std::vector<double> &vec) const {
    double result = 0;
    double m = mean(vec);

    for (double p : vec) {
      result += pow((p - m), 2);
    }

    return sqrt(result / vec.size());
  }

  std::vector<double> mul_vecs(const std::vector<double> &vec) const {
    return vec;
  }

  template <typename... Vectors>
  std::vector<double> mul_vecs(const std::vector<double> &first,
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

  std::vector<double> pow_vec(const std::vector<double> &vec,
                              double power) const {
    std::vector<double> result;
    result.reserve(vec.size());

    for (double v : vec) {
      result.push_back(pow(v, power));
    }

    return result;
  }

  double correlation(const std::vector<double> &vec1,
                     const std::vector<double> &vec2) const {
    double result = 0;

    if (vec1.size() != vec2.size())
      throw std::invalid_argument("Vectors must be the same size");

    for (size_t i = 0; i < vec1.size(); ++i) {
      result += ((vec1[i] - mean(vec1)) / std(vec1)) *
                ((vec2[i] - mean(vec2)) / std(vec2));
    }

    return result / vec1.size();
  }
};

#endif

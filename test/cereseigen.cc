#include "Eigen/Dense"
#include "ceres/ceres.h"
#include "glog/logging.h"

struct CostFunctor {
  template <typename T>
  bool operator()(const T* const x, T* residual) const {
        return true;
  }
};

int main(int argc, char const* argv[]) {
  std::cout << "Testing ceres with Eigen and template";
  Eigen::Matrix<double, 3, 4> x;
  Eigen::Matrix<CostFunctor, 3, 4> x2;
  return 0;
}

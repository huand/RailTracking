#ifndef RAIL_HPP
#define RAIL_HPP

#include <Eigen/Dense>
#include <iostream>
#include <vector>

struct RailParams {
  double gauge = 1.435;
  double width = 0.065;
};

struct Rail {
  Rail(double length, int n_nodes, RailParams rail_params)
      : n_nodes(n_nodes), rail_params(rail_params) {
    left.resize(Eigen::NoChange, n_nodes);
    right.resize(Eigen::NoChange, n_nodes);
    double seg_length = length / (n_nodes - 1);
    for (size_t i = 0; i < n_nodes; i++) {
      // m(0) = i * seg_length;
      left.col(i)(0) = i * seg_length;
      left.col(i)(1) = (rail_params.gauge + rail_params.width) / 2;
      right.col(i)(0) = i * seg_length;
      right.col(i)(1) = -(rail_params.gauge + rail_params.width) / 2;
    }
  };
  Eigen::Matrix3Xd left;
  Eigen::Matrix3Xd right;
  RailParams rail_params;
  int n_nodes;
};

#endif
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <Eigen/Dense>

struct Focal {
  double fx;
  double fy;
};

struct Resolution {
  int w;
  int h;
};

struct Center {
  double x;
  double y;
};

struct Distortion {
  double k1;
  double k2;
  double p1;
  double p2;
  double k3;
};

struct Camera {
  Focal focal;
  Resolution resolution;
  Center center;
  Distortion distortion;
  Eigen::Vector2d Project(Eigen::Vector3d&);
};

#endif
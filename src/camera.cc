#include "camera.hpp"
#include "Eigen/Dense"

Eigen::Vector2d Camera::Project(Eigen::Vector3d& points) {
  auto xp = -points(1) / points(0);
  auto yp = -points(2) / points(0);
  auto r2 = xp * xp + yp * yp;
  auto r4 = r2 * r2;
  auto r6 = r4 * r2;
  auto radial =
      1 + distortion.k1 * r2 + distortion.k2 * r4 + distortion.k3 * r6;
  auto xy = xp * yp;
  Eigen::Vector2d proj;
  proj[0] =
      xp * radial + 2 * distortion.p1 * xy + distortion.p2 * (r2 + 2 * xp * xp);
  proj[1] =
      yp * radial + 2 * distortion.p2 * xy + distortion.p1 * (r2 + 2 * yp * yp);
  proj[0] = focal.fx * proj[0] + center.x;
  proj[1] = focal.fy * proj[1] + center.y;
  return proj;
}
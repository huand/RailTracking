#include "gtest/gtest.h"
#include "rail.hpp"

namespace my {
namespace project {
namespace {

// // The fixture for testing class Foo.
// class RailTest : public ::testing::Test {
//  protected:
//   // You can remove any or all of the following functions if their bodies
//   would
//   // be empty.

//   RailTest() {
//     // You can do set-up work for each test here.
//   }
//   // Class members declared here can be used by all tests in the test suite
//   // for Foo.
//   Rail rail();
// };

// Tests that the Foo::Bar() method does Abc.
TEST(RailTest, RailInitialization) {
  Eigen::Vector3d v = Eigen::Vector3d::Zero();
  double length = 200;
  int n_nodes = 9;
  double gauge = 2;
  double width = 0.5;
  Rail rail(length, n_nodes, RailParams{gauge, width});
  for (size_t i = 0; i < 9; i++) {
    v(0) = i * 25;
    v(1) = 1.25;
    v(2) = 0;
    ASSERT_EQ(rail.left.col(i), v);
    v(1) = -1.25;
    ASSERT_EQ(rail.right.col(i), v);
  }
}

// TEST(RailTest, InitToZeroN0) {
//   Rail rail(200., 0);
//   EXPECT_EQ(0, 0);
// }

// TEST(RailTest, InitToZeroN1) {
//   Rail rail(200., 1);
//   EXPECT_EQ(0, 0);
// }

// TEST(RailTest, InitToZeroL) {
//   Rail rail(0., 3);
//   EXPECT_EQ(0, 0);
// }

}  // namespace
}  // namespace project
}  // namespace my

// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
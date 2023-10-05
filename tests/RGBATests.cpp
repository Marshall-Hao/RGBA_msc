#include "RGBA.h"
#include <gtest/gtest.h>

TEST(RGBA, construct) {
  RGBA pixel;
  EXPECT_EQ(pixel.r, 0);
  EXPECT_EQ(pixel.g, 0);
  EXPECT_EQ(pixel.b, 0);
  EXPECT_EQ(pixel.a, 255);
}
// SPDX-License-Identifier: CC-BY-NC-4.0
// Author: Toggy Smith (toggysmith@gmail.com)

#include "gtest/gtest.h"

TEST(SUITE, TEST1) { EXPECT_EQ("Same value", "Same value"); }

TEST(SUITE, TEST2) { EXPECT_EQ("Same value", "Different value"); }
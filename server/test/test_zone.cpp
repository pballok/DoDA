#include <gtest/gtest.h>

#include "zone.h"

TEST(Zone, size) {
    Zone z1(10);

    EXPECT_EQ(10, z1.size());
}

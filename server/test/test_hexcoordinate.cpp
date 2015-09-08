#include <gtest/gtest.h>

#include "hexcoordinate.h"

TEST(HexCoordinate, directions) {
    HexCoordinate c1;
    EXPECT_EQ(HexCoordinate( 0, -1), c1 + HexCoordinate::NW);
    EXPECT_EQ(HexCoordinate( 1, -1), c1 + HexCoordinate::NE);
    EXPECT_EQ(HexCoordinate( 1,  0), c1 + HexCoordinate::E);
    EXPECT_EQ(HexCoordinate( 0,  1), c1 + HexCoordinate::SE);
    EXPECT_EQ(HexCoordinate(-1,  1), c1 + HexCoordinate::SW);
    EXPECT_EQ(HexCoordinate(-1,  0), c1 + HexCoordinate::W);

    HexCoordinate c2{-3, -1};
    EXPECT_EQ(HexCoordinate(-3, -2), c2 + HexCoordinate::NW);
    EXPECT_EQ(HexCoordinate(-2, -2), c2 + HexCoordinate::NE);
    EXPECT_EQ(HexCoordinate(-2, -1), c2 + HexCoordinate::E);
    EXPECT_EQ(HexCoordinate(-3,  0), c2 + HexCoordinate::SE);
    EXPECT_EQ(HexCoordinate(-4,  0), c2 + HexCoordinate::SW);
    EXPECT_EQ(HexCoordinate(-4, -1), c2 + HexCoordinate::W);
}

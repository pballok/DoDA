#include <gtest/gtest.h>

#include "zone.h"

TEST(Zone, size) {
    Zone z1(10);
    Zone z2(20);

    EXPECT_EQ(10, z1.size());
    EXPECT_EQ(20, z2.size());
}

TEST(Zone, sector) {
    Zone z(6);

    EXPECT_EQ(Sector::Terrain::Invalid, z.sector({0,0}).terrain());
    EXPECT_EQ(Sector::Terrain::Invalid, z.sector({4,3}).terrain());

    z.sector({4,3}).setTerrain(Sector::Terrain::Grassland);

    EXPECT_EQ(Sector::Terrain::Invalid,   z.sector({0,0}).terrain());
    EXPECT_EQ(Sector::Terrain::Grassland, z.sector({4,3}).terrain());
}

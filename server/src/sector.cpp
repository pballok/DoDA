#include "sector.h"

Sector::Sector()
    : terrain_{Terrain::Invalid} {
}

Sector::Terrain Sector::terrain() const {
    return terrain_;
}

void Sector::setTerrain(Sector::Terrain terrain) {
   terrain_ = terrain;
}

#include "zone.h"

Zone::Zone(unsigned int size) :
    size_{size},
    sectors_{size * size, Sector()} {
}

unsigned int Zone::size() const {
    return size_;
}

#include "zone.h"

Zone::Zone(unsigned int size, const std::string &name) :
    size_{size},
    name_{name},
    sectors_{size * size, Sector()} {
}

unsigned int Zone::size() const {
    return size_;
}

Sector& Zone::sector(const HexCoordinate &c) {
    return sectors_.at(hexToLinear(c));
}

unsigned int Zone::hexToLinear(const HexCoordinate &c) {
    return 0;
}

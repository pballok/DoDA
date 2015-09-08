#include "hexcoordinate.h"

constexpr HexCoordinate HexCoordinate::NW{ 0, -1};
constexpr HexCoordinate HexCoordinate::NE{ 1, -1};
constexpr HexCoordinate HexCoordinate::E { 1,  0};
constexpr HexCoordinate HexCoordinate::SE{ 0,  1};
constexpr HexCoordinate HexCoordinate::SW{-1,  1};
constexpr HexCoordinate HexCoordinate::W {-1,  0};

std::ostream& operator<<(std::ostream& out, const HexCoordinate& c) {
    out << "HexCoordinate(" << c.q << "," << c.r << ")";
    return out;
}

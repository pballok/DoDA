#ifndef HEXCOORDINATE_H
#define HEXCOORDINATE_H

#include <ostream>

struct HexCoordinate {
    int q;
    int r;

    constexpr HexCoordinate() : q{0}, r{0} {}
    constexpr HexCoordinate(int coord_q, int coord_r) : q{coord_q}, r{coord_r} {}
    constexpr HexCoordinate operator+(const HexCoordinate& that) { return {q + that.q, r + that.r}; }
    void operator +=(const HexCoordinate& that) { q += that.q; r += that.r; }
    constexpr bool operator==(const HexCoordinate& that) { return (q == that.q) && (r == that.r); }

    const static HexCoordinate NW;
    const static HexCoordinate NE;
    const static HexCoordinate E;
    const static HexCoordinate SE;
    const static HexCoordinate SW;
    const static HexCoordinate W;
};

std::ostream& operator<<(std::ostream& out, const HexCoordinate& c);

#endif

#ifndef ZONE_H
#define ZONE_H

#include <string>
#include <vector>

#include "hexcoordinate.h"
#include "sector.h"

class Zone {
public:
    explicit Zone(unsigned int size, const std::string& name = "");

    unsigned int size() const;
    std::string  name() const;
    Sector&      sector(const HexCoordinate& c);

private:
    unsigned int size_;
    std::string  name_;
    std::vector<Sector> sectors_;

    unsigned int hexToLinear(const HexCoordinate& c);
};

#endif

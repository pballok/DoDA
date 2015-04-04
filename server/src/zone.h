#ifndef ZONE_H
#define ZONE_H

#include <vector>

#include "sector.h"

class Zone {
public:
    explicit Zone(unsigned int size);

    unsigned int size() const;

private:
    unsigned int size_;
    std::vector<Sector> sectors_;
};

#endif

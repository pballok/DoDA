#ifndef SECTOR_H
#define SECTOR_H

class Sector {
public:
    enum class Terrain {
        Invalid,
        Grassland,
        Forest
    };

    Sector();

    Terrain terrain() const;
    void setTerrain(Terrain terrain);

private:
    Terrain terrain_;
};

#endif

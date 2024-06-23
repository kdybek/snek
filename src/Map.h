#ifndef SNEK_MAP_H
#define SNEK_MAP_H


#include <array>
#include <ostream>

#include "Snek.h"

class Map
{
public:
    Map();

    void update(Direction dir, float& speedup);

    char operator()(unsigned short x, unsigned short y) const;

private:
    std::array<std::array<char, MAP_HEIGHT>, MAP_WIDTH> m_map;
    Snek m_snek;

    void clearSnek();

    void drawSnek();

    void placeNewFruit();

    char& accessSnekPart(const snekPart_t& snekPart);

    char cAccessSnekPart(const snekPart_t& snekPart);

};


#endif // SNEK_MAP_H

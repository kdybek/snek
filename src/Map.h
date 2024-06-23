#ifndef SNEK_MAP_H
#define SNEK_MAP_H


#include <array>
#include <ostream>

#include "snek.h"

#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define BACKGROUND ' '
#define BORDER '#'
#define FRUIT '@'

namespace snek
{

    class Map
    {
    public:
        Map();

        void update(Direction dir);

        inline char operator()(unsigned short x, unsigned short y) const { return m_map[x][y]; }

    private:
        std::array<std::array<char, MAP_HEIGHT>, MAP_WIDTH> m_map;
        Snek m_snek;

        void clearSnek();

        void drawSnek();

        void placeNewFruit();

        char& accessSnekPart(const snekPart_t& snekPart);

        char cAccessSnekPart(const snekPart_t& snekPart);

    };

} // snek


#endif // SNEK_MAP_H

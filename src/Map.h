#ifndef SNEK_MAP_H
#define SNEK_MAP_H


#include <array>
#include <ostream>

#include "Snek.h"

#define MAP_WIDTH 100
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

        friend std::ostream& operator<<(std::ostream& os, const Map& map);

    private:
        std::array<std::array<char, MAP_WIDTH>, MAP_HEIGHT> m_map;
        Snek m_snek;

        void clearSnek();

        void drawSnek();

        char& accessSnekPart(const snekPart_t& snekPart);

        char cAccessSnekPart(const snekPart_t& snekPart);

    }; // Map

} // snek


#endif // SNEK_MAP_H

#include "Map.h"

namespace snek
{

    Map::Map() : m_map(), m_snek(2, 2, Direction::East)
    {
        for (unsigned int i = 0; i < MAP_HEIGHT; i++) {
            for (unsigned int j = 0; j < MAP_WIDTH; j++) {
                if (i == 0 || i == MAP_HEIGHT - 1 || j == 0 || j == MAP_WIDTH - 1) {
                    m_map[i][j] = BORDER;
                }
                else {
                    m_map[i][j] = BACKGROUND;
                }
            }
        }
    }

    void Map::update(Direction dir)
    {
        clearSnek();
        m_snek.move(dir);
        if (cAccessSnekPart(m_snek.getHead()) != FRUIT) { m_snek.shorten(); }
        drawSnek();
    }

    std::ostream& operator<<(std::ostream& os, const Map& map)
    {
        for (const auto& row : map.m_map) {
            for (char c : row) {
                os << c;
            }
            os << '\n';
        }

        return os;
    }

    void Map::clearSnek()
    {
        accessSnekPart(m_snek.getHead()) = BACKGROUND;
        for (const auto& part: m_snek.getTail()) {
            accessSnekPart(part) = BACKGROUND;
        }
    }

    void Map::drawSnek()
    {
        accessSnekPart(m_snek.getHead()) = m_snek.getHead().c;
        for (const auto& part: m_snek.getTail()) {
            accessSnekPart(part) = part.c;
        }
    }

    char& Map::accessSnekPart(const snekPart_t& snekPart)
    {
        return m_map[snekPart.y][snekPart.x];
    }

    char Map::cAccessSnekPart(const snekPart_t& snekPart)
    {
        return m_map[snekPart.y][snekPart.x];
    }

} // snek
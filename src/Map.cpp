#include "Map.h"

namespace snek
{

    Map::Map() : m_map(), m_snek(2, 2, Direction::East)
    {
        for (short i = 0; i < MAP_WIDTH; i++) {
            for (short j = 0; j < MAP_HEIGHT; j++) {
                if (i == 0 || i == MAP_WIDTH - 1 || j == 0 || j == MAP_HEIGHT - 1) {
                    m_map[i][j] = BORDER;
                }
                else {
                    m_map[i][j] = BACKGROUND;
                }
            }
        }

        m_map[4][4] = FRUIT;
        m_map[9][9] = FRUIT;
        m_map[4][10] = FRUIT;
        m_map[20][4] = FRUIT;
        m_map[5][20] = FRUIT;
    }

    bool Map::update(Direction dir)
    {
        clearSnek();
        m_snek.move(dir, 1, MAP_WIDTH - 2, 1, MAP_HEIGHT - 2);
        if (cAccessSnekPart(m_snek.getHead()) != FRUIT) { m_snek.shorten(); }
        if (m_snek.collisionCheck()) { return false; }
        drawSnek();
        return true;
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
        return m_map[snekPart.x][snekPart.y];
    }

    char Map::cAccessSnekPart(const snekPart_t& snekPart)
    {
        return m_map[snekPart.x][snekPart.y];
    }

} // snek
#include "Map.h"

#include <random>

#include "SnekExcept.h"

namespace snek
{

    namespace
    {

        int generateRandomNumber(int max)
        {
            std::random_device rd;
            std::mt19937 gen(rd());

            std::uniform_int_distribution<> dis(0, max);

            return dis(gen);
        }

    } // anonymous

    Map::Map() : m_map(), m_snek(2, 2, Direction::East)
    {
        for (unsigned short i = 0; i < MAP_WIDTH; i++) {
            for (unsigned short j = 0; j < MAP_HEIGHT; j++) {
                if (i == 0 || i == MAP_WIDTH - 1 || j == 0 || j == MAP_HEIGHT - 1) {
                    m_map[i][j] = BORDER;
                }
                else {
                    m_map[i][j] = BACKGROUND;
                }
            }
        }

        placeNewFruit();
    }

    void Map::update(Direction dir)
    {
        clearSnek();

        m_snek.move(dir, 1, MAP_WIDTH - 2, 1, MAP_HEIGHT - 2);

        if (cAccessSnekPart(m_snek.getHead()) != FRUIT) { m_snek.shorten(); }

        if (m_snek.collisionCheck()) { throw SnekDeath("snek is ded"); }

        if (cAccessSnekPart(m_snek.getHead()) == FRUIT) {
            placeNewFruit();
        }

        drawSnek();
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

    void Map::placeNewFruit()
    {
        unsigned int nFreeSquares = (MAP_WIDTH - 2) * (MAP_HEIGHT - 2) - m_snek.length();

        if (nFreeSquares == 0) return; // No fruits can be placed.

        int randomNum = generateRandomNumber(static_cast<int>(nFreeSquares - 1));

        for (unsigned short i = 0; i < MAP_WIDTH; i++) {
            for (unsigned short j = 0; j < MAP_HEIGHT; j++) {
                if (m_map[i][j] == BACKGROUND && randomNum-- == 0) {
                    m_map[i][j] = FRUIT;
                    return;
                }
            }
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
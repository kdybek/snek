#include "Map.h"

#include <random>

#include "SnekExcept.h"

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
    for (unsigned short i = 0; i < g_mapWidth; i++) {
        for (unsigned short j = 0; j < g_mapHeight; j++) {
            if (i == 0 || i == g_mapWidth - 1 || j == 0 || j == g_mapHeight - 1) {
                m_map[i][j] = g_borderChar;
            }
            else {
                m_map[i][j] = g_backgroundChar;
            }
        }
    }

    drawSnek();

    placeNewFruit();
}

void Map::update(Direction dir, float& speedup)
{
    clearSnek();

    m_snek.move(dir, 1, g_mapWidth - 2, 1, g_mapHeight - 2);

    bool fruit = cAccessSnekPart(m_snek.getHead()) == g_fruitChar;

    if (!fruit) { m_snek.shorten(); }

    if (m_snek.collisionCheck()) { throw SnekDeath("snek is ded"); }

    drawSnek();

    if (fruit) {
        speedup *= 1.02f;
        placeNewFruit();
    }
}

char Map::operator()(unsigned short x, unsigned short y) const
{
    return m_map[x][y];
}

void Map::clearSnek()
{
    accessSnekPart(m_snek.getHead()) = g_backgroundChar;

    for (const auto& part: m_snek.getTail()) {
        accessSnekPart(part) = g_backgroundChar;
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
    unsigned int nFreeSquares = (g_mapWidth - 2) * (g_mapHeight - 2) - m_snek.length();

    if (nFreeSquares == 0) { return; } // No fruits can be placed.

    int randomNum = generateRandomNumber(static_cast<int>(nFreeSquares - 1));

    for (unsigned short i = 0; i < g_mapWidth; i++) {
        for (unsigned short j = 0; j < g_mapHeight; j++) {
            if (m_map[i][j] == g_backgroundChar && randomNum-- == 0) {
                m_map[i][j] = g_fruitChar;
                return;
            }
        }
    }

    assert(false);
}

char& Map::accessSnekPart(const snekPart_t& snekPart)
{
    return m_map[snekPart.x][snekPart.y];
}

char Map::cAccessSnekPart(const snekPart_t& snekPart)
{
    return m_map[snekPart.x][snekPart.y];
}

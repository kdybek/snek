#ifndef SNEK_UTILITY_H
#define SNEK_UTILITY_H


#include <cassert>

#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define BACKGROUND ' '
#define BORDER '#'
#define FRUIT '@'
#define SNEK_HEAD 's'

struct snekPart_t
{
    unsigned short x;
    unsigned short y;
    char c;
};

enum class Direction
{
    East,
    West,
    North,
    South
};

inline bool validDirection(char c)
{
    if (c == 'w' || c == 'a' || c == 's' || c == 'd') { return true; }
    else { return false; }
}

inline Direction charToDir(char c)
{
    switch (c) {
        case 'w':
            return Direction::North;
        case 'a':
            return Direction::West;
        case 's':
            return Direction::South;
        case 'd':
            return Direction::East;
        default:
            assert(false);
            return Direction::West;
    }
}

inline char dirToSnekTail(Direction prevDir, Direction newDir)
{
    switch (newDir) {
        case Direction::East:
            if (prevDir == Direction::South) { return '\\'; }
            if (prevDir == Direction::North) { return '/'; }
            return '-';
        case Direction::West:
            if (prevDir == Direction::South) { return '/'; }
            if (prevDir == Direction::North) { return '\\'; }
            return '-';
        case Direction::North:
            if (prevDir == Direction::East) { return '/'; }
            if (prevDir == Direction::West) { return '\\'; }
            return '|';
        case Direction::South:
            if (prevDir == Direction::East) { return '\\'; }
            if (prevDir == Direction::West) { return '/'; }
            return '|';
    }
}


#endif // SNEK_UTILITY_H

#ifndef SNEK_UTILITY_H
#define SNEK_UTILITY_H


#include <cassert>

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

    assert(false);

    // Return something to silence warnings.
    return ' ';
}


#endif // SNEK_UTILITY_H

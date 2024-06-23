#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

#include "Map.h"
#include "WindowsConsoleScreenBuffer.h"
#include "SnekExcept.h"

void renderFrame(snek::Map& map, snek::WindowsConsoleScreenBuffer& buffer, snek::Direction& direction)
{
    if (_kbhit()) {
        char dirChar = static_cast<char>(_getch_nolock());
        if (snek::validDirection(dirChar)) {
            direction = snek::charToDir(dirChar);
        }
    }

    map.update(direction);
    buffer.drawMap(map);
    buffer.activate();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void gameLoop()
{
    snek::Map map;
    snek::Direction direction = snek::Direction::East;

    snek::WindowsConsoleScreenBuffer buf1;
    snek::WindowsConsoleScreenBuffer buf2;

    try {
        while (true) {
            renderFrame(map, buf1, direction);
            renderFrame(map, buf2, direction);
        }
    } catch (const SnekDeath& e) {

    }
}

int main()
{
    gameLoop();

    return 0;
}

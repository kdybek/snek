#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

#include "Map.h"
#include "WindowsConsoleScreenBuffer.h"
#include "SnekExcept.h"

void renderFrame(Map& map, WindowsConsoleScreenBuffer& buffer, Direction& direction)
{
    if (_kbhit()) {
        char dirChar = static_cast<char>(_getch_nolock());
        if (validDirection(dirChar)) {
            direction = charToDir(dirChar);
        }
    }

    map.update(direction);
    buffer.drawMap(map);
    buffer.activate();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void gameLoop()
{
    Map map;
    Direction direction = Direction::East;

    WindowsConsoleScreenBuffer buf1;
    WindowsConsoleScreenBuffer buf2;

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

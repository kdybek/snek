#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

#include "Map.h"
#include "WindowsConsoleScreenBuffer.h"
#include "SnekExcept.h"

void renderFrame(Map& map, WindowsConsoleScreenBuffer& buffer, Direction& direction, float& speedup)
{
    if (_kbhit()) {
        char dirChar = static_cast<char>(_getch_nolock());
        if (validDirection(dirChar)) {
            direction = charToDir(dirChar);
        }
    }

    map.update(direction, speedup);
    buffer.drawMap(map);
    buffer.activate();
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<unsigned short>(std::ceil(120.f / speedup))));
}

void gameLoop()
{
    Map map;
    Direction direction = Direction::East;
    float speedup = 1.f;

    WindowsConsoleScreenBuffer buf1;
    WindowsConsoleScreenBuffer buf2;

    try {
        while (true) {
            renderFrame(map, buf1, direction, speedup);
            renderFrame(map, buf2, direction, speedup);
        }
    } catch (const SnekDeath& e) {

    }
}

int main()
{
    gameLoop();
}

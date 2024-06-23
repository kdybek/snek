#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

#include "Map.h"
#include "WindowsConsoleScreenBuffer.h"



void gameLoop()
{
    snek::Map map;
    snek::Direction direction = snek::Direction::East;

    snek::WindowsConsoleScreenBuffer buf1;
    snek::WindowsConsoleScreenBuffer buf2;

    while (true) {
        if (_kbhit()) {
            char dirChar = static_cast<char>(_getch_nolock());
            if (snek::validDirection(dirChar)) {
                direction = snek::charToDir(dirChar);
            }
        }

        if (!map.update(direction)) return;
        buf1.drawMap(map);
        buf1.activate();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        if (_kbhit()) {
            char dirChar = static_cast<char>(_getch_nolock());
            if (snek::validDirection(dirChar)) {
                direction = snek::charToDir(dirChar);
            }
        }

        if (!map.update(direction)) return;
        buf2.drawMap(map);
        buf2.activate();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    gameLoop();

    return 0;
}

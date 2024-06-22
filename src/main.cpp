#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

#include "Map.h"

void gameLoop()
{
    snek::Map map;
    snek::Direction direction = snek::Direction::East;

    while (true) {
        if (_kbhit()) {
            char dirChar = static_cast<char>(_getch_nolock());
            if (snek::validDirection(dirChar)) {
                direction = snek::charToDir(dirChar);
            }
        }

        map.update(direction);
        system("cls");
        std::cout << map << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main()
{
    gameLoop();

    return 0;
}

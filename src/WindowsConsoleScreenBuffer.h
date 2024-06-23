#ifndef SNEK_WINDOWSCONSOLESCREENBUFFER_H
#define SNEK_WINDOWSCONSOLESCREENBUFFER_H


#include <windows.h>

#include "Map.h"
#include "SnekExcept.h"

class WindowsConsoleScreenBuffer
{
public:
    WindowsConsoleScreenBuffer() : m_handle(CreateConsoleScreenBuffer(
            GENERIC_READ | GENERIC_WRITE,   // Access rights
            0,                              // No sharing
            nullptr,                        // Default security attributes
            CONSOLE_TEXTMODE_BUFFER,        // Text mode buffer
            nullptr                         // Default buffer data
    ))
    {
        if (m_handle == INVALID_HANDLE_VALUE) {
            throw SnekException("error creating screen buffer");
        }
    }

    ~WindowsConsoleScreenBuffer()
    {
        CloseHandle(m_handle);
    }

    WindowsConsoleScreenBuffer(const WindowsConsoleScreenBuffer&) = delete;

    WindowsConsoleScreenBuffer& operator=(const WindowsConsoleScreenBuffer&) = delete;

    void drawMap(const Map& map)
    {
        for (SHORT i = 0; i < MAP_WIDTH; ++i) {
            for (SHORT j = 0; j < MAP_HEIGHT; ++j) {
                CHAR c = map(i, j);
                DWORD charsWritten;
                WriteConsoleOutputCharacter(m_handle, &c, 1, {static_cast<SHORT>(2 * i), j}, &charsWritten);
            }
        }
    }

    void activate() const
    {
        SetConsoleActiveScreenBuffer(m_handle);
    }

private:
    HANDLE m_handle;

};


#endif // SNEK_WINDOWSCONSOLESCREENBUFFER_H

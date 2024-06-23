#ifndef SNEK_SNEK_H
#define SNEK_SNEK_H


#include <list>
#include <algorithm>

#include "Utility.h"

#define HEAD 's'

namespace snek
{

    class Snek
    {
    public:
        Snek(unsigned short x, unsigned short y, Direction startDir)
                : m_head({x, y, HEAD}), m_tail(), m_dir(startDir)
        {
        }

        [[nodiscard]] const snekPart_t& getHead() const
        {
            return m_head;
        }

        [[nodiscard]] const std::list<snekPart_t>& getTail() const
        {
            return m_tail;
        }

        [[nodiscard]] unsigned int length() const
        {
            return m_tail.size() + 1;
        }

        void move(Direction newDir, short minX, short maxX, short minY, short maxY)
        {
            m_tail.push_front({.x=m_head.x, .y=m_head.y, .c=dirToSnekTail(m_dir, newDir)});

            m_dir = newDir;

            switch (newDir) {
                case Direction::East:
                    m_head.x == maxX ? m_head.x = minX : ++m_head.x;
                    break;
                case Direction::West:
                    m_head.x == minX ? m_head.x = maxX : --m_head.x;
                    break;
                case Direction::North:
                    m_head.y == minY ? m_head.y = maxY : --m_head.y;
                    break;
                case Direction::South:
                    m_head.y == maxY ? m_head.y = minY : ++m_head.y;
                    break;
            }
        }

        void shorten()
        {
            assert(!m_tail.empty());

            m_tail.pop_back();
        }

        [[nodiscard]] bool collisionCheck() const
        {
            return std::ranges::any_of(m_tail, [&](const snekPart_t& part)
            {
                return part.x == m_head.x && part.y == m_head.y;
            });
        }

    private:
        snekPart_t m_head;
        std::list<snekPart_t> m_tail;
        Direction m_dir;

    };

} // snek


#endif // SNEK_SNEK_H

#ifndef SNEK_SNEK_H
#define SNEK_SNEK_H


#include <list>

#include "Utility.h"

#define HEAD 'o'

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

        void move(Direction newDir)
        {
            m_tail.push_front({.x=m_head.x,
                               .y=m_head.y,
                               .c=dirToSnekTail(m_dir, newDir)});

            m_dir = newDir;

            switch (newDir) {
                case Direction::East:
                    ++m_head.x;
                    break;
                case Direction::West:
                    --m_head.x;
                    break;
                case Direction::North:
                    --m_head.y;
                    break;
                case Direction::South:
                    ++m_head.y;
                    break;
            }
        }

        void shorten()
        {
            assert(!m_tail.empty());

            m_tail.pop_back();
        }

    private:
        snekPart_t m_head;
        std::list<snekPart_t> m_tail;
        Direction m_dir;

    }; // Snek

} // snek


#endif // SNEK_SNEK_H

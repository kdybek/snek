#ifndef SNEK_SNEK_EXCEPT_H
#define SNEK_SNEK_EXCEPT_H


#include <exception>
#include <string>

class SnekException : public std::exception
{
private:
    std::string m_errorMessage;

public:
    explicit SnekException(std::string message) : m_errorMessage(std::move(message))
    {
    }

    ~SnekException() noexcept override = default;

    [[nodiscard]] const char* what() const noexcept override
    {
        return m_errorMessage.c_str();
    }

};

class SnekDeath : public SnekException
{
public:
    explicit SnekDeath(std::string message) : SnekException(std::move(message))
    {
    }

    ~SnekDeath() noexcept override = default;

};



#endif // SNEK_SNEK_EXCEPT_H

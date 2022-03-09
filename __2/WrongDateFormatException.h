#pragma once
#include <exception>

class WrongDateFormatException : public std::exception
{
public:
    WrongDateFormatException();
};


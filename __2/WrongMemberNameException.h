#pragma once
#include <exception>
#include <string>

class WrongMemberNameException : public std::exception
{
public:
    WrongMemberNameException(const std::string& name);
};


#pragma once
#include <exception>

class DuplicateMatchException : public std::exception
{
public:
	DuplicateMatchException();
};


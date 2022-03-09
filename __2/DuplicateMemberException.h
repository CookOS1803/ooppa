#pragma once
#include <exception>

class DuplicateMemberException : public std::exception
{
public:
	DuplicateMemberException();
};


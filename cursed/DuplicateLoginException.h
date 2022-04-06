#pragma once
#include <exception>

namespace IMEX
{
	class DuplicateLoginException : public std::exception
	{
	public:
		DuplicateLoginException();
	};
}


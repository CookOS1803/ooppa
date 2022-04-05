#pragma once
#include <exception>

namespace IMEX
{
	class WrongLoginException : public std::exception
	{
	public:

		WrongLoginException();
	};
}


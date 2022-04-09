#pragma once
#include <exception>

namespace IMEX
{
	class WrongProductException : public std::exception
	{
	public:

		WrongProductException();
	};
}

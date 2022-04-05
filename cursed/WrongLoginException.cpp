#include "WrongLoginException.h"

using namespace IMEX;

WrongLoginException::WrongLoginException()
	: std::exception("Неправильный логин")
{
}

#include "DuplicateLoginException.h"

using namespace IMEX;

DuplicateLoginException::DuplicateLoginException()
	: std::exception("Этот логин занят")
{
}

#include "DuplicateMatchException.h"

DuplicateMatchException::DuplicateMatchException()
	: std::exception("Такой матч уже есть")
{
}

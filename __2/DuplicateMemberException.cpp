#include "DuplicateMemberException.h"

DuplicateMemberException::DuplicateMemberException()
	: std::exception("Такой спортсмен уже есть")
{
}

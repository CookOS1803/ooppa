#include "WrongDateFormatException.h"

WrongDateFormatException::WrongDateFormatException()
	: std::exception("Неправильный формат даты")
{
}

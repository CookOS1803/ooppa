#include "WrongProductException.h"

using namespace IMEX;

WrongProductException::WrongProductException()
	: std::exception("Такого продукта нет")
{
}

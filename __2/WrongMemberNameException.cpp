#include "WrongMemberNameException.h"

WrongMemberNameException::WrongMemberNameException(const std::string& name)
	: std::exception((std::string("��������� � ������ ") + name + " �����������").data())
{
}

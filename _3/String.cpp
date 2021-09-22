#include "String.h"

String::String()
{
	setCString("", 1);
}

String::String(const char* str, int length)
{
	setCString(str, length);
}

String::String(const String& other)
{
	setCString(other.str, other.length);
}

String::~String()
{
	delete[] str;
}

const char* String::getCString() const
{
	return str;
}

int String::getLength() const
{
	return length;
}

void String::setCString(const char* str, int length)
{
	delete[] this->str;

	this->str = new char[length];
	strcpy_s(this->str, length, str);
	this->length = length;
}


void String::setCString(char* str, int length)
{
	delete[] this->str;

	this->str = new char[length];
	strcpy_s(this->str, length, str);
	this->length = length;
}

bool String::operator!() const
{
	return length == 1;
}

String String::operator()(int begin, int end)
{
	String result;

	if (begin < 0)		    begin = 0;
	if (end < 0)			end = 0;
	if (begin > length - 1) begin = length - 1;
	if (end > length - 1)   end = length - 1;

	int newLength = end - begin;

	if (newLength < 1) result.setCString("", 1);
	else
	{
		newLength++;
		result.setCString("", newLength);

		for (int i = 0; i < newLength; i++)
		{
			result.str[i] = str[begin + i];
		}
	}


	return result;
}

char String::operator[](int i)
{
	return str[i];
}

istream& operator>>(istream& in, String& s)
{
	char temp[256];

	in.getline(temp, sizeof(temp));
	s.setCString(temp, strlen(temp) + 1);

	return in;
}

ostream& operator<<(ostream& out, const String& s)
{
	out << s.str;
	return out;
}

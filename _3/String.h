#pragma once
#include <iostream>

using namespace std;

class String
{
	char* str = nullptr;
	int length;

public:

	String();
	String(const char* str, int length);
	String(const String& other);
	~String();

	const char* getCString() const;
	int			getLength()	 const;

	void setCString(char* str, int length);
	void setCString(const char* str, int length);

	bool operator!() const;
	String operator()(int begin, int end);
	char operator[](int i);
	String operator=(const String& other);


	friend istream& operator>>(istream& in, String& s);
	friend ostream& operator<<(ostream& out, const String& s);
};


#pragma once
#include <string>

using namespace std;

class Day
{
	string name;
	string* schedule;
	int n;

public:

	Day();
	Day(string name, int n);
	Day(string name, string* schedule, int n);
	~Day();

	int			  getAmount()	   const;
	const string& getCourse(int i) const;
	const string& getName()		   const;

	void setSchedule(string* schedule, int n);
	void setCourse(int i, string course);
	void setName(string name);
};
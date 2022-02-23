#pragma once
#include <string>

struct Grade
{
	std::string subject;
	int value;

	Grade();
	Grade(std::string subject, int value);
};


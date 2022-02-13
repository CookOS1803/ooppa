#pragma once
#include <vector>
#include "Student.h"
#include "Transaction.h"

class Speciality
{
	std::vector<Transaction<Student>> students;
};


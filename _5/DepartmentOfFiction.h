#pragma once

#include "Department.h"

class DepartmentOfFiction : public Department
{
public:
	DepartmentOfFiction();
	DepartmentOfFiction(const DepartmentOfFiction& other);
	DepartmentOfFiction(string name, string* directions, int nDir, Book* books, int nBooks);

	virtual string getDepartmentType() const override;
};


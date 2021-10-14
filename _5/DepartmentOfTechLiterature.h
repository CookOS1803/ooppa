#pragma once

#include "Department.h"

class DepartmentOfTechLiterature : public Department
{
public:
	DepartmentOfTechLiterature();
	DepartmentOfTechLiterature(const DepartmentOfTechLiterature& other);
	DepartmentOfTechLiterature(string name, string* directions, int nDir, Book* books, int nBooks);

	virtual string getDepartmentType() const override;
};


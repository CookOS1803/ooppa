#include "DepartmentOfTechLiterature.h"

DepartmentOfTechLiterature::DepartmentOfTechLiterature() : Department()
{
}

DepartmentOfTechLiterature::DepartmentOfTechLiterature(const DepartmentOfTechLiterature& other) : Department(other)
{
}

DepartmentOfTechLiterature::DepartmentOfTechLiterature(string name, string* directions, int nDir, Book* books, int nBooks) :
    Department(name, directions, nDir, books, nBooks)
{
}

string DepartmentOfTechLiterature::getDepartmentType() const
{
    return "Department of tecnical literature";
}

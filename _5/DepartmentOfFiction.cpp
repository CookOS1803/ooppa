#include "DepartmentOfFiction.h"

DepartmentOfFiction::DepartmentOfFiction() : Department()
{
}

DepartmentOfFiction::DepartmentOfFiction(const DepartmentOfFiction& other) : Department(other)
{
}

DepartmentOfFiction::DepartmentOfFiction(string name, string* directions, int nDir, Book* books, int nBooks) :
    Department(name, directions, nDir, books, nBooks)
{
}

string DepartmentOfFiction::getDepartmentType() const
{
    return "Department of fiction";
}

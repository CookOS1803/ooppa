#include "Faculty.h"

Faculty::Faculty() : specialities()
{
}

Faculty::Faculty(const Faculty& other) : specialities(other.specialities)
{
}

void Faculty::AddSpeciality(const Speciality& speciality)
{
	specialities.push_back(speciality);
}

auto Faculty::GetSpecialityCount() const -> int
{
	return specialities.size();
}

auto Faculty::operator[](int i) -> Speciality&
{
	return specialities[i];
}

auto Faculty::operator[](int i) const -> const Speciality&
{
	return specialities[i];
}

auto Faculty::begin() -> std::vector<Speciality>::iterator
{
	return specialities.begin();
}

auto Faculty::begin() const -> std::vector<Speciality>::const_iterator
{
	return specialities.begin();
}

auto Faculty::end() -> std::vector<Speciality>::iterator
{
	return specialities.end();
}

auto Faculty::end() const -> std::vector<Speciality>::const_iterator
{
	return specialities.end();
}

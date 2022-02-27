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

bool Faculty::IsSpeciality(std::string name)
{
	for (const auto& spec : specialities)
	{
		if (spec.GetName() == name)
			return true;
	}

	return false;
}

void Faculty::RemoveSpeciality(std::string name)
{
	for (int i = 0; i < specialities.size(); i++)
	{
		if (specialities[i].GetName() == name)
		{
			specialities.erase(specialities.begin() + i);
			return;
		}
	}
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

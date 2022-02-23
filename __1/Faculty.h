#pragma once
#include <vector>
#include "Speciality.h"

class Faculty
{
	std::vector<Speciality> specialities;

public:

	Faculty();
	Faculty(const Faculty& other);

	void AddSpeciality(const Speciality& speciality);
	auto GetSpecialityCount() const -> int;

	auto operator[](int i) -> Speciality&;
	auto operator[](int i) const -> const Speciality&;

	auto begin() -> std::vector<Speciality>::iterator;
	auto begin() const -> std::vector<Speciality>::const_iterator;
	auto end() -> std::vector<Speciality>::iterator;
	auto end() const -> std::vector<Speciality>::const_iterator;
};


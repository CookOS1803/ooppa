#include "Student.h"

Student::Student() : name(""), group("")
{
}

Student::Student(std::string name, std::string group) : name(name), group(group)
{
}

Student::Student(const Student& other)
	: name(other.name), group(other.group), subjects(other.subjects)
{
}

auto Student::GetName() const -> std::string
{
	return name;
}

auto Student::GetGroup() const -> std::string
{
	return group;
}

auto Student::GetGrades() const -> const std::vector<Grade>&
{
	return subjects;
}

void Student::SetName(std::string name)
{
	this->name = name;
}

void Student::SetGroup(std::string group)
{
	this->group = group;
}

void Student::SetGrade(std::string subject, int grade)
{
	for (auto& sub : subjects)
	{
		if (sub.subject == subject)
			sub.value = grade;
	}
}

void Student::AddSubject(std::string subject)
{
	subjects.emplace_back(subject, -1);
}

bool Student::IsValidSubject(std::string subject)
{
	for (const auto& sub : subjects)
	{
		if (sub.subject == subject)
			return true;
	}

	return false;
}

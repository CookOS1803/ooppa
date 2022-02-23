#include "Speciality.h"

Speciality::Speciality() : name("")
{
}

Speciality::Speciality(std::string name) : name(name)
{
}

Speciality::Speciality(const Speciality& other)
	: name(other.name), coursesStudents(other.coursesStudents), coursesSubjects(other.coursesSubjects)
{
}

void Speciality::AddSubject(std::string name, int course)
{
	coursesSubjects[course - 1].push_back(name);
}

void Speciality::AddStudent(std::string name, std::string group, int course)
{
	Student temp(name, group);

	for (const auto& subject : coursesSubjects[course - 1])
	{
		temp.AddSubject(subject);
	}

	coursesStudents[course - 1].emplace_back(temp);
}

auto Speciality::GetName() const -> std::string
{
	return name;
}

auto Speciality::GetStudents(int course) -> std::vector<Transaction<Student>>& 
{
	return coursesStudents[course - 1];
}

auto Speciality::GetStudents(int course) const -> const std::vector<Transaction<Student>>&
{
	return coursesStudents[course - 1];
}

auto Speciality::GetCourses(int course) const -> const std::vector<std::string>&
{
	return coursesSubjects[course - 1];
}

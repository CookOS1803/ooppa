#pragma once
#include <vector>
#include <array>
#include "Student.h"
#include "Transaction.h"

class Speciality
{
public:

	static const int COURSES_COUNT = 4;

private:

	std::string name;
	std::array<std::vector<Transaction<Student>>, COURSES_COUNT> coursesStudents;
	std::array<std::vector<std::string>, COURSES_COUNT> coursesSubjects;

public:

	Speciality();
	Speciality(std::string name);
	Speciality(const Speciality& other);

	void AddSubject(std::string name, int course);
	void AddStudent(std::string name, std::string group, int course);

	void RemoveSubject(std::string name, int course);

	auto GetName() const -> std::string;
	auto GetStudents(int course) -> std::vector<Transaction<Student>>&;
	auto GetStudents(int course) const -> const std::vector<Transaction<Student>>&;
	auto GetCourses(int course) const -> const std::vector<std::string>&;
};


#pragma once
#include <vector>
#include <string>
#include "Grade.h"

class Student
{
	std::string name;
	std::string group;
	std::vector<Grade> subjects;

public:

	Student();
	Student(std::string name, std::string group);
	Student(const Student& other);

	auto GetName() const -> std::string;
	auto GetGroup() const -> std::string;
	auto GetGrades() const -> const std::vector<Grade>&;

	void SetName(std::string name);
	void SetGroup(std::string group);
	void SetGrade(std::string subject, int grade);
	
	void AddSubject(std::string subject);
	bool IsValidSubject(std::string subject);
};


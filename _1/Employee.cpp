#include <iostream>
#include "Employee.h"

Employee::Employee()
{
    setName("");
    setExperience(0);
    setHourSalary(0);
    setHours(0);
}

Employee::Employee(char name[64], int experience, int hourSalary, int hours)
{
    setName(name);
    setExperience(experience);
    setHourSalary(hourSalary);
    setHours(hours);
}

const char* Employee::getName() const
{
    return name;
}

int Employee::getExperience() const
{
    return experience;
}

int Employee::getHourSalary() const
{
    return hourSalary;
}

int Employee::getHours() const
{
    return hours;
}

int Employee::getProfit() const
{
    return hourSalary*hours;
}

float Employee::getBonus() const
{
    float bonus;

    if      (experience < 1) bonus = getProfit()*0.f;
    else if (experience < 3) bonus = getProfit()*0.05f;
    else if (experience < 5) bonus = getProfit()*0.08f;
    else                     bonus = getProfit()*0.15f;    

    return bonus;
}

void Employee::setName(const char* name)
{
    strcpy(this->name, name);
}

void Employee::setExperience(int experience)
{
    this->experience = experience;
}

void Employee::setHourSalary(int hourSalary)
{
    this->hourSalary = hourSalary;
}

void Employee::setHours(int hours)
{
    this->hours = hours;
}

#include <string>
#include "Employee.h"

Employee::Employee()
{
    setName("");
    setExperience(0);
    setSalary(0);
    setHours(0);
}

Employee::Employee(string name, int experience, int salary, int hours)
{
    setName(name);
    setExperience(experience);
    setSalary(salary);
    setHours(hours);
}

string Employee::getName() const
{
    return name;
}

int Employee::getExperience() const
{
    return experience;
}

int Employee::getSalary() const
{
    return salary;
}

int Employee::getHours() const
{
    return hours;
}

int Employee::getProfit() const
{
    return salary*hours;
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

void Employee::setName(string name)
{
    this->name = name;
}

void Employee::setExperience(int experience)
{
    this->experience = experience;
}

void Employee::setSalary(int salary)
{
    this->salary = salary;
}

void Employee::setHours(int hours)
{
    this->hours = hours;
}

istream& operator>>(istream& in, Employee& e)
{
    getline(in, e.name, '\n');
    in >> e.experience >> e.salary >> e.hours;
    
    return in;
}

ostream& operator<<(ostream& out, const Employee& e)
{
    out << e.name << endl << e.experience << endl << e.salary << endl << e.hours << endl;

    return out;
}
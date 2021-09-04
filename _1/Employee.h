#pragma once
#include <iostream>

using namespace std;

class Employee
{
    char name[64];
    int experience;
    int salary;
    int hours;

public:

    Employee();
    Employee(string name, int experience, int salary, int hours);

    string getName()       const;
    int    getExperience() const;
    int    getSalary()     const;
    int    getHours()      const;
    int    getProfit()     const;
    float  getBonus()      const;

    void setName(string name);
    void setExperience(int experience);
    void setSalary(int salary);
    void setHours(int hours);
};
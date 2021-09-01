#pragma once

class Employee
{
    char name[64];
    int experience;
    int hourSalary;
    int hours;

public:

    Employee();
    Employee(char name[64], int experience, int hourSalary, int hours);

    const char* getName()       const;
    int         getExperience() const;
    int         getHourSalary() const;
    int         getHours()      const;
    int         getProfit()     const;
    float       getBonus()      const;

    void setName(const char* name);
    void setExperience(int experience);
    void setHourSalary(int salary);
    void setHours(int hours);
};
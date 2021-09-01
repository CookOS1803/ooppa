#include <iostream>

using namespace std;

class Employee
{
    char name[64];
    int experience;
    int hourSalary;
    int hours;

public:
    
    const char* getName()       const;
    int         getExperience() const;
    int         getHourSalary() const;
    int         getHours()      const;
    int         getProfit()     const;
    float       getBonus()      const;

    void setName(char name[64]);
    void setExperience(int experience);
    void setHourSalary(int salary);
    void setHours(int hours);
};

int main()
{
    int choice;
    bool exit = false;
    Employee e;

    while (!exit)
    {
        cout << "1. Enter info\n2. Show info\n3. Save to file\n4. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:

            break;
            case 2:

            break;
            case 3:

            break;
            case 4: exit = true;
        }
    }

    return 0;
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

void Employee::setName(char name[64])
{
    strcpy(this->name, name);
}

void Employee::setExperience(int experience)
{
    this->experience = experience;
}

void Employee::setHourSalary(int salary)
{
    this->hourSalary = hourSalary;
}

void Employee::setHours(int hours)
{
    this->hours = hours;
}

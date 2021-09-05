#include <string>
#include <fstream>
#include "Employee.h"

void show_info(const Employee* e);

int main()
{
    const char* FILE_NAME = "employee.txt";

    int choice;
    bool exit = false;
    Employee* e = nullptr;
    ofstream o;
    ifstream i;

    while (!exit)
    {
        cout << "1. Enter info\n2. Show info\n3. Save to file\n4. Read from file\n5. Exit\n";
        cin >> choice;
        getc(stdin);

        switch (choice)
        {
            case 1:
            {
                string name;
                int experience, salary, hours;

                cout << "Enter name: ";
                getline(cin, name);

                cout << "Enter years of experience: ";
                cin >> experience;

                cout << "Enter hourly salary: ";
                cin >> salary;

                cout << "Enter hours of work: ";
                cin >> hours;

                delete e;
                e = new Employee(name, experience, salary, hours);

                cout << endl;
            }
            break;
            case 2:
                if (!e) cout << "Enter info first\n";
                else show_info(e);
            break;
            case 3:
                if (!e) cout << "Enter info first\n";
                else
                {
                    o.open(FILE_NAME);
                    o << *e;
                    o.close();
                }
            break;
            case 4:
                i.open(FILE_NAME);

                if (!i.is_open()) cout << "File doesn't exist\n";
                else
                {
                    delete e;
                    e = new Employee;

                    i >> *e;
                    i.close();
                }
            break;
            case 5:
                delete e;
                exit = true;
        }
    }

    return 0;
}

void show_info(const Employee* e)
{
    cout << "Name: " << e->getName() << endl
         << "Experience: " << e->getExperience() << " years" << endl
         << "Hourly salary: " << e->getSalary() << endl
         << "Hours of work: " << e->getHours() << endl
         << "Profit: " << e->getProfit() << endl
         << "Bonus: " << e->getBonus() << endl << endl;
}
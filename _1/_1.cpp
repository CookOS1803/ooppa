#include <string>
#include <fstream>
#include "Employee.h"

void show_info(const Employee* e);

int main()
{
    int choice;
    bool exit = false;
    Employee* e = nullptr;
    ofstream f;
    ifstream i;

    while (!exit)
    {
        cout << "1. Enter info\n2. Show info\n3. Save to file\n4. Exit\n";
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

                if (e) delete e;
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
                    f.open("da.txt", ios::app);
                    f.write((char*)e, sizeof(Employee));
                    f.close();
                }
            break;
            case 4:
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
         << "Bonus :" << e->getBonus() << endl << endl;
}
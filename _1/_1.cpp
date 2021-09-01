#include <iostream>
#include "Employee.h"

using namespace std;

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

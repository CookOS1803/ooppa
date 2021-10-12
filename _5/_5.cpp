#include <iostream>

using namespace std;

bool check_input(bool fail_flag);

int main()
{
    int choice;
    bool exit = false;

    while (!exit)
    {
        do cout << "1. Show info\n2. Edit info\n3. Set path\n4. Show fastest\n5. Show cheapest\n6. Exit\n";
        while (!check_input(!(cin >> choice)));
        getc(stdin);

        switch (choice)
        {
            case 1:
                
            break;
            case 2:
                
            break;
            case 3:
                
            break;
            case 4:
                
            break;
            case 5:
                
            break;
            case 6: exit = true;
        }
    }

    return 0;
}

bool check_input(bool fail_flag)
{
    if (fail_flag)
    {
        cin.clear();
        while (cin.get() != '\n');

        return false;
    }
    else return true;
}
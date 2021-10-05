#include <iostream>

using namespace std;

bool check_input(bool fail_flag);

int main()
{
    int choice;
    bool exit = false;

    while (!exit)
    {
        do cout << "1. Show string\n2. Enter string\n3. Set substring\n4. Get symbol\n5. Exit\n";
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
            case 5: exit = true;
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
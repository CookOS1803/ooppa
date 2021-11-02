#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

bool check_input(bool fail_flag);

int main()
{
    LinkedList<int> intList;
    LinkedList<double> doubleList;
    bool exit = false;
    int choice, n, elementI;
    double elementD;
    ofstream o;

    while (!exit)
    {
        do cout << "1. Add elements\n2. Delete elements\n3. Show\n4. Save to file\n5. Compare sizes\n6. Exit\n";
        while (!check_input(!(cin >> choice)));

        switch (choice)
        {
            case 1:
                do cout << "Choose list:\n1. Integer\n2. Double\n";
                while (!check_input(!(cin >> choice)));

                do cout << "Enter number of elements: ";
                while (!check_input(!(cin >> n)));
                
                cout << "Enter " << n << " elements: ";

                switch (choice)
                {
                    case 1:
                        for (int i = 0; i < n and check_input(!(cin >> elementI)); i++)
                            intList.pushBack(elementI);
                    break;
                    case 2:
                        for (int i = 0; i < n and check_input(!(cin >> elementD)); i++)
                            doubleList.pushBack(elementD);
                }                
            break;
            case 2:
                do cout << "Choose list:\n1. Integer\n2. Double\n";
                while (!check_input(!(cin >> choice)));

                do cout << "Enter number of elements: ";
                while (!check_input(!(cin >> n)));

                switch (choice)
                {
                    case 1:
                        for (int i = 0; i < n; i++)
                            intList.popBack();
                    break;
                    case 2:
                        for (int i = 0; i < n; i++)
                            doubleList.popBack();
                }
                
            break;
            case 3:
                cout << "Integer list: " << intList << endl
                     << "Double list:  " << doubleList << endl
                     << endl;
            break;
            case 4:

                o.open("info.txt", ios::out);
                o << "Integer list: " << intList << endl
                  << "Double list:  " << doubleList << endl
                  << endl;
                o.close();
            break;
            case 5:
                cout << "Sizes of lists are " << (intList == doubleList ? "" : "not ") << "equal\n\n";
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
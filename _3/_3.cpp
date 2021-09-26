#include <iostream>
#include "String.h"

using namespace std;

bool check_input(bool fail_flag);

int main()
{
    String s, subs;
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
                if (!s) cout << "String is empty\n";
                else    cout << s << endl;

                if (!subs) cout  << "Substring is empty\n";
                else       cout << subs << endl;
            break;
            case 2: cin >> s; break;
            case 3:
                int begin, end;
                do cout << "Enter begin and end for substring: ";
                while
                (
                    !check_input(!(cin >> begin >> end)) or
                    begin < 1 or
                    end > s.getLength() or
                    end < begin
                );
                begin--, end--;

                subs = s(begin, end);
            break;
            case 4:
                int i;
                do cout << "Enter position in the string: ";
                while (!check_input(!(cin >> i)) or i < 1 or i > s.getLength());
                i--;

                cout << s[i] << endl;
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
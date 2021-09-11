#include <iostream>
#include <iomanip>
#include "Day.h"

ostream& table(ostream& stream);
void show_info(const Day& day);
void show_info(const Day* day, int n, int courses);

int main()
{
    setlocale(LC_ALL, "rus");
    int courses = 6, n = 7;
    Day* week = new Day[n]
    {
        {"Monday", new string[courses] {"РИК", "Матем", "ФизК", "КС"}, courses},
        {"Tuesday", courses},
        {"Wednesday", new string[courses] {"", "МСиСвИфнТ", "ООП", "ФизК", "ООП"}, courses},
        {"Thursday", new string[courses] {"", "", "", "Эк", "БЖЧ", "БЖЧ"}, courses},
        {"Friday", new string[courses] {"ДВ", "ДВ", "БЖЧ", "РИК"}, courses},
        {"Saturday", new string[courses] {"Эк", "Матем", "Эк"}, courses},
        {"Sunday", courses}
    };
    bool exit = false;
    
    while (!exit)
    {
        int choice;

        cout << "1. Show schedule for a day\n2. Show schedule for the week\n3. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter number of day (1 - 7): ";
                cin >> choice;

                show_info(week[choice - 1]);
            break;
            case 2:
                show_info(week, n, courses);
            break;
            case 3:
                exit = true;
        }
    }


    delete[] week;
    return 0;
}

ostream& table(ostream& stream)
{
    stream << setw(15);
    return stream;
}

void show_info(const Day& day)
{
    cout << "   " << day.getName() << endl;
    
    for (int i = 0; i < day.getAmount(); i++)
        cout << i + 1 << ") " << day.getCourse(i) << endl;

    cout << endl;
}

void show_info(const Day* day, int n, int courses)
{
    cout << left << "   ";
    for (int i = 0; i < n; i++)
        cout << table << day[i].getName() + ":";
    cout << endl;

    for (int i = 0; i < courses; i++)
    {
        cout << i + 1 << ") ";
        for (int j = 0; j < n; j++)
            cout << table << day[j].getCourse(i);
        cout << endl;
    }

    cout << endl << right;
}
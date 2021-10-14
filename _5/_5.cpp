#include <iostream>
#include <fstream>
#include "Book.h"
#include "DepartmentOfFiction.h"
#include "DepartmentOfTechLiterature.h"
#include "Subscriber.h"

using namespace std;

bool check_input(bool fail_flag);
void show_sub(const Subscriber& sub, ostream& out);
void add_sub(Subscriber sub, Subscriber*& subs, int& n);
void show_department(const Department* d);
void show_book(const Book& b);
void show_books(const Subscriber& s);
Subscriber* findSub(string name, Subscriber* subs, int n);

int main()
{
    int choice, currentTime = 20, nSub = 3;
    bool exit = false;
    ofstream o;

    DepartmentOfFiction fic
    (
        "Ficlib",
        nullptr,
        0,
        new Book[1]
        {
            {"Crime and Punishment", "Dostoevskiy", "aa"}
        },
        1
    );
    DepartmentOfTechLiterature tech
    (
        "Techlib",
        nullptr,
        0,
        new Book[2]
        {
            {"OOp metoda", "neznau", "aa"},
            {"ks metoda", "neznau", "aa"}
        },
        2
    );

    Subscriber* subs = new Subscriber[nSub]
    {
        {
            "Kirill",
            "FITU",
            4,
            new info[1]
            {
                {fic.getBooks(), 10}
            },
            1
        },
        {
            "Ilya",
            "FITU",
            4,
            new info[1]
            {
                {tech.getBooks(), 25}
            },
            1
        },
        {
            "Pashgen",
            "FITU",
            1,
            new info[1]
            {
                {tech.getBooks() + 1, 25}
            },
            1
        }
    };
    
    while (!exit)
    {
        do cout << "1. Show subscribers\n2. Add subscriber\n3. Show departments\n4. Subscribe\n5. Show subscriber's books\n6. Find debtors\n7. Save debtors to file\n8. Exit\n";
        while (!check_input(!(cin >> choice)));
        getc(stdin);

        switch (choice)
        {
            case 1:
                for (int i = 0; i < nSub; i++)
                {
                    show_sub(subs[i], cout);
                }
            break;
            case 2:
            {
                string name, fac;
                int group;

                cout << "Enter name: ";
                getline(cin, name);

                cout << "Enter faculty: ";
                getline(cin, fac);

                do cout << "Enter group: ";
                while (!check_input(!(cin >> group)));

                add_sub(Subscriber(name, fac, group, nullptr, 0), subs, nSub);
            }
            break;
            case 3:
                show_department(&fic);
                show_department(&tech);
            break;
            case 4:
            {
                string name;

                cout << "Enter name of subscriber: ";
                getline(cin, name);

                Subscriber* s = findSub(name, subs, nSub);

                if (s == nullptr) cout << "There's no such subscriber\n";
                else
                {
                    int i, deadline;

                    do
                    {
                        cout << "Choose department:\n";
                        cout << "1. " << fic.getDepartmentType() << " \"" << fic.getName() << "\":\n";
                        cout << "2. " << tech.getDepartmentType() << " \"" << tech.getName() << "\":\n";
                    }
                    while (!check_input(!(cin >> choice)));

                    do cout << "Enter book number: ";
                    while (!check_input(!(cin >> i)) or i < 1);
                    i--;

                    do cout << "Enter deadline: ";
                    while (!check_input(!(cin >> deadline)));

                    switch (choice)
                    {
                        case 1:
                            fic.giveBook(*s, i, deadline);
                        break;
                        case 2:
                            tech.giveBook(*s, i, deadline);
                    }
                }
            }
            break;
            case 5:
            {
                string name;

                cout << "Enter name of subscriber: ";
                getline(cin, name);

                Subscriber* s = findSub(name, subs, nSub);

                if (s == nullptr) cout << "There's no such subscriber\n";
                else show_books(*s);
            }
            break;
            case 6:
                for (int i = 0; i < nSub; i++)
                {
                    for (int j = 0; j < subs[i].getBookCount(); j++)
                    {
                        if (subs[i].getBooks()[j].deadline > currentTime)
                        {
                            show_sub(subs[i], cout);
                            break;
                        }
                    }
                }
            break;
            case 7:
                o.open("debtors.txt", ios::out);

                for (int i = 0; i < nSub; i++)
                {
                    for (int j = 0; j < subs[i].getBookCount(); j++)
                    {
                        if (subs[i].getBooks()[j].deadline > currentTime)
                        {
                            show_sub(subs[i], o);
                            break;
                        }
                    }
                }

                o.close();
            break;
            case 8: exit = true;
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

void show_sub(const Subscriber& sub, ostream& out)
{
    out << "Name: " << sub.getName() << endl
        << "Faculty: " << sub.getFaculty() << endl
        << "Group: " << sub.getGroup() << endl << endl;
}

void add_sub(Subscriber sub, Subscriber*& subs, int& n)
{
    Subscriber* temp = new Subscriber[n + 1];

    for (int i = 0; i < n; i++)
        temp[i] = subs[i];
    temp[n] = sub;

    delete[] subs;
    subs = temp;
    n++;
}

void show_department(const Department* d)
{
    cout << "Books of " << d->getDepartmentType() << " \"" << d->getName() << "\":\n";

    for (int i = 0; i < d->getBookCount(); i++)
        show_book(d->getBooks()[i]);
}

void show_book(const Book& b)
{
    cout << "Name: " << b.getName() << endl
         << "Author: " << b.getAuthor() << endl
         << "Publisher: " << b.getPublisher() << endl << endl;
}

Subscriber* findSub(string name, Subscriber* subs, int n)
{
    for (int i = 0; i < n; i++)
        if (subs[i].getName() == name) return subs + i;

    return nullptr;
}

void show_books(const Subscriber& s)
{
    for (int i = 0; i < s.getBookCount(); i++)
    {
        show_book(*s.getBooks()[i].book);
        cout << "Deadline: " << s.getBooks()[i].deadline << endl << endl;
    }
    cout << endl;
}
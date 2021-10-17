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
void remove_sub(const Subscriber* sub, Subscriber*& subs, int& n);
void show_department(const Department& d);
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
            nullptr,
            0
        },
        {
            "Ilya",
            "FITU",
            4,
            nullptr,
            0
        },
        {
            "Pashgen",
            "FITU",
            1,
            nullptr,
            0
        }
    };
    
    fic.giveBook(subs[0], 0, 10);
    tech.giveBook(subs[1], 0, 25);
    tech.giveBook(subs[2], 1, 25);

    while (!exit)
    {
        do cout << "1. Show subscribers\n2. Show departments\n3. Show subscriber's books\n4. Find debtors\n5. Save debtors to file\n6. Edit info\n7. Exit\n";
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
                show_department(fic);
                show_department(tech);
            break;
            case 3:
            {
                string name;

                cout << "Enter name of subscriber: ";
                getline(cin, name);

                Subscriber* s = findSub(name, subs, nSub);

                if (s == nullptr) cout << "There's no such subscriber\n";
                else show_books(*s);
            }
            break;
            case 4:
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
            case 5:
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
            case 6:
            {
                do cout << "1. Edit subscriber\n2. Add subscriber\n3. Remove subscriber";
                while (!check_input(!(cin >> choice)));
                getc(stdin);

                switch (choice)
                {
                    case 1:
                    {
                        string name;

                        cout << "Enter name of subscriber: ";
                        getline(cin, name);

                        Subscriber* s = findSub(name, subs, nSub);

                        if (s == nullptr) cout << "There's no such subscriber\n";
                        else
                        {
                            show_sub(*s, cout);
                            cout << "Books:\n";
                            show_books(*s);

                            do cout << "1. Edit name\n2. Edit faculty\n3. Edit group\n4. Add book\n5. Remove book\n6. Change deadline\n";
                            while (!check_input(!(cin >> choice)));
                            getc(stdin);

                            switch (choice)
                            {
                                case 1:
                                    cout << "Enter new name: ";
                                    getline(cin, name);

                                    s->setName(name);
                                break;
                                case 2:
                                    cout << "Enter new faculty: ";
                                    getline(cin, name);

                                    s->setFaculty(name);
                                break;
                                case 3:
                                    do cout << "Enter new group: ";
                                    while (!check_input(!(cin >> choice)));

                                    s->setGroup(choice);
                                break;
                                case 4:
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
                                break;
                                case 5:
                                    do cout << "Enter book number: ";
                                    while (!check_input(!(cin >> choice)) or choice < 1);
                                    choice--;

                                    s->removeBook(choice);
                                break;
                                case 6:
                                {
                                    int deadline;

                                    do cout << "Enter book number: ";
                                    while (!check_input(!(cin >> choice)) or choice < 1);
                                    choice--;

                                    do cout << "Enter new deadline: ";
                                    while (!check_input(!(cin >> deadline)));

                                    s->getBooks()[choice].deadline = deadline;
                                }                                
                            }
                        }
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
                    {
                        string name;

                        cout << "Enter name of subscriber: ";
                        getline(cin, name);

                        Subscriber* s = findSub(name, subs, nSub);

                        if (s == nullptr) cout << "There's no such subscriber\n";
                        else remove_sub(s, subs, nSub);
                    }
                }
            }
            break;
            case 7: exit = true;
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

void remove_sub(const Subscriber* sub, Subscriber*& subs, int& n)
{
    Subscriber* temp = new Subscriber[n - 1];

    for (int i = 0, a = 0; i - a < n; i++)
        if (subs[i].getName() == sub->getName())
        {
            a = 1;
            n--;
        }
        else temp[i - a] = subs[i];

    delete[] subs;
    subs = temp;
}

void show_department(const Department& d)
{
    cout << "Books of " << d.getDepartmentType() << " \"" << d.getName() << "\":\n";

    for (int i = 0; i < d.getBookCount(); i++)
        show_book(d.getBooks()[i]);
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
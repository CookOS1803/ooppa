#include <iostream>
#include "Vehicle.h"
#include "Train.h"
#include "Airplane.h"

using namespace std;

bool check_input(bool fail_flag);
void show_info(const Transport& t);
void set_info(Transport& t);

int main()
{
    int choice, path = 0, totalPriceV, totalPriceT, totalPriceA;
    float timeV, timeT, timeA;
    bool exit = false;

    Vehicle v(100.f, 100);
    Train t(120.f, 150);
    Airplane a(700.f, 300);

    while (!exit)
    {
        do cout << "1. Show info\n2. Edit info\n3. Set path\n4. Show fastest\n5. Show cheapest\n6. Exit\n";
        while (!check_input(!(cin >> choice)));
        getc(stdin);

        switch (choice)
        {
            case 1:
                cout << "Vehicle:\n";
                show_info(v);

                cout << "Train:\n";
                show_info(t);

                cout << "Airplane:\n";
                show_info(a);

                cout << "Path: " << path << endl << endl;
            break;
            case 2:
                do cout << "1. Vehicle\n2. Train\n3. Airplane\n";
                while (!check_input(!(cin >> choice)) or choice < 1 or choice > 3);

                switch (choice)
                {
                    case 1: set_info(v); break;
                    case 2: set_info(t); break;
                    case 3: set_info(a); break;
                }

            break;
            case 3:
                do cout << "Enter path: ";
                while (!check_input(!(cin >> path)));
                cout << endl;

                v.calculateRoute(path, timeV, totalPriceV);
                t.calculateRoute(path, timeT, totalPriceT);
                a.calculateRoute(path, timeA, totalPriceA);
            break;
            case 4:
                if      (timeV <= timeT and timeV <= timeA)
                    cout << "Vehicle";
                else if (timeT <= timeV and timeT <= timeA)
                    cout << "Train";
                else
                    cout << "Airplane";
                cout << " is fastest\n\n";
            break;
            case 5:
                if      (totalPriceV <= totalPriceT and totalPriceV <= totalPriceA)
                    cout << "Vehicle";
                else if (totalPriceT <= totalPriceV and totalPriceT <= totalPriceA)
                    cout << "Train";
                else
                    cout << "Airplane";
                cout << " is cheapest\n\n";
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

void show_info(const Transport& t)
{
    cout << "Speed: " << t.getSpeed() << endl
         << "Price: " << t.getPrice() << endl
         << endl;
}

void set_info(Transport& t)
{
    float speed;
    int price;

    do cout << "Enter speed: ";
    while (!check_input(!(cin >> speed)));

    do cout << "Enter price: ";
    while (!check_input(!(cin >> price)));

    t.setSpeed(speed);
    t.setPrice(price);

    cout << endl;
}
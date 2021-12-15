#include <iostream>
#include <fstream>
#include "Sphere.h"

using namespace std;

bool check_input(bool fail_flag);

int main()
{
	Point point;
	Ellipse ellipse;
	Ellipsoid ellipsoid;
	Sphere sphere;
	int choice;
	bool exit = false;
	ofstream o;

	while (!exit)
	{
		do cout << "1. Show info\n2. Edit info\n3. Save to file\n4. Exit\n";
		while (!check_input(!(cin >> choice)));

		switch (choice)
		{
			case 1:
				do cout << "1. Point\n2. Ellipse\n3. Ellipsoid\n4. Sphere\n";
				while (!check_input(!(cin >> choice)));

				switch (choice)
				{
					case 1:
						point.printPoint(cout);
					break;
					case 2:
						ellipse.printData(cout);
					break;
					case 3:
						ellipsoid.printData(cout);
					break;
					case 4:
						sphere.printData(cout);
				}

				cout << endl;
			break;
			case 2:
				do cout << "1. Point\n2. Ellipse\n3. Ellipsoid\n4. Sphere\n";
				while (!check_input(!(cin >> choice)));

				switch (choice)
				{
					case 1:
						do cout << "Enter X: ";
						while (!check_input(!(cin >> choice)));
						point.setX(choice);

						do cout << "Enter Y: ";
						while (!check_input(!(cin >> choice)));
						point.setY(choice);
					break;
					case 2:
						do cout << "Enter center point X: ";
						while (!check_input(!(cin >> choice)));
						ellipse.setX(choice);

						do cout << "Enter center point Y: ";
						while (!check_input(!(cin >> choice)));
						ellipse.setY(choice);

						do cout << "Enter radius X: ";
						while (!check_input(!(cin >> choice)));
						ellipse.setRadiusX(choice);

						do cout << "Enter radius Y: ";
						while (!check_input(!(cin >> choice)));
						ellipse.setRadiusY(choice);

					break;
					case 3:
						do cout << "Enter center point X: ";
						while (!check_input(!(cin >> choice)));
						ellipsoid.setX(choice);

						do cout << "Enter center point Y: ";
						while (!check_input(!(cin >> choice)));
						ellipsoid.setY(choice);

						do cout << "Enter center point Z: ";
						while (!check_input(!(cin >> choice)));
						ellipsoid.setZ(choice);

						do cout << "Enter radius X: ";
						while (!check_input(!(cin >> choice)));
						ellipsoid.setRadiusX(choice);

						do cout << "Enter radius Y: ";
						while (!check_input(!(cin >> choice)));
						ellipsoid.setRadiusY(choice);

						do cout << "Enter radius Z: ";
						while (!check_input(!(cin >> choice)));
						ellipsoid.setRadiusZ(choice);
					break;
					case 4:
						do cout << "Enter center point X: ";
						while (!check_input(!(cin >> choice)));
						sphere.setX(choice);

						do cout << "Enter center point Y: ";
						while (!check_input(!(cin >> choice)));
						sphere.setY(choice);

						do cout << "Enter center point Z: ";
						while (!check_input(!(cin >> choice)));
						sphere.setZ(choice);

						do cout << "Enter radius: ";
						while (!check_input(!(cin >> choice)));
						sphere.setRadiusX(choice);
				}
			break;
			case 3:
				o.open("info.txt", ios::out);

				o << "Point:\n";
				point.printPoint(o);
				o << endl;

				o << "Ellipse:\n";
				ellipse.printData(o);
				o << endl;

				o << "Ellipsoid:\n";
				ellipsoid.printData(o);
				o << endl;

				o << "Sphere:\n";
				sphere.printData(o);

				o.close();
			break;
			case 4: exit = true;
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
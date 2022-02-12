#include <iostream>
#include "SmartPointer.h"

using std::cout;
using std::endl;

int main()
{
    while (true)
    {
        SmartPointer<int> i1(new int(2));

        cout << "int1 counter: " << i1.GetCounter() << endl;
        cout << endl;

        SmartPointer<int> i2 = i1;

        cout << "int1 counter: " << i1.GetCounter() << endl;
        cout << "int2 counter: " << i2.GetCounter() << endl;
        cout << endl;

        i2 = SmartPointer<int>(new int(3));

        cout << "int1 counter: " << i1.GetCounter() << endl;
        cout << "int2 counter: " << i2.GetCounter() << endl;
        cout << endl;
    }



    return 0;
}

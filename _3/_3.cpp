#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    String s;

    cout << !s << endl;

    cin >> s;
    cout << s << endl;

    cout << !s << endl;

    String s2(s);

    cout << s2 << endl;
    cout << s2(3, s2.getLength() - 1)[1] << endl;

    return 0;
}
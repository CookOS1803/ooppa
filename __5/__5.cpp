#include <iostream>
#include <Windows.h>
#include <map>
#include <algorithm>

struct point
{
    int x, y;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    std::map<std::string, point> m;
    m["raz"] ={1, 3};
    m["dva"] = { 7, 2 };
    m["tri"] = { 4, 4 };
    m["cadtire"] ={ 4, 4 };
    m["caetire"] ={ 4, 4 };
    
    for (auto& [x, y] : m)
    {
        std::cout << x << ": (" << y.x << ", " << y.y << ")\n";
    }
    
    

    return 0;
}
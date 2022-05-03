#include <Windows.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include "Menus.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    std::stack<int, std::vector<int>> s;
    std::queue<int> q;

    s.push(3);
    s.push(5);
    s.push(4);

    q.push(3);
    q.push(5);
    q.push(4);

    std::cout << "Stack:\n";
    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    std::cout << "\nQueue:\n";
    while (!q.empty())
    {
        std::cout << q.front() << std::endl;
        q.pop();
    }

    MainMenu();

    return 0;
}


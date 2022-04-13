#include <iostream>
#include <Windows.h>
#include "UserInput.h"
#include "User.h"
#include "Menus.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, 1250, 700, TRUE); // 800 width, 100 height


    IMEX::MainMenu();
        
    return 0;
}
#include <iostream>
#include <Windows.h>
#include "UserInput.h"
#include "User.h"
#include "Menus.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    IMEX::MainMenu();
        
    return 0;
}
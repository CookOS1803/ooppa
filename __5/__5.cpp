#include <Windows.h>
#include "Menus.h"
#include "WorkerList.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    WorkerList workers;
    workers.Add("Kirill", "55-55-555", 1000, 5);
    workers.Add("Toha", "12-34-567", 900, 3);
    
    MainMenu(workers);

    return 0;
}

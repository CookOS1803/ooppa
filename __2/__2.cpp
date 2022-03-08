#include <vector>
#include "UserInput.h"

int main()
{
    int choice;
    bool exit = false;
    
    while (!exit)
    {
        INPUT
        (
            choice,
            std::cout
                << "1."
        );
    }

    return 0;
}

#pragma once
#include <iostream>

bool check_input(bool fail_flag)
{
    if (fail_flag)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        return false;
    }
    else return true;
}

#define INPUT_CONDITION(command, value, condition) \
    do {command;} \
    while (!check_input(!(std::cin >> value)) or !(condition)); \
    std::ignore = getc(stdin)

#define INPUT(command, value) INPUT_CONDITION(command, value, true)
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

#define INPUT_CONDITION(value, condition, command) \
    do {command;} \
    while (!check_input(!(std::cin >> value)) or !(condition))

#define INPUT(value, command) INPUT_CONDITION(value, true, command)
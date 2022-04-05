#pragma once
#include <iostream>
#include <string>

#define INPUT_CONDITION(command, value, condition) \
    do \
    { \
        while (true) \
        { \
            command; \
            std::cin >> value; \
            if (std::cin.good()) \
                break; \
            std::cin.clear(); \
            std::cin.ignore(99999, '\n'); \
        } \
    } \
    while (!(condition)); \
    getc(stdin)

#define INPUT(command, value) INPUT_CONDITION(command, value, true)
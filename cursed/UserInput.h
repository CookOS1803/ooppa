#pragma once
#include <iostream>
#include <string>

#define INPUT_CONDITION(command, value, condition) \
    do \
    { \
        while (true) \
        { \
            command; \
            std::string temp; \
            std::getline(std::cin, temp); \
            try \
            { \
                value = std::stoi(temp); \
            } \
            catch (...) \
            { \
                continue; \
            } \
            break; \
        } \
    } \
    while (!(condition))

#define INPUT(command, value) INPUT_CONDITION(command, value, true)

std::string StringInput(std::string_view message);
std::string StringInput(std::string_view message, std::string_view invalidChars);

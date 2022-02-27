#include <iostream>
#include <vector>

bool check_input(bool fail_flag);

#define INPUT_CONDITION(value, condition, ...) \
    do {__VA_ARGS__;} \
    while (!check_input(!(std::cin >> value)) or !(condition))

#define INPUT(value, ...) INPUT_CONDITION(value, true, __VA_ARGS__)

int main()
{
    std::vector<std::string> s;
    s.emplace_back("odin");
    s.emplace_back("dva");
    s.emplace_back("tri");
   
    int choice;

    INPUT_CONDITION
    (
        choice,
        choice >= 1 and choice <= s.size(),
        for (int i = 1; i <= s.size(); i++)
        {
            std::cout << i << ". " << s[i - 1] << std::endl;
        }
    );

    std::cout << s[choice - 1] << std::endl;
}

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
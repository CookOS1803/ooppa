#include "UserInput.h"

std::string StringInput(std::string_view message)
{
    std::string str;
    while (true)
    {
        std::cout << message;
        std::getline(std::cin, str);

        if (str.empty())
            continue;

        bool hasOnlyWS = true;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
            {
                hasOnlyWS = false;
                str = str.substr(i, str.size());
                break;
            }
        }

        if (hasOnlyWS)
            continue;

        for (int i = str.size() - 1; i != 0; i--)
        {
            if (str[i] != ' ')
            {
                str = str.substr(0, i + 1);
                break;
            }
        }
        
        return str;
    }
}

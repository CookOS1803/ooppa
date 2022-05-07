#include "SortHelper.h"
#include <algorithm>

bool IMEX::SortHelper::CompareStrings(std::string_view first, std::string_view second)
{
    auto len = std::min(first.size(), second.size());

    for (int i = 0; i < len; i++)
    {
        if (first[i] == second[i])
            continue;

        return first[i] < second[i];
    }

    return len == first.size();
}

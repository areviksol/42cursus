#include <iostream>

bool allCharactersAreAlpha(const std::string& str)
{
    for (std::size_t i = 0; i < str.length(); ++i)
    {
        if (!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool allCharactersAreDigit(const std::string& str)
{
    for (std::size_t i = 0; i < str.length(); ++i)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

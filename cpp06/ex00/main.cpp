#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "./type [argument]" << std::endl;
    else
    {
        std::string str(av[1]);
        ScalarConverter::convert(str);        
    }
    return (0);
}
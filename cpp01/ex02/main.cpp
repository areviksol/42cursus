#include <iostream>

int main(void)
{
    std::string variable_string = "HI THIS IS BRAIN";
    std::string *stringPTR = &variable_string;
    std::string &stringREF = variable_string;

    std::cout << &variable_string << std::endl;
    std::cout << &stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << variable_string << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    return 0;
}
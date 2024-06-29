#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const std::string &wrongCatType) : WrongAnimal(wrongCatType)
{
    std::cout << "WrongCat parametric constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat assignment operator" << std::endl;
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}
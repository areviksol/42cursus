#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const std::string &type)
{
    std::cout << "Animal parametric constructor" << std::endl;
    this->type = type;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor" << std::endl;
    type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal assignment operator" << std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}


Animal::~Animal()
{
    std::cout << "Animal destructor" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::setType(std::string type) {
    this->type = type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

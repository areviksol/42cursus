#include "Dog.hpp"

Dog::Dog():Animal("Dog")
{
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const std::string &dogType) : Animal(dogType)
{
    std::cout << "Dog parametric constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Dog assignment operator" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
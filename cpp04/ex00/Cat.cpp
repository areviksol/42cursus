#include "Cat.hpp"

Cat::Cat() :Animal("Cat")
{
    std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const std::string &catType) : Animal(catType)
{
    std::cout << "Cat parametric constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")   {
    brain = new Brain();
    std::cout  << "Default constructor for Cat" << std::endl;
}

Cat::Cat(const std::string& catType, Brain* brain) : Animal(catType), brain(new Brain(*brain))
{
    std::cout << "Cat parametric constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other.type), brain(new Brain(*other.brain))
{
    std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assignment operator" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}
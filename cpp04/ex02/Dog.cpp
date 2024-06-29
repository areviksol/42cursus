#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")   {
    brain = new Brain();
    std::cout << "Default constructor for Dog"  << std::endl;
}
Dog::Dog(const std::string& catType, Brain* brain) : Animal(catType), brain(new Brain(*brain))
{
    std::cout << "Dog parametric constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other.type), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assignment operator" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}
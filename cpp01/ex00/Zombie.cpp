#include "Zombie.hpp"

void Zombie:: announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {}


// Parameterized constructor
Zombie::Zombie(std::string name) : name(name) {}

// Copy constructor
Zombie::Zombie(const Zombie &other) : name(other.name) {}

// Destructor
Zombie::~Zombie() {
    std::cout << name << std::endl;
}

// Assignment operator
Zombie &Zombie::operator=(const Zombie &other)
{
    if (this != &other)
    {
        name = other.name;
    }
    return *this;
}

// Setter for Name
void Zombie::setName(std::string name)
{
    this->name = name;
}

// Getter for Name
std::string Zombie::getName() const
{
    return name;
}




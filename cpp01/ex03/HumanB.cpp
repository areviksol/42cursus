#include <iostream>
#include "HumanB.hpp"

void HumanB::attack(void)
{
    Weapon w = *weapon;
    std::cout << name << " attacks with their " << w.getType() << std::endl;
}

HumanB::HumanB() {}

// Parameterized constructor
HumanB::HumanB(std::string name) : name(name) {}

// Copy constructor
HumanB::HumanB(const HumanB &other) : name(other.name){}

// Destructor
HumanB::~HumanB() {}

// Assignment operator
HumanB &HumanB::operator=(const HumanB &other)
{
    if (this != &other)
    {
        name = other.name;
        weapon = other.weapon;
    }
    return *this;
}

// Setter for Name
void HumanB::setName(std::string name)
{
    this->name = name;
}

// Getter for Name
std::string HumanB::getName() const
{
    return name;
}

// Setter for weapon
void HumanB::setWeapon( Weapon &weapon)
{
    this->weapon = &weapon;
}

// Getter for weapon
const Weapon &HumanB::getWeapon() const
{
    return *weapon;
}

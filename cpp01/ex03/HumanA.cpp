#include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << name << "  attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(Weapon &weapon) : weapon(weapon){}

// Parameterized constructor
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

// Copy constructor
HumanA::HumanA(const HumanA &other) : name(other.name), weapon(other.weapon) {}

// Destructor
HumanA::~HumanA()
{
    // std::cout << name << std::endl;
}

// Assignment operator
HumanA &HumanA::operator=(const HumanA &other)
{
    if (this != &other)
    {
        name = other.name;
        weapon = other.weapon;
    }
    return *this;
}

// Setter for Name
void HumanA::setName(std::string name)
{
    this->name = name;
}

// Getter for Name
std::string HumanA::getName() const
{
    return name;
}

// Setter for weapon
void HumanA::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}

// Getter for weapon
Weapon HumanA::getWeapon() const
{
    return weapon;
}

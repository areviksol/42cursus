#include "Weapon.hpp"

Weapon::Weapon() {}


// Parameterized constructor
Weapon::Weapon(std::string type) : type(type) {}

// Copy constructor
Weapon::Weapon(const Weapon &other) : type(other.type) {}

// Destructor
Weapon::~Weapon() {
    // std::cout << type << std::endl;
}

// Assignment operator
Weapon &Weapon::operator=(const Weapon &other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

// Setter for type
void Weapon::setType(std::string type)
{
    this->type = type;
}

// Getter for type
// const std::string &Weapon::getType() 
// {
//     return type;
// }


const std::string&  Weapon::getType()
{
	return type;
}

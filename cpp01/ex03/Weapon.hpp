#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
private:
    std::string type;

public:
    // Default constructor
    Weapon();

    // Parameterized constructor
    Weapon(std::string type);

    // Copy constructor
    Weapon(const Weapon &other);

    // Destructor
    ~Weapon();

    // Assignment operator
    Weapon &operator=(const Weapon &other);

    // Setter for type
    void setType(std::string type);

    // Getter for type
	const std::string& getType();
};

#endif

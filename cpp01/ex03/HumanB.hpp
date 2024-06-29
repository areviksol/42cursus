#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"
class HumanB
{
private:
    std::string name;
    Weapon *weapon;

public:
    // Default constructor
    HumanB();

    // Parameterized constructor
    HumanB(std::string name);

    // Copy constructor
    HumanB(const HumanB &other);

    // Destructor
    ~HumanB();

    // Assignment operator
    HumanB &operator=(const HumanB &other);

    // Setter for Name
    void setName(std::string name);

    // Getter for Name
    std::string getName() const;

    // Setter for weapon
    void setWeapon( Weapon &weapon);

    // Getter for weapon
    const Weapon &getWeapon() const; // Declaration of the getWeapon function
    void attack(void);
};

#endif
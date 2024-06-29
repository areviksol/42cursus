#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon &weapon;
public:
    // Default constructor
    HumanA(Weapon &weapon);

    // Parameterized constructor
    HumanA(std::string name, Weapon &weapon);

    // Copy constructor
    HumanA(const HumanA& other);

    // Destructor
    ~HumanA();

    // Assignment operator
    HumanA& operator=(const HumanA& other);

    // Setter for Name
    void setName(std::string name);

    // Getter for Name
    std::string getName() const ;

    // Setter for weapon
    void setWeapon(Weapon weapon);

    // Getter for weapon
    Weapon getWeapon() const ;

    void attack(void);
};


#endif
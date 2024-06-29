#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called " << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    std::cout << "ScavTrap parameter constructor called " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other){
    std::cout << "ScavTrap copy constructor called " << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called " << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if(getPoints() == 0 || getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap can't attack" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode." << std::endl;
}
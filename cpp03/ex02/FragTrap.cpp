#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called " << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    std::cout << "FragTrap parameter constructor called " << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other){
    std::cout << "FragTrap copy constructor called " << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called " << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << getName() << " requests a high five!" << std::endl;
}
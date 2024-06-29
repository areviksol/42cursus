#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _points(10), _energy_points(10), _attack_damage(0) {}

ClapTrap::ClapTrap(std::string name) : _name(name), _points(10), _energy_points(10), _attack_damage(0) {}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _points(other._points), _energy_points(other._energy_points), _attack_damage(other._attack_damage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _points = other._points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}
void ClapTrap::setName(std::string name)
{
    this->_name = name;
}
std::string ClapTrap::getName() const
{
    return _name;
}

void ClapTrap::setPoints(int value)
{
    this->_points = value;
}
int ClapTrap::getPoints() const
{
    return _points;
}

void ClapTrap::setEnergyPoints(int value)
{
    this->_energy_points = value;
}
int ClapTrap::getEnergyPoints() const
{
    return _energy_points;
}

void ClapTrap::setAttackDamage(int value)
{
    this->_attack_damage = value;
}
int ClapTrap::getAttackDamage() const
{
    return _attack_damage;
}


void ClapTrap::attack(const std::string& target) {
    if(_points == 0 || _energy_points == 0)
    {
        std::cout << "ClapTrap can't attack" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
    _energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if(_points <= (int)amount)
    {
        _points = 0;
        std::cout << _name << " ClapTrap is dead! " << std::endl;
        return;
    }
    _points -= amount;
    if(_points <= 0)
    {
        _points = 0;
        std::cout << "ClapTrap lost  " << amount << "point and died" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. Hit points remaining: " << _points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if(_points == 0 || _energy_points == 0)
    {
        std::cout << "ClapTrap can't repaired" << std::endl;
        return;
    }
    _points += amount;
    _energy_points -=1;
    std::cout << "ClapTrap " << _name << " is repaired and regains " << amount << " hit points. Total hit points: " << _points << std::endl;
}
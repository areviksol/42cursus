#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ClapTrap{
    private:
        std::string _name;
        int _points;
        int _energy_points;
        int _attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount); 

        std::string getName() const;
        void setName(std::string name);
        int getPoints() const;
        void setPoints(int value);
        int getEnergyPoints() const;
        void setEnergyPoints(int value);
        int getAttackDamage() const;
        void setAttackDamage(int value);
};

#endif

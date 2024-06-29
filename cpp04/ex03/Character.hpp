#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{

public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    ~Character();

    std::string const &getName() const;
    void setName(std::string name);
    void equip(AMateria *item);
    void unequip(int i);
    void use(int i, ICharacter &target);

private:
    std::string _name;
    int _size;
    AMateria *_inventory[4];
    void copyInventory(const Character &other);
};
#endif
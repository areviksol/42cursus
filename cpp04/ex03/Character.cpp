#include "Character.hpp"

Character::Character() : _name(""), _size(0)
{
    std::cout << "Default constructor fot character" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        _inventory[i] = nullptr;
    }
}
Character::Character(const std::string &name) : _name(name), _size(0)
{
    std::cout << "Parametric constructor fot character" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        _inventory[i] = nullptr;
    }
}

Character::Character(const Character &other) : _name(other._name), _size(0)
{
    std::cout << "Copy constructor fot character" << std::endl;
    copyInventory(other);
}

Character &Character::operator=(const Character &other)
{
    std::cout << "Copy assignment operator for Character" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    for (int i = 0; i < _size; ++i)
    {
        delete _inventory[i];
        _inventory[i] = nullptr;
    }
    _size = 0;

    _name = other._name;
    copyInventory(other);

    return *this;
}
Character::~Character()
{
    std::cout << "Destructor for Character" << std::endl;
    for (int i = 0; i < _size; ++i)
    {
        delete _inventory[i];
        _inventory[i] = nullptr;
    }
}
void Character::setName(std::string name)
{
    this->_name = name;
}
std::string const &Character::getName() const
{
    return _name;
}
void Character::copyInventory(const Character &other)
{
    for (int i = 0; i < other._size; ++i)
    {
        if (other._inventory[i])
        {
            _inventory[_size++] = other._inventory[i]->clone();
        }
    }
}

void Character::equip(AMateria *item)
{
    if (_size >= 4 || !item)
    {
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (!_inventory[i])
        {
            _inventory[i] = item;
            _size++;
            break;
        }
    }
}

void Character::unequip(int i)
{
    if (i < 0 || i >= _size)
    {
        return;
    }

    _inventory[i] = nullptr;
    _size--;
}

void Character::use(int i, ICharacter &target)
{
    if (i < 0 || i >= _size || !_inventory[i])
    {
        return;
    }
    _inventory[i]->use(target);
}

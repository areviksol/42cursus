#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    // Zombie  zombie(name);
    // Zombie *ptr = &zombie;
    // return ptr;

    Zombie* p = new Zombie(name);
    return p;
}
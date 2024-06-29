#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* p = new Zombie[N];
    for(int i = 0; i <N; i++)
    {
        p[i].setName(name);
    }
    return p;
}
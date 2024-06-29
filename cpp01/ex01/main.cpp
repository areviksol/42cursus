#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    int n = 23;

    Zombie* Horde = zombieHorde(n, "ATTACK");
    for(int i = 0; i < n; i++)
    {
        Horde[i].announce();
    }
    delete [] Horde;
    return 0;
}
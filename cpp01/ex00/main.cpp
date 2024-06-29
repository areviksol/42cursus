#include "Zombie.hpp"
void randomChump( std::string name );
Zombie* newZombie( std::string name );


int main(void)
{
    Zombie Nyam("My name");
    Nyam.announce();
    Zombie *p = newZombie("Nyam");
    (void) p;
    randomChump("Nyam");
    delete p;
    return 0;
}
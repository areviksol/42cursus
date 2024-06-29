#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("A-2");
    clapTrap.attack("Enemy1");
    clapTrap.takeDamage(30);
    clapTrap.beRepaired(20);
    return 0;
}

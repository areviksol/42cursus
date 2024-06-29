#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    
    ClapTrap clapTrap("GH-7");
    clapTrap.attack("Droideka");

    std::cout << std::endl;

    FragTrap fragTrap("R5-D4");
    fragTrap.attack("droideka");
    fragTrap.highFivesGuys();

    return 0;
}
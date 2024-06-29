#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clapTrap("CL4P-TP");
    ScavTrap scavTrap("SC4V-TP");

    clapTrap.attack("Bandit");
    scavTrap.attack("Bandit");

    scavTrap.guardGate();

    return 0;
}
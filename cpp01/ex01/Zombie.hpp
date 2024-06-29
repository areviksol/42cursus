#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;

public:
    // Default constructor
    Zombie();

    // Parameterized constructor
    Zombie(std::string name);

    // Copy constructor
    Zombie(const Zombie& other);

    // Destructor
    ~Zombie();

    // Assignment operator
    Zombie& operator=(const Zombie& other);

    // Setter for firstName
    void setName(std::string name);

    // Getter for firstName
    std::string getName() const ;

    void announce( void );
};


#endif
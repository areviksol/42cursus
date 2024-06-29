#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
    std::cout << "Default constructor for Ice" << std::endl;
}

Ice::~Ice(){
    std::cout << "Destructor for Ice" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
    std::cout << "Copy constructor for Cure" << std::endl; *this = other;
}

Ice    &Ice::operator=(const Ice &other)  {

    std::cout << "Copy assignment operator for Ice" << std::endl;
    AMateria::operator=(other);
    return (*this);
}

AMateria *Ice::clone() const {return (new Ice(*this));}
void    Ice::use(ICharacter &target)    {
    std::cout << std::endl;
    std::cout <<"* shoots an ice bolt at  " << target.getName() << " *" << std::endl;
    std::cout << std::endl;
}
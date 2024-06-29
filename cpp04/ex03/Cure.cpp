#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
    std::cout << "Default constructor for Cure" << std::endl;
}
Cure::~Cure(){
    std::cout << "Destructor for Cure" <<  std::endl;
}
Cure::Cure(const Cure &other)   {
    std::cout <<  "Copy constructor for Cure" << std::endl; *this = other;
}

Cure    &Cure::operator=(const Cure &other)  {
    std::cout <<  "Copy assignment operator for Cure" <<  std::endl;
    AMateria::operator=(other);
    return (*this);
}

AMateria *Cure::clone() const {return (new Cure(*this));}

void    Cure::use(ICharacter &target)    {
    std::cout << std::endl;
    std::cout <<  "* heals  " << target.getName() << "'s wounds *" << std::endl;
    std::cout << std::endl;
}
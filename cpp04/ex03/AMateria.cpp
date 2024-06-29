#include "AMateria.hpp"

AMateria::AMateria() {
    std::cout << "Default constructor for AMateria"  << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "with type parameter constructor for AMateria"  << std::endl;

}

AMateria::AMateria(const AMateria& other) : type(other.type) {
    std::cout << "Copy constructor for aMateria" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "Copy assignment operator for AMateria" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "Destructor for AMateria"<< std::endl;
}

std::string const& AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
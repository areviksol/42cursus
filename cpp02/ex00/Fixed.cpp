#include "Fixed.hpp"

//Default constructor 
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
Fixed::Fixed(int integer) : value(integer) {}

Fixed::Fixed(const Fixed& other) : value(other.value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Setter for Name
void Fixed::setInteger(int integer)
{
    this->value = integer;
}

// Getter for Name
int Fixed::getInteger() const
{
    return value;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(const int raw) {
    value = raw;
}
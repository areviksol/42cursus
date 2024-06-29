#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(int integer);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    void setInteger(int integer);
    int getInteger() const ;
    int getRawBits() const;
    void setRawBits(const int raw);
};

#endif
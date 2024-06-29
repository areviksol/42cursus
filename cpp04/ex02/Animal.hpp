#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;
    Animal();
    Animal(const Animal& other);
    Animal(const std::string& type);

public:
    virtual ~Animal();
    Animal& operator=(const Animal& other);
    std::string getType() const;
    void setType(std::string type);
    virtual void makeSound() const = 0;
};


#endif

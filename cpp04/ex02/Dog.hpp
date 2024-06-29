#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal {
private:
    Brain* brain;
public:
    Dog();

    Dog(const std::string& dogType);
    Dog(const std::string& dogType, Brain* brain);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    virtual ~Dog();

    void makeSound() const;
};

#endif

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    //const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // std::cout << j->getType() << std::endl;
    // std::cout << i->getType() << std::endl;
    // i->makeSound();
    // j->makeSound();
    // meta->makeSound();

    // std::cout << "Additional Tests" << std::endl;

    // const Animal* d = new Dog("akita inu");
    // const Animal* c = new Cat("van cat");
    // const WrongAnimal* wa = new WrongAnimal();
    // const WrongAnimal* wc = new WrongCat("Sphynx");

    // std::cout << d->getType() << std::endl;
    // std::cout << c->getType() << std::endl;
    // std::cout << wa->getType() << std::endl;
    // std::cout << wc->getType() << std::endl;

    // d->makeSound();
    // c->makeSound();
    // wa->makeSound();
    // wc->makeSound();

    // delete meta;
    delete j;
    delete i;
    // delete d;
    // delete c;
    // delete wa;
    // delete wc;
    system("leaks Animal"); 
    return 0;
}

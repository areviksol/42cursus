#include "MutantStack.hpp"  

int main() {
    MutantStack<int> mutantStack;

    mutantStack.push(10);
    mutantStack.push(20);
    mutantStack.push(30);
    mutantStack.push(40);

    MutantStack<int>::iterator it = mutantStack.begin();
    MutantStack<int>::iterator itEnd = mutantStack.end();

    std::cout << "Elements in the stack: ";
    while (it != itEnd) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    return 0;
}

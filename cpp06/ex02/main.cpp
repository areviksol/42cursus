#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast&) {
        try {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
            return;
        } catch (const std::bad_cast&) {
            try {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
                return;
            } catch (const std::bad_cast&) {
                std::cout << "Unknown" << std::endl;
                return;
            }
        }
    }
}


int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < 5; ++i) {
        Base* object = generate();
        std::cout << "Pointer identification: ";
        identify(object);
        std::cout << "Reference identification: ";
        identify(*object);
        delete object;
    }

    return 0;
}

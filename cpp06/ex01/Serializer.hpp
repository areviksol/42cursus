#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

struct Data {
    int value;
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    static uintptr_t serializedValue;
    
    Serializer();
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& other);
    ~Serializer() ;
};
#endif
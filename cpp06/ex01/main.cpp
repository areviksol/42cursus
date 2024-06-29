#include <iostream>
#include "Serializer.hpp"


int main() {
    Data dataObject;
    dataObject.value = 42;

    uintptr_t serializedValue = Serializer::serialize(&dataObject);
    Data* deserializedData = Serializer::deserialize(serializedValue);

    if (deserializedData == &dataObject) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Original value: " << dataObject.value << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}

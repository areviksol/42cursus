#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

class ArrayOutOfBoundsException : public std::exception {
public:
    const char* what() const throw() {
        return "Array index out of bounds";
    }
};

template <typename T>
class Array {
public:
    Array() : data(0), count(0) {}

    Array(unsigned int n) : data(new T[n]), count(n) {
        for (unsigned int i = 0; i < count; ++i) {
            data[i] = T();
        }
    }

    Array(const Array& other) : data(new T[other.count]), count(other.count) {
        for (unsigned int i = 0; i < count; ++i) {
            data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.size];
            count = other.size;
            for (unsigned int i = 0; i < count; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] data;
    }

    T& operator[](unsigned int index){
        if (index >= count) {
            throw ArrayOutOfBoundsException();
        }
        return data[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= count) {
            throw ArrayOutOfBoundsException();
        }
        return data[index];
    }
    
    unsigned int size() const {
        return count;
    }

private:
    T* data;
    unsigned int count;
};

#endif

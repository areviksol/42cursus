#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {

public:
    Span();
    Span(unsigned int N);
    Span(const Span &copy);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
private : 
    unsigned int N;
    std::vector<int> numbers;
};

#endif
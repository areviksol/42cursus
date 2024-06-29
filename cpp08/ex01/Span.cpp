#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {
    numbers.reserve(N);
}

Span:: Span(const Span& copy) : N(copy.N), numbers(copy.numbers) {}

Span& Span::operator=(const Span& other) {
    if (this == &other) {
        return *this;
    }
    N = other.N;
    numbers = other.numbers;
    return *this;
}

Span::~Span() {}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Cannot calculate span with fewer than two numbers.");
    }
    std::sort(numbers.begin(), numbers.end());
    int minSpan = numbers[1] - numbers[0];
    for (size_t i = 2; i < numbers.size(); ++i) {
        int span = numbers[i] - numbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Cannot calculate span with fewer than two numbers.");
    }
    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> minMax = std::minmax_element(numbers.begin(), numbers.end());
    return *minMax.second - *minMax.first;
}

void Span::addNumber(int number) {
    if (numbers.size() >= N) {
        throw std::overflow_error("Cannot add more numbers, Span is full.");
    }
    numbers.push_back(number);
}
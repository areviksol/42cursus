#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

// int main() {
//     // Test 1: Creating a Span with a capacity of 10000
//     Span sp(10000);

//     // Test 2: Adding 10000 numbers
//     for (int i = 1; i <= 10000; ++i) {
//         sp.addNumber(i);
//     }

//     // Test 3: Calculating and printing the shortest span
//     try {
//         int shortest = sp.shortestSpan();
//         std::cout << "Shortest Span: " << shortest << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Shortest Span Test Failed: " << e.what() << std::endl;
//     }

//     // Test 4: Calculating and printing the longest span
//     try {
//         int longest = sp.longestSpan();
//         std::cout << "Longest Span: " << longest << std::endl;
//     } catch (const std::exception& e) {
//         std::cerr << "Longest Span Test Failed: " << e.what()  << std::endl;
//     }

//     return 0;
// }

#include "easyfind.hpp"

int main() {
// Initialize a std::vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // Initialize a std::list
    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_back(50);

    
    try {
        std::vector<int>::iterator vecResult = easyfind(vec, 3);
        std::list<int>::iterator listResult = easyfind(myList, 20);

        std::cout << "Found in vector: " << *vecResult << std::endl;
        std::cout << "Found in list: " << *listResult << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        easyfind(vec, 6);  // This will throw an exception because 6 is not in the vector
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
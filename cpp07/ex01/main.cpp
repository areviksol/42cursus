#include "iter.hpp"

// template <typename T>
// struct printElement {
//      operator()(const T& element) const {
//         std::cout << element << " ";
//     }
// };

template< typename T >
void printElement( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << "Int array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "Double array: ";
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    return 0;
}
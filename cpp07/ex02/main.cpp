#include "Array.hpp"

int main() {
    Array<int> arr(5);
    
    for (unsigned int i = 0; i < arr.size(); ++i) {
        arr[i] = i * 10;
    }

    const Array<int> copyArr(arr);
    // copyArr[2] = 89; //should be an error
    arr[2] = 42;
    std::cout << "arr[2] is" << copyArr[2] << std::endl;
    std::cout << "copyArr[2] is" << arr[2] << std::endl;
    std::cout << "Original Array: ";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copied Array: ";
    for (unsigned int i = 0; i < copyArr.size(); ++i) {
        std::cout << copyArr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

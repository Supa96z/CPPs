#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Default constructor
        Array<int> emptyArray;
        std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

        // Parameterized constructor
        Array<int> intArray(5);
        std::cout << "Size of int array: " << intArray.size() << std::endl;

        // Setting values
        for (std::size_t i = 0; i < intArray.size(); ++i) {
            intArray[i] = static_cast<int>(i) * 10;
        }

        // Getting and printing values
        for (std::size_t i = 0; i < intArray.size(); ++i) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        // Copy constructor
        Array<int> copiedArray(intArray);
        std::cout << "Size of copied array: " << copiedArray.size() << std::endl;

        // Modify original array
        intArray[0] = 100;

        // Check copied array remains unchanged
        std::cout << "copiedArray[0] (should be 0): " << copiedArray[0] << std::endl;

        // Assignment operator
        Array<int> assignedArray = intArray;
        std::cout << "Size of assigned array: " << assignedArray.size() << std::endl;

        // Modify original array
        intArray[1] = 200;

        // Check assigned array remains unchanged
        std::cout << "assignedArray[1] (should be 10): " << assignedArray[1] << std::endl;

        // Out of bounds access
        try {
            std::cout << intArray[10] << std::endl;
        } catch (const OutOfBoundsException& e) {
            std::cout << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


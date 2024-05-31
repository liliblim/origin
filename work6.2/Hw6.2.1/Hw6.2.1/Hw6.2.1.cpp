

#include "C:\Users\ПК\Desktop\lilihomework\work6.2\Hw6.2.1\smart_array.h"
#include <iostream>

SmartArray::SmartArray(size_t initial_capacity)
    : data(new int[initial_capacity]), capacity(initial_capacity), size(0) {}

SmartArray::~SmartArray() {
    delete[] data;
}

void SmartArray::add_element(int element) {
    if (size < capacity) {
        data[size++] = element;
    }
    else {
        throw std::out_of_range("Cannot add element. Array capacity exceeded.");
    }
}

int SmartArray::get_element(size_t index) const {
    if (index < size) {
        return data[index];
    }
    else {
        throw std::out_of_range("Invalid element index.");
    }
}

int main() {
    try {
        SmartArray arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        try {
            arr.add_element(16); // Эта строка вызовет исключение
        }
        catch (const std::out_of_range& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }

        for (size_t i = 0; i < arr.get_size(); ++i) {
            std::cout << "Element at index " << i << ": " << arr.get_element(i) << std::endl;
        }

        try {
            std::cout << arr.get_element(10) << std::endl; // Эта строка вызовет исключение
        }
        catch (const std::out_of_range& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }

    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}

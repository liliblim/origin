#include "smart_array.h"
#include <algorithm> // для std::copy
#include <iostream>  // для std::cerr и std::cout

// Реализация методов класса smart_array
smart_array::smart_array(size_t initial_capacity)
    : data(initial_capacity ? new int[initial_capacity] : nullptr),
    capacity(initial_capacity),
    size(0) {}

smart_array::smart_array(const smart_array& other)
    : data(other.capacity ? new int[other.capacity] : nullptr),
    capacity(other.capacity),
    size(other.size) {
    std::copy(other.data, other.data + other.size, data);
}

smart_array::~smart_array() {
    delete[] data;
}

smart_array& smart_array::operator=(const smart_array& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        data = capacity ? new int[capacity] : nullptr;
        std::copy(other.data, other.data + other.size, data);
    }
    return *this;
}

void smart_array::add_element(int element) {
    if (size < capacity) {
        data[size++] = element;
    }
    else {
        std::cerr << "Array capacity exceeded" << std::endl;
    }
}

int smart_array::get_element(size_t index) const {
    if (index < size) {
        return data[index];
    }
    else {
        std::cerr << "Index out of range" << std::endl;
        return -1;
    }
}

size_t smart_array::get_size() const {
    return size;
}

// Главная функция
int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;

        for (size_t i = 0; i < arr.get_size(); ++i) {
            std::cout << "Element at index " << i << ": " << arr.get_element(i) << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}


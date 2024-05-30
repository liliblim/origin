#pragma once


class SmartArray {
private:
    int* data;
    size_t capacity;
    size_t size;

public:
    SmartArray(size_t initial_capacity)
        : data(new int[initial_capacity]), capacity(initial_capacity), size(0) {}

    ~SmartArray() {
        delete[] data;
    }

    void add_element(int element) {
        if (size < capacity) {
            data[size++] = element;
        }
        else {
            std::cerr << "Array capacity exceeded" << std::endl;
        }
    }

    int get_element(size_t index) const {
        if (index < size) {
            return data[index];
        }
        else {
            std::cerr << "Index out of range" << std::endl;
            return -1; 
        }
    }
};



#pragma once


#include <cstddef> 

class smart_array {
private:
    int* data;
    size_t capacity;
    size_t size;

public:
    smart_array(size_t initial_capacity = 0);
    smart_array(const smart_array& other);
    ~smart_array();

    smart_array& operator=(const smart_array& other);

    void add_element(int element);
    int get_element(size_t index) const;
    size_t get_size() const;
};



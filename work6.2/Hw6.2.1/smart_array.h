#pragma once


class SmartArray {
private:
    int* data;
    size_t capacity;
    size_t size;

public:
    SmartArray(size_t initial_capacity);
    ~SmartArray();

    // «апрещаем копирование и присваивание
    SmartArray(const SmartArray&) = delete;
    SmartArray& operator=(const SmartArray&) = delete;

    void add_element(int element);
    int get_element(size_t index) const;
    size_t get_size() const { return size; }
};


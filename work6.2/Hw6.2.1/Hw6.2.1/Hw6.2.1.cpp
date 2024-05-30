#include <iostream>
#include "C:\Users\ПК\Desktop\lilihomework\work6.2\Hw6.2.1\smart_array.h"

int main() {
    SmartArray arr(5); 

    arr.add_element(1); 
    arr.add_element(4);
    arr.add_element(155);
    arr.add_element(14);
    arr.add_element(15);
 
    arr.add_element(20); 

    std::cout << "Element at index 1: " << arr.get_element(1) << std::endl;

    std::cout << "Element at index 10: " << arr.get_element(10) << std::endl; 

    return 0;
}

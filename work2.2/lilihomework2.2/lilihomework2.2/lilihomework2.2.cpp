// lilihomework2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;
    string street;
    int houseNumber;
    int flatNumber;
    string index;
};

void printAddress(const Address& address) {
    std::cout << "Город: " << address.city << endl;
    std::cout << "Улица: " << address.street << endl;
    std::cout << "Номер дома: " << address.houseNumber << endl;
    std::cout << "Номер квартиры: " << address.flatNumber << endl;
    std::cout << "Индекс: " << address.index << endl << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Address address1;
    std::cout << "Введите город: ";
    std::cin >> address1.city;

    std::cout << "Введите улицу: ";
    std::cin >> address1.street;

    std::cout << "Введите номер дома: ";
    std::cin >> address1.houseNumber;

    std::cout << "Введите номер квартиры: ";
    std::cin >> address1.flatNumber;

    std::cout << "Введите индекс: ";
    std::cin >> address1.index;
    std::cout << " " << endl;

    Address address2;
    std::cout << "Введите город: ";
    std::cin >> address2.city;

    std::cout << "Введите улицу: ";
    std::cin >> address2.street;

    std::cout << "Введите номер дома: ";
    std::cin >> address2.houseNumber;

    std::cout << "Введите номер квартиры: ";
    std::cin >> address2.flatNumber;

    std::cout << "Введите индекс: ";
    std::cin >> address2.index;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

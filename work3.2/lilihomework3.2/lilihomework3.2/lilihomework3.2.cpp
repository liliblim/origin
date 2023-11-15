#include <iostream>
#include <Windows.h>

class Counter {
private:
    int value;

public:
    Counter() : value(1) {}

    Counter(int initialValue) : value(initialValue) {}

    void increment() {
        value++;
    }

    void decrement() {
        value--;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char command;
    int initialValue;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::string input;
    std::cin >> input;

    if (input == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initialValue;
    }
    else {
        initialValue = 1;
    }

    Counter counter(initialValue);

    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command) {
        case '+':
            counter.increment();
            break;
        case '-':
            counter.decrement();
            break;
        case '=':
            std::cout << counter.getValue() << std::endl;
            break;
        case 'x':
            std::cout << "До свидания!" << std::endl;
            break;
        default:
            std::cout << "Некорректная команда. Повторите ввод." << std::endl;
        }

    } while (command != 'x');

    return 0;
}


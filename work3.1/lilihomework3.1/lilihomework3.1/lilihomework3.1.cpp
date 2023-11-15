#include <iostream>

class Calculator {
private:
    double num1;
    double num2;

public:
    double add() const {
        return num1 + num2;
    }

    double multiply() const {
        return num1 * num2;
    }

    double subtract_1_2() const {
        return num1 - num2;
    }

    double subtract_2_1() const {
        return num2 - num1;
    }

    double divide_1_2() const {
        if (num2 != 0) {
            return num1 / num2;
        }
        else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            return 0.0;
        }
    }

    double divide_2_1() const {
        if (num1 != 0) {
            return num2 / num1;
        }
        else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            return 0.0;
        }
    }

    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else {
            std::cout << "Ошибка: значение num1 не может быть равно 0!" << std::endl;
            return false;
        }
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else {
            std::cout << "Ошибка: значение num2 не может быть равно 0!" << std::endl;
            return false;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Calculator calculator;
    int user_num = 0;
    while (true) {
        double input_num1, input_num2;

        std::cout << "Введите num1: ";
        std::cin >> input_num1;

        if (!calculator.set_num1(input_num1)) {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        std::cout << "Введите num2: ";
        std::cin >> input_num2;

        if (!calculator.set_num2(input_num2)) {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        std::cout << "num1 + num2 = " << calculator.add() << std::endl;
        std::cout << "num1 - num2 = " << calculator.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calculator.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calculator.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calculator.divide_2_1() << std::endl;
        user_num++;

        if (user_num >= 2) {
            break;
        }
    }

    return 0;
}

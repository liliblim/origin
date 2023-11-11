// lilihomework3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

        if (input_num1 == 0) {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        std::cout << "Введите num2: ";
        std::cin >> input_num2;

        if (input_num2 == 0) {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }

        if (calculator.set_num1(input_num1) && calculator.set_num2(input_num2)) {
            std::cout << "num1 + num2 = " << calculator.add() << std::endl;
            std::cout << "num1 - num2 = " << calculator.subtract_1_2() << std::endl;
            std::cout << "num2 - num1 = " << calculator.subtract_2_1() << std::endl;
            std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
            std::cout << "num1 / num2 = " << calculator.divide_1_2() << std::endl;
            std::cout << "num2 / num1 = " << calculator.divide_2_1() << std::endl;
            user_num++;
        }
        if (user_num >= 2) {
            break;
        }
    }

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

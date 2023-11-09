// lilihomework2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

enum class months {
    Некорректный_месяц = 0,
    Январь,
    Февраль,
    Март,
    Апрель,
    Май,
    Июнь,
    Июль,
    Август,
    Сентябрь,
    Октябрь,
    Ноябрь,
    Декабрь
};


    int main(int argc, char** argv)
    {
        setlocale(LC_ALL, "Russian");
       
            int user_print;

            do {
                std::cout << "Введите номер месяца: ";
                std::cin >> user_print;

                if (user_print == 0) {
                    cout << "До свидания!" << endl;
                    break;
                }

                if (user_print < 1 || user_print > 12) {
                    std::cout << "Неправильный номер!" << endl;
                    continue;
                }

                months month = static_cast<months>(user_print);

                switch (month) {
                case months::Январь:
                    std::cout << "Январь" << endl;
                    break;
                case months::Февраль:
                    std::cout << "Февраль" << endl;
                    break;
                case months::Март:
                    std::cout << "Март" << endl;
                    break;
                case months::Апрель:
                    std::cout << "Апрель" << endl;
                    break;
                case months::Май:
                    std::cout << "Май" << endl;
                case months::Июнь:
                    std::cout << "Июнь" << endl;
                    break;
                case months::Июль:
                    std::cout << "Июль" << endl;
                    break;
                case months::Август:
                    std::cout << "Август" << endl;
                    break;
                case months::Сентябрь:
                    std::cout << "Сентябрь" << endl;
                    break;
                case months::Октябрь:
                    std::cout << "Октябрь" << endl;
                    break;
                case months::Ноябрь:
                    std::cout << "Ноябрь" << endl;
                    break;
                case months::Декабрь:
                    std::cout << "Декабрь" << endl;
                    break;
                default:
                    std::cout << "Неправильный номер!" << endl;
                    break;
                }
            } while (true);

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

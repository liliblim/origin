// homeworklili2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        int n, m;
        inputFile >> n;

        int* arrayN = new int[n];
        for (int i = 0; i < n; ++i) {
            inputFile >> arrayN[i];
        }

        inputFile >> m;

        int* arrayM = new int[m];
        for (int i = 0; i < m; ++i) {
            inputFile >> arrayM[i];
        }

     
        int firstElementN = arrayN[0];
        for (int i = 0; i < n - 1; ++i) {
            arrayN[i] = arrayN[i + 1];
        }
        arrayN[n - 1] = firstElementN;

     
        int lastElementM = arrayM[m - 1];
        for (int i = m - 1; i > 0; --i) {
            arrayM[i] = arrayM[i - 1];
        }
        arrayM[0] = lastElementM;

        outputFile << m << "\n";
        for (int i = m - 1; i >= 0; --i) {
            outputFile << arrayM[i] << " ";
        }

        outputFile << "\n" << n << "\n";
        for (int i = 0; i < n - 1; ++i) {
            outputFile << arrayN[i] << " ";
        }
        outputFile << arrayN[n - 1];

        delete[] arrayN;
        delete[] arrayM;

        inputFile.close();
        outputFile.close();
    }
    else {
        std::cout << "Miskate";
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

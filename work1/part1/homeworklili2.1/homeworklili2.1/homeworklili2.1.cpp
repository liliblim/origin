// homeworklili2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <fstream>

int main() {
    std::ifstream inFile("in.txt");

    int N, M;
    inFile >> N;

    int* arrayN = new int[N];
    for (int i = 0; i < N; ++i) {
        inFile >> arrayN[i];
    }

    inFile >> M;

    int* arrayM = new int[M];
    for (int i = 0; i < M; ++i) {
        inFile >> arrayM[i];
    }

    inFile.close();

    std::ofstream outFile("out.txt");

    outFile << M << std::endl;
    for (int i = 0; i < M; ++i) {
        if (i != M - 1) {
            outFile << arrayM[i + 1] << " ";
        }
        else {
            outFile << arrayM[0];
        }
    }
    outFile << std::endl;

    outFile << N << std::endl;
    for (int i = 0; i < N - 1; ++i) {
        outFile << arrayN[i + 1] << " ";
    }
    outFile << arrayN[0];

    outFile.close();

    delete[] arrayN;
    delete[] arrayM;

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

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
   
    Address() : houseNumber(0), apartmentNumber(0) {}

    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

  
    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }

    const std::string& getCity() const {
        return city;
    }
};

void bubbleSortAddresses(Address* addresses, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (addresses[j].getCity() > addresses[j + 1].getCity()) {
                
                Address temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::ifstream inputFile("C:\\Users\\ПК\Desktop\\lilihomework\\work4.2\\lilihomework4.2\\in.txt");
    std::ofstream outputFile("C:\\Users\\ПК\Desktop\\lilihomework\\work4.2\\lilihomework4.2\\out.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл in.txt." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Не удалось открыть файл out.txt." << std::endl;
        inputFile.close();
        return 1;
    }
    int N;
    inputFile >> N;
    Address* addresses = new Address[N];

    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;
        inputFile >> city >> street >> houseNumber >> apartmentNumber;
        addresses[i] = Address(city, street, houseNumber, apartmentNumber);
    }
    bubbleSortAddresses(addresses, N);

    outputFile << N << std::endl;
    for (int i = 0; i < N; ++i) {
        outputFile << addresses[i].getOutputAddress() << std::endl;
    }
    delete[] addresses;

    inputFile.close();
    outputFile.close();

    std::cout << "Данные успешно обработаны и записаны в файл out.txt." << std::endl;

    return 0;
}

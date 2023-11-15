#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }
};

int main() {
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

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

    std::vector<Address*> addresses;

    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        inputFile >> city >> street >> houseNumber >> apartmentNumber;

        addresses.push_back(new Address(city, street, houseNumber, apartmentNumber));
    }

    outputFile << N << std::endl;

    for (int i = N - 1; i >= 0; --i) {
        outputFile << addresses[i]->getOutputAddress() << std::endl;
        delete addresses[i];  

    inputFile.close();
    outputFile.close();

    std::cout << "Данные успешно обработаны и записаны в файл out.txt." << std::endl;

    return 0;
}

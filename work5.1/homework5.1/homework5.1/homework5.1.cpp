#include <iostream>
#include <string>
#include <Windows.h>

class Figure {
protected:
    int sides_count;
    std::string name;

public:
    Figure(int sides) : sides_count(sides) {}

    int get_sides_count() const {
        return sides_count;
    }

    std::string get_name() const {
        return name;
    }
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) {
        name = "Треугольник";
    }
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4) {
        name = "Четырёхугольник";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Figure figure(0);
    Triangle triangle;
    Quadrangle quadrangle;

    std::cout << "Количество сторон:" << std::endl;
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
    std::cout << triangle.get_name() << ": " << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << std::endl;

    return 0;
}

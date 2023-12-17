#include <iostream>
#include <cmath>
#include <Windows.h>

class Figure {
public:
    virtual void print_info() const {
        std::cout << "Фигура:" << std::endl;
        std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << sides << std::endl;
    }

    virtual bool check() const {
        // Проверка общих условий для фигуры (количество сторон)
        return sides == 0;
    }

protected:
    int sides = 0;  // Общее количество сторон у всех фигур
};

class Triangle : public Figure {
public:
    Triangle(double side1, double side2, double side3)
        : a(side1), b(side2), c(side3) {
        sides = 3;
        A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / 3.14159265358979323846;
        B = acos((c * c + a * a - b * b) / (2 * c * a)) * 180.0 / 3.14159265358979323846;
        C = 180 - A - B;
    }

    Triangle(double side1, double side2, bool isRightTriangle)
        : a(side1), b(side2) {
        sides = 3;
        A = atan2(side2, side1) * 180.0 / 3.14159265358979323846;
        B = 90;
        C = 180 - A - B;
    }

    Triangle(double side)
        : a(side), b(side), c(side) {
        sides = 3;
        A = 60;
        B = 60;
        C = 60;
    }

    void print_info() const override {
        std::cout << "Треугольник:" << std::endl;
        std::cout << (check() ? "Правильный" : "Неправильный") << std::endl;
        std::cout << "Количество сторон: " << sides << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }

    bool check() const override {
        // Проверка суммы углов в треугольнике
        return Figure::check() && A + B + C == 180;
    }

private:
    double a, b, c;  // Длины сторон
    double A, B, C;  // Углы
};

class Quadrangle : public Figure {
public:
    Quadrangle(double side1, double side2, double side3, double side4)
        : a(side1), b(side2), c(side3), d(side4) {
        sides = 4;
        A = 90;
        B = 90;
        C = 90;
        D = 90;
    }

    Quadrangle(double base1, double height1, double base2, double height2, bool isRectangle = false)
        : a(base1), b(height1), c(base2), d(height2) {
        if (isRectangle) {
            A = 90;
            B = 90;
            C = 90;
            D = 90;
        }
        else {
            A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / 3.14159265358979323846;
            B = acos((c * c + d * d - b * b) / (2 * c * d)) * 180.0 / 3.14159265358979323846;
            C = acos((d * d + a * a - c * c) / (2 * d * a)) * 180.0 / 3.14159265358979323846;
            D = 180 - A - B - C;
        }
    }

    void print_info() const override {
        std::cout << "Четырёхугольник:" << std::endl;
        std::cout << (check() ? "Правильный" : "Неправильный") << std::endl;
        std::cout << "Количество сторон: " << sides << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }

    bool check() const override {
        // Проверка суммы углов в четырёхугольнике
        return Figure::check() && A + B + C + D == 360;
    }

private:
    double a, b, c, d;  // Длины сторон
    double A, B, C, D;  // Углы
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Triangle triangle(10, 20, 30);
    Triangle rightTriangle(10, 20, true);
    Triangle isoscelesTriangle(10, 20, 50);
    Triangle equilateralTriangle(30);
    Quadrangle quadrangle(10, 20, 30, 40);

    triangle.print_info();
    std::cout << std::endl;

    rightTriangle.print_info();
    std::cout << std::endl;

    isoscelesTriangle.print_info();
    std::cout << std::endl;

    equilateralTriangle.print_info();
    std::cout << std::endl;

    quadrangle.print_info();

    return 0;
}


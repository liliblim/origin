#include <iostream>
#include <cmath>
#include <Windows.h>

class Figure {
public:
    virtual void print_info() const = 0;
};

class Triangle : public Figure {
protected:
    double a, b, c;  // Стороны треугольника
    double A, B, C;  // Углы треугольника

public:
    // Конструктор для произвольного треугольника
    Triangle(double side_a, double side_b, double side_c)
        : a(side_a), b(side_b), c(side_c) {
        A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / 3.14159265358979323846;
        B = acos((c * c + a * a - b * b) / (2 * a * c)) * 180.0 / 3.14159265358979323846;
        C = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / 3.14159265358979323846;
    }

    // Конструктор для прямоугольного треугольника
    Triangle(double base, double legs)
        : a(base), b(legs), c(sqrt(base* base + legs * legs)),
        A(acos(base / c) * 180.0 / 3.14159265358979323846), B(90), C(acos(legs / c) * 180.0 / 3.14159265358979323846) {}

    // Конструктор для равнобедренного треугольника
    Triangle(double base, double legs, double angle_C)
        : a(base), b(legs), c(legs),
        A(acos((b* b + c * c - a * a) / (2 * b * c)) * 180.0 / 3.14159265358979323846),
        B(acos((a* a + c * c - b * b) / (2 * a * c)) * 180.0 / 3.14159265358979323846),
        C(angle_C) {}

    // Конструктор для равностороннего треугольника
    Triangle(double side)
        : a(side), b(side), c(side), A(60), B(60), C(60) {}

    void print_info() const override {
        std::cout << "Треугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

class Quadrangle : public Figure {
protected:
    double a, b, c, d;  // Стороны четырёхугольника
    double A, B, C, D;  // Углы четырёхугольника

public:
    // Конструктор для произвольного четырёхугольника
    Quadrangle(double side_a, double side_b, double side_c, double side_d)
        : a(side_a), b(side_b), c(side_c), d(side_d) {
        A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / 3.14159265358979323846;
        B = acos((c * c + d * d - b * b) / (2 * c * d)) * 180.0 / 3.14159265358979323846;
        C = acos((d * d + a * a - c * c) / (2 * d * a)) * 180.0 / 3.14159265358979323846;
        D = acos((a * a + b * b - d * d) / (2 * a * b)) * 180.0 / 3.14159265358979323846;
    }

    void print_info() const override {
        std::cout << "Четырёхугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Triangle triangle(10, 20, 30);
    Triangle right_triangle(10, 20);
    Triangle isosceles_triangle(10, 20, 50);
    Triangle equilateral_triangle(30);

    Quadrangle quadrangle(10, 20, 30, 40);

    triangle.print_info();
    right_triangle.print_info();
    isosceles_triangle.print_info();
    equilateral_triangle.print_info();
    quadrangle.print_info();

    return 0;
}

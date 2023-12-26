#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif


class Figure {
public:
    virtual void print_info() const = 0;
};

class Triangle : public Figure {
protected:
    double a, b, c;  // Стороны треугольника
    double A, B, C;  // Углы треугольника

public:
    Triangle(double side_a, double side_b, double side_c, double angle_A, double angle_B, double angle_C)
        : a(side_a), b(side_b), c(side_c), A(angle_A), B(angle_B), C(angle_C) {
        if (a <= 0 || b <= 0 || c <= 0 || A <= 0 || B <= 0 || C <= 0 || A + B + C != 180) {
            throw std::invalid_argument("Invalid triangle parameters");
        }
    }

    void print_info() const override {
        std::cout << "Треугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double base, double legs)
        : Triangle(base, legs, sqrt(base* base + legs * legs), acos(base / sqrt(base * base + legs * legs)) * 180.0 / M_PI,
            acos(legs / sqrt(base * base + legs * legs)) * 180.0 / M_PI, 90) {}

    void print_info() const override {
        std::cout << "Прямоугольный треугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double base, double legs, double angle_C)
        : Triangle(base, legs, legs, asin(legs* sin(angle_C* M_PI / 180.0) / base) * 180.0 / M_PI, 180 - angle_C, angle_C) {}

    void print_info() const override {
        std::cout << "Равнобедренный треугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {}

    void print_info() const override {
        std::cout << "Равносторонний треугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

class Quadrangle : public Figure {
protected:
    double a, b, c, d;  // Стороны четырёхугольника
    double A, B, C, D;  // Углы четырёхугольника

public:
    Quadrangle(double side_a, double side_b, double side_c, double side_d)
        : a(side_a), b(side_b), c(side_c), d(side_d), A(0), B(0), C(0), D(0) {
        if (a <= 0 || b <= 0 || c <= 0 || d <= 0 || A + B + C + D != 360) {
            throw std::invalid_argument("Invalid quadrangle parameters");
        }
    }

    void print_info() const override {
        std::cout << "Четырёхугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

// Добавьте оставшиеся классы для прямоугольника, квадрата, параллелограмма, ромба

int main() {
    try {
        Triangle triangle(10, 20, 30, 50, 60, 70);
        RightTriangle right_triangle(10, 20);
        IsoscelesTriangle isosceles_triangle(10, 20, 50);
        EquilateralTriangle equilateral_triangle(30);

        triangle.print_info();
        right_triangle.print_info();
        isosceles_triangle.print_info();
        equilateral_triangle.print_info();

        Quadrangle quadrangle(10, 20, 30, 40);
        // Создайте объекты оставшихся классов и выведите информацию о них

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

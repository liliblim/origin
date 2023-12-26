#include <iostream>
#include <cmath>

class Figure {
protected:
    std::string name;

public:
    Figure(const std::string& figureName) : name(figureName) {}

    virtual void print_info() const {
        std::cout << name << ":" << std::endl;
        std::cout << "Стороны: ";
    }
};

class Triangle : public Figure {
protected:
    double a, b, c;  // Стороны треугольника

public:
    Triangle(const std::string& figureName, double side_a, double side_b, double side_c)
        : Figure(figureName), a(side_a), b(side_b), c(side_c) {}

    void print_info() const override {
        Figure::print_info();
        std::cout << "a=" << a << " b=" << b << " c=" << c << std::endl;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double base, double legs)
        : Triangle("Прямоугольный треугольник", base, legs, sqrt(base* base + legs * legs)) {}
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double base, double legs, double angle_C)
        : Triangle("Равнобедренный треугольник", base, legs, legs) {}
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side)
        : Triangle("Равносторонний треугольник", side, side, side) {}
};

class Quadrangle : public Figure {
protected:
    double a, b, c, d;  // Стороны четырёхугольника

public:
    Quadrangle(const std::string& figureName, double side_a, double side_b, double side_c, double side_d)
        : Figure(figureName), a(side_a), b(side_b), c(side_c), d(side_d) {}

    void print_info() const override {
        Figure::print_info();
        std::cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(double side_a, double side_b)
        : Quadrangle("Прямоугольник", side_a, side_b, side_a, side_b) {}
};

class Square : public Rectangle, public EquilateralTriangle {
public:
    Square(double side)
        : Rectangle(side, side), EquilateralTriangle(side) {}

    void print_info() const override {
        Rectangle::print_info();
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(double side_a, double side_b, double angle)
        : Quadrangle("Параллелограмм", side_a, side_b, side_a, side_b) {}
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double side, double angle)
        : Parallelogram(side, side, angle) {}
};

int main() {
    Triangle triangle("Треугольник", 10, 20, 30);
    RightTriangle rightTriangle(10, 20);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50);
    EquilateralTriangle equilateralTriangle(30);
    Quadrangle quadrangle("Четырёхугольник", 10, 20, 30, 40);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 40);
    Rhombus rhombus(30, 40);

    triangle.print_info();
    rightTriangle.print_info();
    isoscelesTriangle.print_info();
    equilateralTriangle.print_info();
    quadrangle.print_info();
    rectangle.print_info();
    square.print_info();
    parallelogram.print_info();
    rhombus.print_info();

    return 0;
}

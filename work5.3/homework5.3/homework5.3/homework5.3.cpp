#include <iostream>
#include <cmath>
#include <vector>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
class Figure {
public:
    virtual void print_info() const {
        std::cout << "Фигура:\n"
            << (check() ? "Правильная" : "Неправильная") << "\n"
            << "Количество сторон: " << sides.size() << "\n";
    }

    virtual bool check() const {
        return sides.size() > 0; // Проверка наличия сторон
    }

protected:
    std::vector<double> sides;
};

class Triangle : public Figure {
public:
    Triangle(double side_a, double side_b, double side_c) {
        sides = { side_a, side_b, side_c };
        calculateAngles();
    }

    void print_info() const override {
        std::cout << "Треугольник:\n";
        Figure::print_info();
        if (check()) {
            std::cout << "Стороны: a=" << sides[0] << " b=" << sides[1] << " c=" << sides[2] << "\n"
                << "Углы: A=" << angles[0] << " B=" << angles[1] << " C=" << angles[2] << "\n";
        }
    }

    bool check() const override {
        if (Figure::check() && sides.size() == 3) {
            // Проверка наличия трех сторон
            return angles[0] + angles[1] + angles[2] == 180.0; // Проверка суммы углов в треугольнике
        }
        return false;
    }

private:
    std::vector<double> angles;

    void calculateAngles() {
        angles.resize(3);
        for (size_t i = 0; i < 3; ++i) {
            angles[i] = acos((sides[(i + 1) % 3] * sides[(i + 1) % 3] +
                sides[(i + 2) % 3] * sides[(i + 2) % 3] -
                sides[i] * sides[i]) / (2 * sides[(i + 1) % 3] * sides[(i + 2) % 3])) * 180.0 / M_PI;
        }
    }
};

class Rectangle : public Figure {
public:
    Rectangle(double side_a, double side_b) {
        sides = { side_a, side_b, side_a, side_b };
    }

    void print_info() const override {
        std::cout << "Прямоугольник:\n";
        Figure::print_info();
        if (check()) {
            std::cout << "Стороны: a=" << sides[0] << " b=" << sides[1] << " c=" << sides[2] << " d=" << sides[3] << "\n";
        }
    }

    bool check() const override {
        if (Figure::check() && sides.size() == 4) {
            // Проверка наличия четырех сторон
            return sides[0] == sides[2] && sides[1] == sides[3]; // Проверка равенства сторон
        }
        return false;
    }
};

// Добавьте аналогичные классы для других фигур

int main() {
    std::vector<Figure*> figures;

    figures.push_back(new Figure());
    figures.push_back(new Triangle(10, 20, 30));
    figures.push_back(new Rectangle(10, 20));
    // Добавьте создание экземпляров других фигур

    for (const auto& figure : figures) {
        figure->print_info();
        std::cout << "\n";
    }

    // Освобождение памяти
    for (const auto& figure : figures) {
        delete figure;
    }

    return 0;
}

/*
1. Задача: Фигуры (наследование, виртуальные методы)

Описание:
Создать иерархию классов для геометрических фигур. Каждая фигура должна уметь вычислять свою площадь.

Структура классов:
1. Абстрактный класс Shape (Фигура)
  •  Виртуальный метод area()

2. Наследники: Rectangle, Circle, Triangle
  •  Реализуют area() по-своему.

Входные данные:
Создать прямоугольник (3x4), круг (r=5), треугольник (a=3, b=4, c=5).

Выходные данные:
Площадь прямоугольника: 12
Площадь круга: 78.5
Площадь треугольника: 6
*/

#include <iostream>

using namespace std;

//Абстрактный класс Shape (Фигура)
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape(){}
};

//Наследники: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double area() const override {
        return width * height;
    }
};

//Наследники: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return 3.14 * radius * radius;
    }
};

//Наследники: Triangle
class Triangle : public Shape {
private:
    double a;
    double b;
    double c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double area() const override {
        double s = (a + b + c) / 2; //полупериметр
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main()
{
    setlocale(LC_ALL, "RU");

    Rectangle rect(3, 4);
    Circle circle(5);
    Triangle triangle(3, 4, 5);

    cout << "Площадь прямоугольника: " << rect.area() << endl;
    cout << "Площадь круга: " << circle.area() << endl;
    cout << "Площадь треугольника: " << triangle.area() << endl;

    return 0;
}

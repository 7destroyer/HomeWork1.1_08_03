/*
1. ������: ������ (������������, ����������� ������)

��������:
������� �������� ������� ��� �������������� �����. ������ ������ ������ ����� ��������� ���� �������.

��������� �������:
1. ����������� ����� Shape (������)
  �  ����������� ����� area()

2. ����������: Rectangle, Circle, Triangle
  �  ��������� area() ��-������.

������� ������:
������� ������������� (3x4), ���� (r=5), ����������� (a=3, b=4, c=5).

�������� ������:
������� ��������������: 12
������� �����: 78.5
������� ������������: 6
*/

#include <iostream>

using namespace std;

//����������� ����� Shape (������)
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape(){}
};

//����������: Rectangle
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

//����������: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return 3.14 * radius * radius;
    }
};

//����������: Triangle
class Triangle : public Shape {
private:
    double a;
    double b;
    double c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    double area() const override {
        double s = (a + b + c) / 2; //������������
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main()
{
    setlocale(LC_ALL, "RU");

    Rectangle rect(3, 4);
    Circle circle(5);
    Triangle triangle(3, 4, 5);

    cout << "������� ��������������: " << rect.area() << endl;
    cout << "������� �����: " << circle.area() << endl;
    cout << "������� ������������: " << triangle.area() << endl;

    return 0;
}

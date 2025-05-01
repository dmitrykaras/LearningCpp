#include "trapezoid.h"
#include <iostream>

using namespace std;

trapezoid::trapezoid() : x1(0), y1(0), x2(0), y2(0), base1(0), base2(0) {}; //по умолчению
trapezoid::trapezoid(double x1_, double y1_, double x2_, double y2_, double b1_, double b2_) : x1(x1_), y1(y2_), x2(x2_), y2(y2_), base1(b1_), base2(b2_) {}; // с параметрами
trapezoid::trapezoid(const trapezoid& t) = default; //копирования
trapezoid::~trapezoid() {} //деструктор

//сеттеры (с встроенными функциями членами)
void trapezoid::setX1(double val) { x1 = val; }
void trapezoid::setY1(double val) { y1 = val; }
void trapezoid::setX2(double val) { x2 = val; }
void trapezoid::setY2(double val) { y2 = val; }
void trapezoid::setBase1(double val) { base1 = val; }
void trapezoid::setBase2(double val) { base2 = val; }

//геттеры (с встроенными функциями членами)
double trapezoid::getX1() const { return x1; }
double trapezoid::getY1() const { return y1; }
double trapezoid::getX2() const { return x2; }
double trapezoid::getY2() const { return y2; }
double trapezoid::getBase1() const { return base1; }
double trapezoid::getBase2() const { return base2; }

//функция перемещения трапеции
void trapezoid::move(double dx, double dy) {
    x1 += dx; y1 += dy;
    x2 += dx; y2 += dy;
}

//функция вывода значений
void trapezoid::printVertices() const {
    cout << "Вершины:\n";
    cout << "(" << x1 << ", " << y1 << ")\n";
    cout << "(" << x2 << ", " << y2 << ")\n";
    cout << "(" << x2 + base2 << ", " << y2 << ")\n";
    cout << "(" << x1 + base1 << ", " << y1 << ")\n";
    cout << "\n";
}

//перегрузка операторов 
trapezoid trapezoid::operator+(const trapezoid& t) const {
    return trapezoid(x1 + t.x1, y1 + t.y1, x2 + t.x2, y2 + t.y2, base1 + t.base1, base2 + t.base2);
}

trapezoid trapezoid::operator-(const trapezoid& t) const {
    return trapezoid(x1 - t.x1, y1 - t.y1, x2 - t.x2, y2 - t.y2, base1 - t.base1, base2 - t.base2);
}

std::istream& operator>>(std::istream& in, trapezoid& t) {
    in >> t.x1 >> t.y1 >> t.x2 >> t.y2 >> t.base1 >> t.base2;
    cout << "\n";
    return in;
}

std::ostream& operator<<(std::ostream& out, const trapezoid& t) {
    out << "вершины: (" << t.x1 << ", " << t.y1 << "), (" << t.x2 << ", " << t.y2
        << "), нижнее основание: " << t.base1 << ", верхнее основание: " << t.base2;
    return out;
}

//четырёхугольник
#include "CQuad.h"
#include <cmath>

CQuad::CQuad() : CPolygon() {}

CQuad::CQuad(const int* x_vals, const int* y_vals) : CPolygon(x_vals, y_vals) {}

CQuad::CQuad(const CQuad& other) : CPolygon(other) {}

CQuad::~CQuad() {}

double CQuad::length(int i) const { //вычисление длины стороны между вершинами i и (i+1)%3
    int j = (i + 1) % 4;
    double dx = x[j] - x[i];
    double dy = y[j] - y[i];
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

double CQuad::perimeter() const { //периметр 
    return length(0) + length(1) + length(2) + length(3);
}

void CQuad::display() const { //вывод вершин
    cout << "Четырёхугольник:\n";
    for (int i = 0; i < 4; ++i)
        cout << " Вершина " << i + 1 << ": (" << x[i] << ", " << y[i] << ")\n";
    cout << "\n";
}

const char* CQuad::type() const { //вывод типа объекта
    return "Четырёхугольник";
}
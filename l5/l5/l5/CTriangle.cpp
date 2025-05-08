//�����������
#include "CTriangle.h"
#include <cmath>

CTriangle::CTriangle() : CPolygon() {}

CTriangle::CTriangle(const int* x_vals, const int* y_vals) : CPolygon(x_vals, y_vals) {}

CTriangle::CTriangle(const CTriangle& other) : CPolygon(other) {}

CTriangle::~CTriangle() {}

double CTriangle::length(int i) const { //���������� ����� ������� ����� ��������� i � (i+1)%3
    int j = (i + 1) % 3;
    double dx = x[j] - x[i];
    double dy = y[j] - y[i];
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

double CTriangle::perimeter() const { //�������� 
    return length(0) + length(1) + length(2);
}

void CTriangle::display() const { //����� ������
    cout << "�����������:\n";
    for (int i = 0; i < 3; ++i)
        cout << " ������� " << i + 1 << ": (" << x[i] << ", " << y[i] << ")\n";
    cout << "\n";
}

const char* CTriangle::type() const { //����� ���� �������
    return "�����������";
}
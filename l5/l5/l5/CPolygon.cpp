//����������� �����
#include "CPolygon.h"

CPolygon::CPolygon() { //����������� �� ��������� (��������� ������ ��� ��������)
    for (int i = 0; i < 4; ++i) x[i] = y[i] = 0;
}

CPolygon::CPolygon(const int* x_vals, const int* y_vals) { //����������� � ����������� 
    for (int i = 0; i < 4; ++i) {
        x[i] = x_vals[i];
        y[i] = y_vals[i];
    }
}

CPolygon::CPolygon(const CPolygon& other) { //����������� ����������
    for (int i = 0; i < 4; ++i) {
        x[i] = other.x[i];
        y[i] = other.y[i];
    }
}

CPolygon::~CPolygon() {} //����������
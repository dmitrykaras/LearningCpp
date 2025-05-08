//�����������
#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include "CPolygon.h"

#include <iostream>

using namespace std;

class CTriangle : public CPolygon {
private:
	double length(int i) const;
public:
	CTriangle();
	CTriangle(const int* x, const int* y);
	CTriangle(const CTriangle& other);
	~CTriangle(); //����� ��� ���������� ������� - �������� �����

	double perimeter() const override;
	void display() const override;
	const char* type() const override;
};
#endif

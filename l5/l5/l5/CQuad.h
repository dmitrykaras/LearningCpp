//Четырёхугольник
#ifndef CQUAD_H
#define CQUAD_H
#include "CPolygon.h"

#include <iostream>

using namespace std;

class CQuad : public CPolygon {
private:
	double length(int i) const;
public:
	CQuad();
	CQuad(const int* x, const int* y);
	CQuad(const CQuad& other);
	~CQuad(); //здесь уже деструктор обычный - дочерний класс

	double perimeter() const override;
	void display() const override;
	const char* type() const override;
};
#endif
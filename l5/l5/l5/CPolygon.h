//абстрактный класс
#ifndef CPOLYGON_H
#define CPOLYGON_H

#include <iostream>

using namespace std;

class CPolygon {
protected:
	int x[4], y[4]; //может быть максимально 4 вершины
public:
	CPolygon(); //по умолчанию
	CPolygon(const int* x, const int* y); //с параметрами
	CPolygon(const CPolygon& other); //копирования
	virtual ~CPolygon(); //виртуальный диструктор нужен для использования полиморфизма 

	virtual double perimeter() const = 0; //вычисление периметра
	virtual void display() const = 0; //вывод вершин
	virtual const char* type() const = 0; //вывод типа объекта
};
#endif
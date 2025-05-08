//����������� �����
#ifndef CPOLYGON_H
#define CPOLYGON_H

#include <iostream>

using namespace std;

class CPolygon {
protected:
	int x[4], y[4]; //����� ���� ����������� 4 �������
public:
	CPolygon(); //�� ���������
	CPolygon(const int* x, const int* y); //� �����������
	CPolygon(const CPolygon& other); //�����������
	virtual ~CPolygon(); //����������� ���������� ����� ��� ������������� ������������ 

	virtual double perimeter() const = 0; //���������� ���������
	virtual void display() const = 0; //����� ������
	virtual const char* type() const = 0; //����� ���� �������
};
#endif
#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <iostream>

//����� ��������
class trapezoid {
private:
	double x1, y1;
	double x2, y2;
	double base1, base2;

public:
	//������������
	trapezoid(); //�� ���������
	trapezoid(double x1_, double y1_, double x2_, double y2_, double b1_, double b2_); //� �����������
	trapezoid(const trapezoid& t); //�����������

	~trapezoid(); //����������

    //�������
    void setX1(double val);
    void setY1(double val);
    void setX2(double val);
    void setY2(double val);
    void setBase1(double val);
    void setBase2(double val);

    //�������
    double getX1() const;
    double getY1() const;
    double getX2() const;
    double getY2() const;
    double getBase1() const;
    double getBase2() const;

    //������� ������� ��������� (move) � ����� �������� (printVertices)
    void move(double dx, double dy);
    void printVertices() const;
    
    //���������� ���������� + � -
    trapezoid operator+(const trapezoid& t) const;
    trapezoid operator-(const trapezoid& t) const;

    //������� �������
    friend std::istream& operator>>(std::istream& in, trapezoid& t);
    friend std::ostream& operator<<(std::ostream& out, const trapezoid& t);
};

#endif  
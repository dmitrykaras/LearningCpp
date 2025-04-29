#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

double simpleFunction(double x) {
	return (1 + cos(x)) / pow(1 + x * x, 1.0 / 3.0);
}

void conditionFunction(double x1, double y1, double x2, double y2) {
	double distanceA = sqrt(x1 * x1 + y1 * y1);
	double distanceB = sqrt(x2 * x2 + y1 * y2);

	if (distanceA < distanceB) {
		cout << "Точка A ближе к началу координат" << endl;
	}
	else if (distanceA > distanceB) {
		cout << "Точка B ближе к началу координат" << endl;
	}
	else {
		cout << "Точка A и B находятся на одинаковом расстоянии от начала коориднат" << endl;
	}
}

int loopFunction(int N) {
	int K = 1;
	while (3 * K <= N) {
		K++;
	}
	return K;
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int choice;
	do {
		cout << "Выберете действие:" << endl;
		cout << "1. Вывести значение функции y(x)" << endl;
		cout << "2. Определить, какая из точек ближе к началу координат" << endl;
		cout << "3. Найти наименьшее K, при котором 3K > N" << endl;
		cout << "4. Выход" << endl;
		cout << "Ваш выбор:" << endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			double x;
			cout << "Введите значение x: ";
			cin >> x;
			cout << "y(x) = " << simpleFunction(x) << endl;
			break;
		}
		case 2: {
			double x1, y1, x2, y2;
			cout << "Введите координаты точки A (x1, y1): ";
			cin >> x1 >> y1;
			cout << "Введите координаты точки B (x2, y2): ";
			cin >> x2 >> y2;
			conditionFunction(x1, y1, x2, y2);
			break;
		}
		case 3: {
			int N;
			cout << "Введите целое число N (>1): ";
			cin >> N;
			if (N <= 1) {
				cout << "N должно быть больше 1." << endl;
			}
			else {
				int K = loopFunction(N);
				cout << "Наименьшее K, при котором 3K > N: " << K << endl;
			}
			break;
		}
		case 4: {
			cout << "Выход из программы." << endl;
			break;
		}
		default: {
			cout << "Неверный выбор. Попробуйте снова." << endl;
			break;
		}
		}
	} while (choice != 4);
	return 0;
}
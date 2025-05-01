#include "trapezoid.h"
#include <iostream>
#include <windows.h>

using namespace std;	

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	trapezoid t1, t2(5, 4, 3, 1, 8, 9); //c параметрами 
	trapezoid* tPtr = new trapezoid(t2); //копирования

	int choice;
	bool running = true;

	while (running) {
		cout << "Меню:" << endl;
		cout << "1. Создание и вывод состояния объекта авторского класса" << endl;
		cout << "2. Изменение значения члена-данного" << endl;
		cout << "3. Применение уникального метода класса" << endl;
		cout << "4. Применение арифметических и операторов отношений к объектам класса" << endl;
		cout << "0. Выход" << endl;
		cout << "Ваш выбор: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "t1: " << t1 << endl;
				t1.printVertices(); //вызов функции через объект t1
				cout << "\nt2: " << *tPtr << endl;
				tPtr->printVertices(); //вызов функции через указатель tPtr
				break;
			case 2: {
				int sub;
				cout << "Что изменить? (1. x1; 2. y1; 3. x2; 4. y2; 5. base1; 6. base2): ";
				cin >> sub; //запись введённого значения
				double val;
				cout << "Новое значение: ";
				cin >> val; //вывод введённого значения
				cout << "\n";
				switch (sub) {
					//измениние того, что выбрали
					case 1: t1.setX1(val); break;
					case 2: t1.setY1(val); break;
					case 3: t1.setX2(val); break;
					case 4: t1.setY2(val); break;
					case 5: t1.setBase1(val); break;
					case 6: t1.setBase2(val); break;
				}
				break;
				}
			case 3: {
				double dx, dy;
				cout << "Введите dx и dy: ";
				cin >> dx >> dy;
				cout << "\n";
				t1.move(dx, dy); //вызов функции move через объект t1
				break;
			}
			case 4: {
				trapezoid sum = t1 + t2;
				trapezoid diff = t1 - t2;
				cout << "Сумма: " << sum << endl;
				cout << "Разность: " << diff << endl;
				cout << "\n";
				break;
			}
			case 0:
				running = false;
				break;
			default:
				cout << "Неверный выбор.\n\n";
				break;
		}
	}

	delete tPtr;
	return 0;
}
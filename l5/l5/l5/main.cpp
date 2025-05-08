#include "CQuad.h"
#include "CTriangle.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//задаём коориданты 
	int xTri[4] = { 0, 3, 0 };       // только 3 координаты
	int yTri[4] = { 0, 0, 4 };
	int xQuad[4] = { 0, 4, 4, 0 };   // 4 вершины
	int yQuad[4] = { 0, 0, 3, 3 };

	//создаём объекты
	CTriangle triangle(xTri, yTri);
	CQuad quad(xQuad, yQuad);

	//указатель на базовый класс	
	CPolygon* poly = nullptr;

	int choice;
	bool running = true;

	while (running) {
		cout << "Меню: " << endl;
		cout << "1. Просмотр состояния объекта" << endl;
		cout << "2. Вызов виртуальной функции display()" << endl;
		cout << "3. Изменение значения указателя " << endl;
		cout << "4. Вывод периметра" << endl;
		cout << "0. Выход" << endl;
		cout << "Ваш выбор: ";

		cin >> choice;

		switch (choice) {
		case 1:
			if (poly) {
				cout << "Выбран объект: " << poly->type() << endl;  // Выводим тип объекта
				poly->display();  // Выводим состояние объекта
			}
			else {
				cout << "Указатель на объект не установлен \n" << endl;
			}
			break;
		case 2:
			if (poly) {
				poly->display();
			}
			else {
				cout << "Указатель на объект не установлен." << endl;
			}
			break;
		case 3:
			cout << "Выберите объект для изменения указателя:" << endl;
			cout << "1. Треугольник" << endl;
			cout << "2. Четырёхугольник" << endl;
			cout << "Ваш выбор: ";
			int choiceObj;
			cin >> choiceObj;
			switch (choiceObj) {
			case 1:
				poly = &triangle;
				cout << "Указатель теперь указывает на треугольник.\n" << endl;
				break;
			case 2:
				poly = &quad;
				cout << "Указатель теперь указывает на четырёхугольник.\n" << endl;
				break;
			default:
				cout << "Неверный выбор.\n" << endl;
				break;
			}
			break;
		case 4:
			if (poly) {
				cout << "Периметр выбранного объекта: " << poly->perimeter() << endl;  // Выводим периметр
			}
			else {
				cout << "Указатель на объект не установлен.\n" << endl;
			}
			break;
		case 0:
			running = false;
			break;
		default:
			cout << "Неверный выбор\n" << endl;
		}
	}
	return 0;
}
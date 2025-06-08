#include "trapezoid.h"
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<trapezoid> trapezoids;
    int count;

    cout << "Введите количество трапеций: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        trapezoid t;
        cout << "Введите координаты трапеции #" << i + 1 << " (x1 y1 x2 y2 base1 base2): ";
        cin >> t;
        trapezoids.push_back(t);
    }

    int choice;
    bool running = true;

    while (running) {
        cout << "Меню:" << endl;
        cout << "1. Вывести все трапеции" << endl;
        cout << "2. Переместить все трапеции" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (size_t i = 0; i < trapezoids.size(); ++i) {
                cout << "Трапеция #" << i + 1 << ": " << trapezoids[i] << endl;
                trapezoids[i].printVertices();
            }
            break;

        case 2: {
            double dx, dy;
            cout << "Введите dx и dy: ";
            cin >> dx >> dy;
            for (auto& t : trapezoids) {
                t.move(dx, dy);
            }
            cout << "Трапеции перемещены.\n";
            break;
        }

        case 0:
            running = false;
            break;

        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    }

    return 0;
}

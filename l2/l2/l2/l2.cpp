#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <windows.h>

using namespace std;

//функция меняет местами чётные и нечётные символы строки
void swapString(char* ptr) {
    while (*ptr && *(ptr + 1)) {
        char temp = *ptr;
        *ptr = *(ptr + 1);
        *(ptr + 1) = temp;
        ptr += 2;
    }
}

//проверка, является ли символ знаком пунктуации
bool isPunct(char c) {
    return ispunct(c);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char tmp[80];

    while (true) {
        cout << "Введите строку: ";
        cin.getline(tmp, sizeof(tmp));

        if (!isPunct(tmp[0])) {
            break;
        }

        //вычисляем длину строки и выделяем память
        char* dynamicBlock = new char[strlen(tmp) + 1];

        if (!dynamicBlock) {
            cout << "Ошибка выделения памяти!" << endl;
            continue;
        }

        //копируем строку
        strcpy(dynamicBlock, tmp);

        //обрабатываем строку
        swapString(dynamicBlock);

        //выводим результат
        cout << "Результат обработки: " << dynamicBlock << endl;

        //освобождаем память
        delete[] dynamicBlock;
    }

    cout << "Завершение программы..." << endl;
    return 0;
}

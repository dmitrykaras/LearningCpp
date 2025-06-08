#include <iostream>
#include <string>
#include "CArray.h"
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    using namespace std;

    //CArray по умолчанию (int, размер 10)
    CArray<> arr1;
    for (size_t i = 0; i < arr1.size(); ++i)
        arr1[i] = static_cast<int>(i * 2);

     cout << "Массив по умолчанию (int): " << arr1 <<  endl;

    //CArray<float, 5>
    CArray<float, 5> arr2;
    for (size_t i = 0; i < arr2.size(); ++i)
        arr2[i] = i * 1.1f;

     cout << "Массив float: " << arr2 <<  endl;

    //CArray<double, 3>
    CArray<double, 3> arr3;
     cout << "Введите 3 значения типа double: ";
     cin >> arr3;
     cout << "Массив double (введён пользователем): " << arr3 <<  endl;

    //Используем  string вместо char*
    CArray< string, 3> arr4;
     cout << "Введите 3 строки: ";
     cin >> arr4;
     cout << "Массив строк (string): " << arr4 <<  endl;

    return 0;
}

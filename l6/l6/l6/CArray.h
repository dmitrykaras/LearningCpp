#ifndef CARRAY_H
#define CARRAY_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template<typename T = int, size_t N = 10>
class CArray {
private:
    T data[N];

public:
    //конструктор по умолчанию
    CArray();

    //индексация с контролем границ
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    //доступ к размеру массива
    size_t size() const { return N; }

    //перегрузка ввода/вывода
    template<typename U, size_t M>
    friend  ostream& operator<<(ostream&, const CArray<U, M>&);

    template<typename U, size_t M>
    friend  istream& operator>>(istream&, CArray<U, M>&);
};

//определение конструктора
template<typename T, size_t N>
CArray<T, N>::CArray() {
    for (size_t i = 0; i < N; ++i) {
        data[i] = T();
    }
}

//определение оператора индексации
template<typename T, size_t N>
T& CArray<T, N>::operator[](size_t index) {
    if (index >= N) throw out_of_range("Индекс вне диапазона");
    return data[index];
}

template<typename T, size_t N>
const T& CArray<T, N>::operator[](size_t index) const {
    if (index >= N) throw out_of_range("Индекс вне диапазона");
    return data[index];
}

//определение операторов ввода/вывода
template<typename T, size_t N>
ostream& operator<<(ostream& os, const CArray<T, N>& arr) {
    for (size_t i = 0; i < N; ++i)
        os << arr.data[i] << " ";
    return os;
}

template<typename T, size_t N>
istream& operator>>(istream& is, CArray<T, N>& arr) {
    for (size_t i = 0; i < N; ++i)
        is >> arr.data[i];
    return is;
}

//явная специализация для char*
template<size_t N>
class CArray<char*, N> {
private:
    string data[N];

public:
    CArray();

    string& operator[](size_t index);
    const string& operator[](size_t index) const;

    size_t size() const { return N; }

    friend ostream& operator<<(ostream& os, const CArray<char*, N>& arr) {
        for (size_t i = 0; i < N; ++i)
            os << arr.data[i] << " ";
        return os;
    }

    friend istream& operator>>(istream& is, CArray<char*, N>& arr) {
        for (size_t i = 0; i < N; ++i)
            is >> arr.data[i];
        return is;
    }
};

template<size_t N>
CArray<char*, N>::CArray() {
    for (size_t i = 0; i < N; ++i)
        data[i] = "";
}

template<size_t N>
string& CArray<char*, N>::operator[](size_t index) {
    if (index >= N) throw out_of_range("Индекс вне диапазона");
    return data[index];
}

template<size_t N>
const string& CArray<char*, N>::operator[](size_t index) const {
    if (index >= N) throw out_of_range("Индекс вне диапазона");
    return data[index];
}

#endif // CARRAY_H
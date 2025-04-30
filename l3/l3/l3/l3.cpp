#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//структура содержащая информацию о стуентах и книгах
struct CARD {
	string surname;
	string name;
	int reader_num;
	int book_count;
};

//функция для сортировки четательского билета по возростанию
bool reader_num_sort(const CARD& a, const CARD& b) {
	return a.reader_num < b.reader_num;
}

//функция для сортировки пол кол-ву книг
bool book_count_sort(const CARD& card, int N) {
	return card.book_count >= N;
}

//функция чтения данных из файла в вектор стрктур
void readFromFile(const string& filename, vector<CARD>& cards) {
	ifstream file(filename);
	if (!file) {
		cout << "Ошибка открытия файла: " << filename << endl;
		return;
	}
	CARD temp;
	while (file >> temp.surname >> temp.name >> temp.reader_num >> temp.book_count) {
		cards.push_back(temp); //добавление temp в конец вектора
	}
	file.close();
}

//функция для записи данных из вектора в файл
void writeToFile(const string& filename, const vector<CARD>& cards) {
	ofstream file(filename);
	if (!file) {
		cout << "Ошибка создания файла: " << filename << endl;
		return;
	}
	for (const auto& card : cards) {
		file << card.surname << " " << card.name << " " << card.reader_num << " " << card.book_count << " " << endl;
	}
	file.close();
}

//функция для вывода данных на консоль
void printCard(const vector<CARD>& cards) {
	for (const auto& card : cards) {
		cout << card.surname << " " << card.name << " " << card.reader_num << " " << card.book_count << " " << endl;
	}
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;

	vector<CARD> cards;

	//чтение данных из data.txt
	readFromFile("data.txt", cards);

	//вывод исходных данных
	cout << "Исходные данные: " << endl;
	printCard(cards);

	//сортировка по номеру читательского билета 
	sort(cards.begin(), cards.end(), reader_num_sort);
	cout << "\nОтсортированные данные:" << endl;
	printCard(cards);

	//фильтация, пользователь вводит число книг
	cout << "\nВведите минимальное количество книг для фильтрации: ";
	cin >> N;

	vector<CARD> filteredCards;
	for (const auto& card : cards) {
		if (book_count_sort(card, N)) {
			filteredCards.push_back(card);
		}
	}

	//Выводим отфильтрованные данные
	cout << "\nОтфильтрованные данные:" << endl;
	printCard(filteredCards);
	
	//записываем отсортированные данные в файл data1.txt
	writeToFile("data1.txt", cards);

	return 0;
}


#include <iostream>
#include <math.h>
using namespace std;
short main() {
	setlocale(LC_ALL, "Ukrainian");
	cout << "---------------- Лабораторна №3 ------------" << endl;
	cout << "------ Робота з типами double та short --------" << endl << endl;


	cout << "\n---------------Завдання 1-------------------" << endl << endl;
	double a = 0;
	short b = 0;
	cout << "Введiть дiйсне число: ";
	cin >> a;
	cout << "Введiть цiле число: ";
	cin >> b;


	cout << "\n---------------Завдання 2-------------------" << endl;
	short shortRes = a * b / b - b;
	shortRes -= b;
	double doubleRes = a * b / b - b;
	doubleRes -= b;

	cout << "\nРезультати обчислень збереженi у змiнних \nрiзного типу.";
	cout << "Результати " << ((shortRes == doubleRes) ? "" : "не ") << "спiвпадають!!!";


	//Неявне приведення типiв
	cout << "\n---------------Завдання 3-------------------" << endl;
	short newA = a;
	cout << "\nНеявне перетворення типiв (double в short)\n" << endl;
	cout << "\nЗначення до перетворення:\t" << a << endl;
	cout << "\nЗначення пiсля перетворення:\t" << newA << endl;

	//Явне приведення типiв
	cout << "\n---------------Завдання 4-------------------" << endl;
	double newB = (double)b;
	cout << "\nЯвне перетворення типiв (short в double)\n" << endl;
	cout << "\nЗначення до перетворення:\t" << b << endl;
	cout << "\nЗначення пiсля перетворення:\t" << newB << endl;

	//Операцiї порiвняння
	cout << "\n---------------Завдання 5-------------------" << endl << endl;
	bool compare = false;
	cout << "\nРезультат порiняння" << endl;

	compare = (a > b);
	cout << "\t(a > b) Результат:\t" << compare << endl;

	compare = (a != b);
	cout << "\t(a != b) Результат:\t" << compare << endl;

	//Перевiрка обрiзання значення при приведеннi типiв
	cout << "\n--------------Завдання 6--------------" << endl;
	cout << "\nПри перетвореннi типiв double в short " << endl;
	cout << "обрiзання " << ((newA == a) ? "не" : "") << "вiдбулося" << endl;

	//Визначення к-тi зайнятої пам'ятi
	cout << "\n---------------Завдання 7---------------" << endl << endl;
	cout << "Змiнна а займає " << sizeof(a) << " байти" << endl;
	cout << "Змiнна b займає " << sizeof(b) << " байти" << endl;

	//Виведення адреси
	cout << "\n--------------Завдання 8---------------" << endl << endl;
	cout << "Адреса змiнної а: " << &a << endl;
	cout << "Адреса змiнної b:" << &b << endl;
	system("pause");
	cout << '\a';
	return -0;
}
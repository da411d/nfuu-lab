#define _USE_MATH_DEFINES
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

int rnd(int i, int a) {
	srand(time(0));
	return i + rand() % (a - i + 1);
}
void loading(){
	cout << "|";
	for (int i = 0; i < rnd(3, 7); i++) {
		cout << "\b";
		cout << "/";
		Sleep(40);
		cout << "\b";
		cout << "-";
		Sleep(40);
		cout << "\b";
		cout << "\\";
		Sleep(40);
		cout << "\b";
		cout << "|";
		Sleep(40);
	}
	cout << "\b";
}
int main(){
	setlocale(LC_ALL, "Ukrainian");
	cout << "Загрузка...";
	Sleep(rnd(500, 1500));
	system("cls");
	cout << "Подготавливаем окружение...";
	Sleep(rnd(500, 1500));
	system("cls");
	cout << "Почти готово...";
	Sleep(rnd(500, 1500));
	system("cls");
	
	float x;
	unsigned short t;
	

	cout << "\nПрограма-конвертер" << endl;
	cout << "Оберiть пункт меню:"<<endl;
	cout << "\t1. Знайти синус"<<endl;
	cout << "\t2. Знайти косинус"<<endl;
	cout << "\t3. Знайти тангенс"<<endl;
	cout << "Вибiр зроби свiй ти: ";
	cin >> t;
	cout << "Введiть число: ";
	cin >> x;

	
	system("cls");
	cout << "Викликаєм духи визначних математикiв...";
	loading();
	system("cls");
	cout << "Викликаєм дух Пiфагора...";
	loading();
	system("cls");
	cout << "Викликаєм дух Гаусса...";
	loading();
	system("cls");
	cout << "Викликаєм дух Буля...";
	loading();
	system("cls");
	cout << "Викликаєм дух Жигалкiна...";
	loading();
	system("cls");
	cout << "Викликаєм дух Ейлера...";
	loading();
	system("cls");
	cout << "Викликаєм дух Декарта...";
	loading();
	system("cls");
	cout << "Викликаєм дух Архiмеда...";
	loading();
	system("cls");
	cout << "Викликаєм дух Ферма...";
	loading();
	system("cls");
	
	system("color a");
	switch(t){
	case 1: cout << "sin("<<x<<") = "<<sin(x)<<endl;break;
	case 2: cout << "cos("<<x<<") = "<<cos(x)<<endl;break;
	case 3: cout << "tan("<<x<<") = "<<tan(x)<<endl;break;
	default: cout << '\a';system("color C");cout << "Вибiр неправильний зробив ти!"<<endl;
	}
	
	system("pause");
	return 0;
}
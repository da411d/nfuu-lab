#define _USE_MATH_DEFINES
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <cmath>

using namespace std;

int rnd(int i, int a) {
	srand(time(0));
	return i + rand() % (a - i + 1);
}

int main(){
	setlocale(LC_ALL, "Ukrainian");
	cout << "��������...";
	Sleep(rnd(500, 1500));
	system("cls");
	cout << "�������������� ���������...";
	Sleep(rnd(500, 1500));
	system("cls");
	cout << "����� ������...";
	Sleep(rnd(500, 1500));
	system("cls");

	system("color a");
	cout << "\n---------------- ����������� ������ �4 ----------------" << endl;
	cout << "�������� ��� ���������� ������ � ������� ������� �� ������� [-5, 5]" << endl;
	cout << "--------------------------------------------------------" << endl;

	float x, y;

	cout << "\t������ �������� ���������: \tx = ";
	cin >> x;

	if (x < -5 || x > 5) {
		system("cls");
		system("color C");
		cout << "��������� ���������! �������� x �������� �� ��� ��������� [-5, 5]" << endl;
	} else {
		cout << "|";
		for (int i = 0; i < rnd(5, 10); i++) {
			cout << "\b";
			cout << "/";
			Sleep(50);
			cout << "\b";
			cout << "-";
			Sleep(50);
			cout << "\b";
			cout << "\\";
			Sleep(50);
			cout << "\b";
			cout << "|";
			Sleep(50);
		}
		cout << "\b";
		if (fabs(x) < 2) {
			y = 2*x*x + 3 * sin(M_PI_4*x);
			cout << "���������� ����� �����!";
		}
		else if (2 <= fabs(x) && fabs(x) <= 3) {
			y = 11;
			cout << "���������� ����� �����!";
		}
		else if (3 <= x && x <= 4) {
			y = 17 - 2*x;
			cout << "���������� ����� �����!";
		}
		else if (x>=4) {
			y = 2.5*x;
			cout << "���������� �������� �����!";
		}
		cout << endl << "\t�������� �������: \t\ty = " << y << endl;
	}

	system("pause");
	return 0;
}
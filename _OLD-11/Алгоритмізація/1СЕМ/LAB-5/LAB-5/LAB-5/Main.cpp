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
	cout << "��������...";
	Sleep(rnd(500, 1500));
	system("cls");
	cout << "�������������� ���������...";
	Sleep(rnd(500, 1500));
	system("cls");
	cout << "����� ������...";
	Sleep(rnd(500, 1500));
	system("cls");
	
	float x;
	unsigned short t;
	

	cout << "\n��������-���������" << endl;
	cout << "����i�� ����� ����:"<<endl;
	cout << "\t1. ������ �����"<<endl;
	cout << "\t2. ������ �������"<<endl;
	cout << "\t3. ������ �������"<<endl;
	cout << "���i� ����� ��i� ��: ";
	cin >> t;
	cout << "����i�� �����: ";
	cin >> x;

	
	system("cls");
	cout << "�������� ���� ��������� ���������i�...";
	loading();
	system("cls");
	cout << "�������� ��� �i������...";
	loading();
	system("cls");
	cout << "�������� ��� ������...";
	loading();
	system("cls");
	cout << "�������� ��� ����...";
	loading();
	system("cls");
	cout << "�������� ��� ������i��...";
	loading();
	system("cls");
	cout << "�������� ��� ������...";
	loading();
	system("cls");
	cout << "�������� ��� �������...";
	loading();
	system("cls");
	cout << "�������� ��� ���i����...";
	loading();
	system("cls");
	cout << "�������� ��� �����...";
	loading();
	system("cls");
	
	system("color a");
	switch(t){
	case 1: cout << "sin("<<x<<") = "<<sin(x)<<endl;break;
	case 2: cout << "cos("<<x<<") = "<<cos(x)<<endl;break;
	case 3: cout << "tan("<<x<<") = "<<tan(x)<<endl;break;
	default: cout << '\a';system("color C");cout << "���i� ������������ ������ ��!"<<endl;
	}
	
	system("pause");
	return 0;
}
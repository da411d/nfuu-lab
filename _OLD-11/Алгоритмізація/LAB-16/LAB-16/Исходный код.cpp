#include<iostream>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
/*
	������ �5. ���������� ��������� ����, �� ���������� � ��������� ���
	�������� ���� �����:
	- ����, �����, �� ����������,
	- ���� ����������,
	- ����� (������� �� �����).
	������� �� ���� ������� �������� ������� ����. ���������� ��������� ��������
	� ����� ����.
*/
struct Student{
	char* name[100];
	int birthday;
	char* addr[100];
	int gender;
	void print(ostream& stream){
		stream << *name << " " << birthday << " " << addr << " " << gender << "\r\n";
	}
};

void main() {
	setlocale(LC_ALL, "Ukrainian");
	ifstream infile("text.txt");
	
	char g_name[100], g_addr[100];
	char *g_birthday, *g_gender;
	while (infile >> g_name >> g_birthday >> g_addr >> g_gender){
		Student S = {
			g_name, 
			g_birthday, 
			g_addr, 
			g_gender
		};
		S.print(cout);
	}
	system("pause>>NUL");
}
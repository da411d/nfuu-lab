#include <iostream>
#include <math.h>
using namespace std;
short main() {
	setlocale(LC_ALL, "Ukrainian");
	cout << "---------------- ����������� �3 ------------" << endl;
	cout << "------ ������ � ������ double �� short --------" << endl << endl;


	cout << "\n---------------�������� 1-------------------" << endl << endl;
	double a = 0;
	short b = 0;
	cout << "����i�� �i���� �����: ";
	cin >> a;
	cout << "����i�� �i�� �����: ";
	cin >> b;


	cout << "\n---------------�������� 2-------------------" << endl;
	short shortRes = a * b / b - b;
	shortRes -= b;
	double doubleRes = a * b / b - b;
	doubleRes -= b;

	cout << "\n���������� ��������� ��������i � ��i���� \n�i����� ����.";
	cout << "���������� " << ((shortRes == doubleRes) ? "" : "�� ") << "��i��������!!!";


	//������ ���������� ���i�
	cout << "\n---------------�������� 3-------------------" << endl;
	short newA = a;
	cout << "\n������ ������������ ���i� (double � short)\n" << endl;
	cout << "\n�������� �� ������������:\t" << a << endl;
	cout << "\n�������� �i��� ������������:\t" << newA << endl;

	//���� ���������� ���i�
	cout << "\n---------------�������� 4-------------------" << endl;
	double newB = (double)b;
	cout << "\n���� ������������ ���i� (short � double)\n" << endl;
	cout << "\n�������� �� ������������:\t" << b << endl;
	cout << "\n�������� �i��� ������������:\t" << newB << endl;

	//������i� ���i������
	cout << "\n---------------�������� 5-------------------" << endl << endl;
	bool compare = false;
	cout << "\n��������� ���i�����" << endl;

	compare = (a > b);
	cout << "\t(a > b) ���������:\t" << compare << endl;

	compare = (a != b);
	cout << "\t(a != b) ���������:\t" << compare << endl;

	//�����i��� ���i����� �������� ��� ���������i ���i�
	cout << "\n--------------�������� 6--------------" << endl;
	cout << "\n��� �����������i ���i� double � short " << endl;
	cout << "���i����� " << ((newA == a) ? "��" : "") << "�i�������" << endl;

	//���������� �-�i ������� ���'��i
	cout << "\n---------------�������� 7---------------" << endl << endl;
	cout << "��i��� � ����� " << sizeof(a) << " �����" << endl;
	cout << "��i��� b ����� " << sizeof(b) << " �����" << endl;

	//��������� ������
	cout << "\n--------------�������� 8---------------" << endl << endl;
	cout << "������ ��i��� �: " << &a << endl;
	cout << "������ ��i��� b:" << &b << endl;
	system("pause");
	cout << '\a';
	return -0;
}
#pragma once

#include "BigInt.h"

using namespace std;

class BigIntArray	// ���� ����� ������� �����, �� ������ ����� ��'���� ����� ����ʲ ֲ˲ �����
{
	BigInt* pBigInts;
	int Count;
	unsigned int uiPosition;

public:
	BigIntArray(); //����������� ��� ���������
	BigIntArray(int); //�����������
	void Input(); //����� ��� ����� �����
	void Show(); //����� ��� ��������� �����
	BigInt Sum(); // ���� ��� ������� ����� �����
	~BigIntArray(void);	//����������
	BigInt* GetBigInts(); //������� �������� �� ������� ������
	BigInt* begin(); //���������� �������� �� ������� ������
	BigInt* end(); 	//���������� �������� �� ����� ������
	int GetCount(); // ����� ��� ������� ����  - ������� �������� ������
};


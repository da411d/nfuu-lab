#pragma once

#include "BigInt.h"

using namespace std;

class BigIntArray	// Клас МАСИВ ВЕЛИКИХ ЧИСЕЛ, що містить масив об'єктів класу ВЕЛИКІ ЦІЛІ ЧИСЛА
{
	BigInt* pBigInts;
	int Count;
	unsigned int uiPosition;

public:
	BigIntArray(); //Конструктор без параметрів
	BigIntArray(int); //Конструктор
	void Input(); //Метод для вводу даних
	void Show(); //Метод для виведення даних
	BigInt Sum(); // Сума всіх великих цілих чисел
	~BigIntArray(void);	//Деструктор
	BigInt* GetBigInts(); //Повертає вказівник на елемент масиву
	BigInt* begin(); //Встановлює вказівник на початок масиву
	BigInt* end(); 	//Встановлює вказівник на кінець масиву
	int GetCount(); // Метод для читання поля  - кількість елементів масиву
};


// Task13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <iostream>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <math.h>

#include "String.h"
#include "BigInt.h"
#include "BigIntArray.h"
#include "Function.h"
#include "Error.h"
#include "MyIterator.h"

using namespace std;

long double log2(BigInt x, long double epsilon = 0.000000000000001)
{
	static /* const */ long double O = 0.0;
	if (x.sign <= 0) return O / O;     // Return NaN

	long double y = 0.0, z = 1.0, f = 0.0;
	while (x >= 2)
	{
		if (x.divide(2)) f += 1.0;
		f /= 2.0;
		y++;
	}
	f += 1.0;
	while (z > epsilon)
	{
		f *= f;
		z /= 2.0;
		if (f >= 2.0)
		{
			y += z;
			f /= 2.0;
		}
	}
	return y;
}

inline long double log(BigInt x, long double epsilon = 0.000000000000001)
{
	return log2(x, epsilon) * 0.6931471805599;
}

inline long double log10(BigInt x, long double epsilon = 0.000000000000001)
{
	return log2(x, epsilon) * 0.301029995664;
}

inline long double lg(BigInt x, long double epsilon = 0.000000000000001)
{
	return log2(x, epsilon);
}

inline long double ln(BigInt x, long double epsilon = 0.000000000000001)
{
	return log(x, epsilon);
}

int main(int argc, char* argv[])
{
	try
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int nCount = 1; // кількість елементів масиву
		int input;
		char flag = 'y';
		bool not_found = true;;
		String *p_String, o_String;
		BigInt *p_BigInt, o_BigInt;

		cout << "=========================================== " << endl;
		cout << " Курсова робота ст.гр. КН-2 Кузьмика Андрія " << endl;
		cout << "=========================================== " << endl;

		cout << "Введiть будь-ласка кiлькiсть чисел: ";
		nCount = GetInt(cin);

		BigIntArray bigIntArr(nCount);
		bigIntArr.Input(); // Введення даних
		bigIntArr.Show(); //Виведення даних
		cout << endl;
		cout << "Введення чисел завершено." << endl;
		
		BigInt b = BigInt(12345000);
		BigInt c; c = b;
		BigInt n = 1000;
		BigInt q = 1023;
		BigInt x = 11;
		BigInt rem2 = q.divide(BigInt(2));


		while (flag == 'y' || flag == 'Y') //Організація пунктів меню
		{	
			MyIterator<BigInt> myItr(bigIntArr.GetBigInts(), bigIntArr.GetCount());
			try
			{
				cout << endl << "*** ДІЇ ТА АРИФМЕТИЧНІ ОПЕРАЦІЇ над ВЕЛИКИМИ ЦІЛИМИ ЧИСЛАМИ ***" << endl;
				cout << "1. Додавання ВЕЛИКИХ ЦІДИХ ЧИСЕЛ\n";
				cout << "2. Віднімання ВЕЛИКИХ ЦІЛИХ ЧИСЕЛ\n";
				cout << "3. Множення ВЕЛИКИХ ЦІЛИХ ЧИСЕЛ\n";
				cout << "4. Ділення ВЕЛИКИХ ЦІЛИХ ЧИСЕЛ\n";
				cout << "5. Конкатенація ВЕЛИКИХ ЦІЛИХ ЧИСЕЛ\n";
				cout << "6. Відображення ВЕЛИКИХ ЦІЛИХ ЧИСЕЛ\n";
				cout << "7. Побітові (порозрядні) операції над ВЕЛИКИМИ ЦІЛИМИ ЧИСЛАМИ\n";
				cout << "8. Перебір ВЕЛИКИХ ЦІЛИХ ЧИСЕЛ\n";
				cout << "9. Логарифми з ВЕЛИКИХ ЦІЛИХ ЧИСЕЛ\n";
				cout << "10. Вивід МАСИВУ ВЕЛИКИХ ЧИСЕЛ\n";
				cout << "11. Знайти суму елементів масиву ВЕЛИКИХ ЦІЛИХ ЧИСЕЛ\n";
				cout << "12. Демо механізму пізнього зв'язування МАСИВ ВЕЛИКИХ ЧИСЕЛ = РЯДОК\n";
				cout << "13. Демо механізму пізнього зв'язування МАСИВ ВЕЛИКИХ ЧИСЕЛ = ВЕЛИКЕ ЦІЛЕ ЧИСЛО\n";
				cout << "14. Вихiд\n";
				cout << "Виберiть будь-ласка пункт з меню: ";

				input = GetInt(cin);
				
				switch (input)
				{
					case 1:
					{
						cout << "Constructors and copy constructors:" << endl;
						cout << "12345000 = " << BigInt(12345000) << endl;
						cout << "12345000 = " << b << endl;
						cout << "12345000 = " << c << endl;
						cout << "1234567890 = " << BigInt((long double)1234567890.49999) << endl;
						cout << endl;

						cout << "Додавання:" << endl;
						cout << "123 + 234 = " << (BigInt(123) + 234).toInt() << endl;
						cout << "243 + 999 = " << (BigInt(243) + BigInt(999)) << endl;
						cout << "-123 + -321 = " << (BigInt(-123) + BigInt(-321)) << endl;
						cout << "-123 + 321 = " << (BigInt(-123) + BigInt(321)) << endl;
						cout << "-2 + 5 = " << (BigInt(-2) + 5) << endl;
						cout << "-2 + 5 = " << (BigInt(-2) + BigInt(5)) << endl;
						cout << "-2 + -5 = " << (BigInt(-2) + -5) << endl;
						cout << "-2 + -5 = " << (BigInt(-2) + BigInt(-5)) << endl;
						cout << "0 + -5 = " << (BigInt(0) + -5) << endl;
						cout << "0 + -5 = " << (BigInt(0) + BigInt(-5)) << endl;
						cout << endl;
					}
					break;
					case 2:
					{
						cout << "Віднімання:" << endl;
						cout << "4567 - 1234 = " << (4567 - BigInt(1234)) << endl;
						cout << "345 - 46 = " << (BigInt(345) - BigInt(46)) << endl;
						cout << "2 - 6 = " << (BigInt(2) - BigInt(6)) << endl;
						cout << "2 - 6 = " << (BigInt(2) - 6) << endl;
						cout << "0 - 5 = " << (BigInt(0) - 5) << endl;
						cout << "0 - 5 = " << (BigInt(0) - BigInt(5)) << endl;
						cout << "0 - -5 = " << (BigInt(0) - -5) << endl;
						cout << "0 - -5 = " << (BigInt(0) - BigInt(-5)) << endl;
						cout << "10000 - 10000 = " << (BigInt(10000) - 10000) << endl;
						cout << "10000 - 10110 = " << (BigInt(10000) - 10110) << endl;
						cout << "4567 - 4568 = " << (BigInt(4567) - 4568) << endl;
						cout << "-4567 - -4568 = " << (BigInt(-4567) - BigInt(-4568)) << endl;
						cout << "999 - 9999 = " << (BigInt(999) - 9999) << endl;
						cout << "2000000000 + 2000000000 + 2000123456 = " << (BigInt(2000000000) + 2000000000 + BigInt(2000123456)) << endl;
						cout << "-34567 + 34568 = " << (BigInt(-34567) + BigInt(34568)) << endl;
						cout << "10 - 1 = " << (BigInt(10) - 1) << endl;
						cout << "1 - 10 = " << (BigInt(1) - 10) << endl;
						cout << "Fib( 613 ) + Fib( 614 ) = " << (
						BigInt("57535841731394367586444934959935162731893485882113791734636043664022186311322175066312007025864665068095897804714985049873571833")
						+
						BigInt("93094947492730684688120544687306111880728698574224279139760379700550384193434187688727692133714165658764281830930007773906603177")
						) << endl;
						cout << "1024 * 15.37 = " << BigInt(1024) * 15.37l << endl;
						cout << "100 * 0.5 = " << BigInt(100) * 0.5l << endl;
						cout << "123456789 * 0.123456789 = " << BigInt(123456789) * 0.123456789l << endl;
						cout << "4286 * -0.5 = " << BigInt(4286) * -0.5l << endl;
						cout << "29384723 * 1.0 = " << BigInt(29384723) * 1.0l << endl;
						cout << "29384723 * -1.0 = " << BigInt(29384723) * -1.0l << endl;
						cout << "3874928345 * 0.0 = " << BigInt("3874928345") * 0.0l << endl;
						//BigInt n = 1000;
						cout << "n = 1000: n*n*(8+n*(12+n*(3+n*n))) = " << n*n*(8 + n*(12 + n*(3 + n*n))) << endl;
						cout << endl;
					}
					break;
					case 3: 
					{
						cout << "Множення:";
						cout << "128 * 512 = " << (BigInt(128) * 512) << endl;
						cout << "0 * 12345 = " << (BigInt(0) * 12345) << endl;
						cout << "-123 * 0 = " << (BigInt(-123) * 0) << endl;
						cout << "-12345 * 1000001 = " << (BigInt(-12345) * BigInt(1000001)) << endl;
						cout << "-1 * -1 = " << (BigInt(-1) * BigInt(-1)) << endl;
					} 
					break;
					case 4: 
					{
						cout << "Ділення:";
						cout << "1024 / 2 = " << (BigInt(1024) / 2) << endl;
						cout << "-525474 / -789 = " << (BigInt(-525474) / -789) << endl;
						cout << "-81 / 27 = " << (BigInt(-81) / 27) << endl;
						cout << "0 / -888 = " << (BigInt(0) / -888) << endl;
						cout << "1024 / 2 = " << (BigInt(1024) / BigInt(2)) << endl;
						cout << "-525474 / -789 = " << (BigInt(-525474) / BigInt(-789)) << endl;
						cout << "-81 / 27 = " << (BigInt(-81) / BigInt(27)) << endl;
						cout << "0 / -888 = " << (BigInt(0) / BigInt(-888)) << endl;
						//BigInt q = 1023;
						int rem = q.divide(2);
						cout << "1023 / 2 = " << q << " + " << rem << "/2" << endl;
						q = 1219255159;
						rem = q.divide(98765);
						cout << "1219255159 / 98765 = " << q << " + " << rem << "/98765" << endl;
						q = 121;
						rem = q.divide(11);
						cout << "121 / 11 = " << q << " + " << rem << "/11" << endl;
						q = 1023;
						BigInt rem2 = q.divide(BigInt(2));
						cout << "1023 / 2 = " << q << " + " << rem2 << "/2" << endl;
						q = 1219255159;
						rem2 = q.divide(BigInt(98765));
						cout << "1219255159 / 98765 = " << q << " + " << rem2 << "/98765" << endl;
						q = 121;
						rem2 = q.divide(BigInt(11));
						cout << "121 / 11 = " << q << " + " << rem2 << "/11" << endl;
						q = 9999;
						rem2 = q.divide(BigInt(9));
						cout << "9999 / 9 = " << q << " + " << rem2 << "/9" << endl;
					}
					break;
					case 5: 
					{
						cout << "Конкатенація:" << endl;
						cout << "123,456 = " << (BigInt(123), 456) << endl;
						cout << "9999,55 = " << (BigInt(9999), BigInt(55)) << endl;
						cout << "0,1 = " << (BigInt(0), BigInt(1)) << endl;
						cout << "0,0 = " << (BigInt(0), 0) << endl;
						cout << "0,0 = " << (BigInt(0), BigInt(0)) << endl;
						cout << endl;
					}
					break;
					case 6: 
					{
						cout << "Відображення (Reflection):" << endl;					
						cout << "11 + 11 = " << (x + x) << endl;
						cout << "11 * 11 = " << (x * x) << endl;
						x += x;
						cout << "11 + 11 = " << x << endl;
						x *= x;
						cout << "22 * 22 = " << x << endl;
						cout << endl;
					}
					break;
					case 7: 
					{
						cout << "Побітові операції (Bitwise operations):" << endl;
						cout << "1 << 10 = " << (1 << 10) << " = " << (BigInt(1) << 10) << endl;
						cout << "-7 << 2 = " << (-7 << 2) << " = " << (BigInt(-7) << 2) << endl;
						cout << "3 << 8 = " << (3 << 8) << " = " << (BigInt(3) << 8) << endl;
						cout << "3 << 9 = " << (3 << 9) << " = " << (BigInt(3) << 9) << endl;
						cout << "1024 >> 9 = " << (1024 >> 9) << " = " << (BigInt(1024) >> 9) << endl;
						cout << "-1 >> 4 = " << (-1 >> 4) << " = " << (BigInt(-1) >> 4) << endl;
						cout << endl;
						cout << "Input:" << endl;
						istringstream in("1234567890");
						in >> x;
						cout << "1234567890 = " << x << endl;
						istringstream in2(" \t\n\r01234 -00009876\t");
						in2 >> x >> rem2;
						cout << "1234 = " << x << endl;
						cout << "-9876 = " << rem2 << endl;
						cout << endl;
					}
					break;
					case 8: 
					{
						cout << "Exhaustion:" << endl;
						BigInt *table = new BigInt[10240];
						table[0] = 0; table[1] = 1;
						for (int i = 2; i < 10240; i++)
							table[i] = table[i - 1] + table[i - 2];
						cout << "Fibonacci( 615 )  = " << table[615] << endl;
						cout << "Fibonacci( 10000 )  = " << table[10000] << endl;
						delete[] table;
						cout << endl;
					}
					break;
					case 9:
					{
						cout << "Логарифми (Logarithms):" << endl;
						cout << "log2( 1024 ) = " << log2(BigInt(1024)) << endl;
						cout << "log2( 6 ) = " << log2(BigInt(6)) << endl;
						cout << "log( 0 ) = " << log(BigInt(0)) << endl;
						cout << "log10( 1000000 ) = " << log10(BigInt(10000000)) << endl;
						cout << "log( 1234567 ) = " << log(BigInt(1234567)) << endl;
					}
					break;
					case 10: // Вивід даних
						bigIntArr.Show();
					cout << endl;
					break;
					case 11: 
					{
						 cout << "Сума елементів масиву: " << endl;
						 cout << bigIntArr.Sum();
						 cout << endl;
					}
					break;
					case 12: // виклик віртуального оператора конкатенації рядків
					{
						String *pObj = new String();
						for (p_BigInt = bigIntArr.begin(); p_BigInt != bigIntArr.end(); ++p_BigInt)
						{
							String *temp = new String(p_BigInt->toString());
							*pObj = *pObj + *temp;
							delete temp;
						}
						cout << *pObj << endl;
						delete pObj;
					}
					break;
					case 13: // виклик віртуального оператора додавання великих цілих чисел
					{
						String *pObj = new BigInt();
						for (p_BigInt = bigIntArr.begin(); p_BigInt != bigIntArr.end(); ++p_BigInt)
						{
							*pObj = *pObj + *p_BigInt;
						}
						cout << *pObj << endl;
						delete pObj;
					}
					break;
					case 14: // Вихід з програми
						cout << "Дякуємо, що скористалися нашою программою!\n";
						exit(1);
					break;
					default:
						cout << "Помилка при виборi пункта меню." << endl;
					break;
				}
			}
			catch (Error ex)
			{
				cout << " ================================================== " << endl;
				cout << ex.what() << endl;
			}
			myItr.~MyIterator();
			cout << "Продовжити?(так - 'y')" << endl;
			flag = _getch();
		}
	}
	catch (Error ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Помилка!" << endl;
		exit(1);
	}
	cout << "Натиснiть будь-яку клавiшу!";
	while (!_kbhit());
	return 0;
}


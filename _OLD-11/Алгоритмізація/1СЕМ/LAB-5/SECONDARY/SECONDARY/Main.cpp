#include <iostream>
#include <stdio.h>
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
void echoRight(string input){
	short w = 80;
	if(strlen(input.c_str()) < 80){
		for(int i = 0;i<(80 - strlen(input.c_str()));i++){
			cout << " ";
		};
		cout << input.c_str();
	}
}
void display(string num, string nam, string tim){
	echoRight("r----------------");
	string s = "| Станцiя №$     ";
	s.replace(s.find("$"), 1, num);
	echoRight(s);
	echoRight("| Назва:         ");

	s = "|    $$$$$$$$$$$ ";
	s.replace(s.find("$$$$$$$$$$$"), 11, nam);
	echoRight(s);
	echoRight("| Час в дорозi:  ");

	s = "|           $$$$ ";
	s.replace(s.find("$$$$"), 4, tim);
	echoRight(s);
	echoRight("L________________");
}
int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Ukrainian");
	system("cls");
	system("color 1e");
	short n;
	cout << "                Google" << endl << endl;
	cout << " - Окей гугл, менi треба станцiю №";
	cin >> n;
	echoRight("Зачекай - ");
	cout << endl;
	Sleep(700);
	echoRight("З'єднуюсь з серверами... - ");
	Sleep(700);
	switch(n){
	case 1:display("1", "Франкiвська", "45хв");break;
	case 2:display("2", "  Сихiвська", "20хв");break;
	case 3:display("3", "   Київська", "15хв");break;
	case 4:display("4", "    Пасiчна", "20хв");break;
	case 5:display("5", "    Одеська", " 5хв");break;
	default:main(argc, argv);
	}
	
	system("pause");
	return 0;
}
#include <iostream>
#include <map>
#include <string>
#include <conio.h>
#include <sstream> 

using namespace std;

/*
	Написати програму обліку книг бібліотеки на основі контейнерного класу multimap. 
	Дані про книги складаються з прізвища та ініціалів автора, назви книги, року видання. 
	Необхідно забезпечити додавання інформації про нові надходження книг, 
	видалення даних про списані книги, пошуку та виведення всіх книг заданого автора або року видання.
*/
void main(){
    multimap<string, int> data;

    data.insert(pair<string, int>("J. D. Salinger \"The Catcher in the Rye\"", 1951));
    data.insert(pair<string, int>("R. Bradbury \"Dandelion Wine\"", 1957));
    data.insert(pair<string, int>("D. Keyes \"Flowers for Algernon\"", 1959));
    data.insert(pair<string, int>("D. Keyes \"The Minds of Billy Milligan\"", 1981));

	while(1){
		cout << "Choose your action:" << endl;
		cout << "1 - Show list" << endl;
		cout << "2 - Add book" << endl;
		cout << "3 - Erase book" << endl;
		cout << "4 - Find book" << endl;
		cout << "Your choice: "; 

		int cmd;
		cin >> cmd;
		int n;
		switch (cmd){
			case 1:
				for(auto it = data.begin(); it != data.end(); ++it){
					cout << it->first << " : " << it->second << endl;
				}
				break;

			case 2:
				cout << "Enter the year of publication of the book: ";
				n = 1;
				int yearOfPublication;
				cin>>yearOfPublication;

				cout << "Enter the author and the title of the book: ";
				while (n != 0){
					string line;
					getline(cin, line);

					if (line.empty()) continue;
					data.insert(pair <string, int>(line, yearOfPublication));
					n--;
				}
				cout << endl;
				for(auto it = data.begin(); it != data.end(); ++it){
					cout << it->first << " : " << it->second << endl;
				}
				break;

			case 3:
				cout << "Enter the title of the book: ";
				n = 1;
				while (n != 0){
					string s;
					getline(cin, s);

					if (s.empty()) continue;
					data.erase (data.find(s));
					n--;
				}

				cout << endl;
				for(auto it = data.begin(); it != data.end(); ++it){
						cout << it->first << " : " << it->second << endl;
				}
				break;

			case 4:
				cout << "Enter the title of the book: ";
				n = 1;
				while (n != 0){
					string s;
					getline(cin, s);

					if (s.empty()) continue;
					for(auto it = data.begin(); it != data.end(); ++it){
						if (s == it->first)
						cout << it->first << " : " << it->second << endl;
					}
					n--;
				}
				break;

			default:
				cout << "Error" << endl;
				break;
		}
	}
	getch();
    return;
}
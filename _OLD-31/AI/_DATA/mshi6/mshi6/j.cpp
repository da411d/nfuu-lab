#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int cityCount = 15;
int distances[cityCount][cityCount];
const int minimal = 100000;
string city[cityCount] = { " Запорiжжя "," Iв-Франкiвськ ", " Луганськ "," Миколаїв ", " Рівне "," Сiмферополь ", 
" Суми "," Тернопiль ", " Ужгород " , " Харкiв ", " Херсон ", " Хмельницький "," Черкаси ", " Чернiвцi "," Чернiгiв " 
};

void loadFromFile() {
	ifstream stream("matrix (2).txt");

	if (!stream.is_open()) {
		cout << "Cannot open file!\n";
		return;
	}

	for (int i = 0; i < cityCount; ++i) {
		for (int j = 0; j < cityCount; ++j) {
			stream >> distances[i][j];
		}
		
	}
	cout << endl;
	stream.close();
}

int findMinDistanceFromCityWith(int rowIndex) {
	int min = minimal, col = -1;
	for (int j = 1; j < cityCount; j++) {
		if (distances[rowIndex][j] != 0 && min > distances[rowIndex][j]) {
			min = distances[rowIndex][j];
			col = j;
		}
	}

	return col;
}

void zerosForRow(int row) {
	for (int i = 0; i < cityCount; i++) {
		distances[i][row] = 0;
	}
}

int main() {
	setlocale(LC_ALL, "Ukrainian");
	loadFromFile();

	for (int count = 0, currentCityIndex = 0; count < cityCount; count++) {
		int minInd = findMinDistanceFromCityWith(currentCityIndex);
		if (minInd != -1) {
			zerosForRow(currentCityIndex);
			cout << "з мiста" << city[currentCityIndex] << " " << "до мiста" << city[minInd] << distances[currentCityIndex][minInd] << " км" << endl;
			currentCityIndex = minInd;
		}
		else {
			cout << "до мiста " << city[0] << " "<< distances[currentCityIndex][0]  << " км" << " \n";

			system("pause");
			return 1;
		}
	}

	system("pause");
	return 0;
}

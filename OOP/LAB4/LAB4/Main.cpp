#include <iostream>
#include <fstream>
using namespace std;

const string _FILENAME_ = "5c1e8290-e2f1-f558-3ad3-089c7d6086bb.txt";

/**
	COMPUTER
*/
class COMP{
public:
	COMP(){};
	COMP(string m, int p){
		this->model = m;
		this->price = p;
	};
	~COMP(){};

	int price;
	string model;

	void print(){
		ofstream f(_FILENAME_, ios::app);
		f << model.c_str() << "  |  " << price << "UAH" << endl;
		cout << model.c_str() << "  |  " << price << "UAH" << endl;
		f.close();
	};
};

/**
	CPU
*/
class CPU: public COMP{
public:
	CPU(string m, int p, float f){
		this->model = m;
		this->price = p;
		this->frequency = f;
	};
	~CPU(){};

	float frequency;

	void print(){
		ofstream f(_FILENAME_, ios::app);
		f << model.c_str() << "  |  " << price << "UAH  |  " << frequency << "GHz" << endl;
		cout << model.c_str() << "  |  " << price << "UAH  |  " << frequency << "GHz" << endl;
		f.close();
	};
};

/**
	HDD
*/
class HDD: public COMP{
public:
	HDD(string m, int p, int s){
		this->model = m;
		this->price = p;
		this->size = s;
	};
	~HDD(){};

	int size;

	void print(){
		ofstream f(_FILENAME_, ios::app);
		f << model.c_str() << "  |  " << price << "UAH  |  " << size << "GB" << endl;
		cout << model.c_str() << "  |  " << price << "UAH  |  " << size << "GB" << endl;
		f.close();
	};
};


 /**
	MAIN
*/
void main(){
	COMP asus("predator", 50000);
	asus.print();

	CPU intel_i5("i5", 5000, 2.4f);
	intel_i5.print();

	HDD toshiba("mx228", 2000, 1024);
	toshiba.print();

	system("PAUSE>>NUL");

	//OPEN FILE
	string hook("start ");
	hook.append(_FILENAME_);
	system(hook.c_str());
}
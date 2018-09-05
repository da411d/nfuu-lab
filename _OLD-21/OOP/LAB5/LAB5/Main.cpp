#include <iostream>
#include <fstream>
using namespace std;

/**
	S
*/
class S{
public:
	S(){};
	~S(){};

	virtual float getS() = 0;
};

/**
	RECT
*/
class RECT: public S{
public:
	RECT(float a, float b){
		this->a = a;
		this->b = b;
	};
	~RECT(){};

	float a, b;

	float getS() override {
		return a*b;
	}
};

/**
	CIRCLE
*/
class CIRCLE: public S{
public:
	CIRCLE(float r){
		this->r = r;
	};
	~CIRCLE(){};

	float r;

	float getS() override {
		return 3.14159f * r * r;
	}
};


/**
	TRIANGLE
*/
class TRIANGLE: public S{
public:
	TRIANGLE(float a, float b){
		this->a = a;
		this->b = b;
	};
	~TRIANGLE(){};

	float a, b;

	float getS() override {
		return a * b / 2.f;
	}
};

/**
	TRAPEZE
*/
class TRAPEZE: public S{
public:
	TRAPEZE(float a, float b, float h){
		this->a = a;
		this->b = b;
		this->h = h;
	};
	~TRAPEZE(){};

	float a, b, h;

	float getS() override {
		return (a + b) * h / 2.f;
	}
};

/**
	MAIN
*/
void main(){
	RECT photo(3.5f, 4.5f);
	cout << "RECT:      " << photo.getS() << endl;
	
	CIRCLE hole(12);
	cout << "CIRCLE:    " << hole.getS() << endl;

	TRIANGLE cheese(15, 8);
	cout << "TRIANGLE:  " << cheese.getS() << endl;

	TRAPEZE cake(8, 12, 4);
	cout << "CAKE:      " << cake.getS() << endl;

	system("PAUSE>>NUL");
}
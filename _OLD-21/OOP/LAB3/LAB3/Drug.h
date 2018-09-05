#pragma once
class Drug
{
public:
	Drug(void);
	Drug(char*);
	Drug(char*, int);
	Drug(char*, int, int);
	~Drug(void);
	char* getName(void);
	int getCount(void);
	int getPrice(void);
	void render(void);

	Drug operator+=(int);
	Drug operator-=(int);

	Drug operator+(int);
	Drug operator-(int);


private:
	char* name;
	int count;
	int price;
};


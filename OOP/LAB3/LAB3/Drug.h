#pragma once
class Drug
{
public:
	Drug(char*);
	Drug(char*, int);
	~Drug(void);
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


#pragma once

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

#include "String.h"

using namespace std;

#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

class BigInt : public String 
{
private:
	int size;
	int sign;

public:
	BigInt(int n, int cap);
	BigInt(int n);
	BigInt(long double d);
	BigInt();
	BigInt(string s);
	BigInt(const char s[]);
	BigInt(const BigInt &n);
	const BigInt &operator=(const BigInt &n);
	const BigInt &operator=(int n);
	virtual ~BigInt();
	void normalize();
	static int sig(int n);
	static int sig(long double n);
	inline int length() { return size; }

	BigInt operator++();
	BigInt operator++(int);
	BigInt operator--();
	BigInt operator--(int);
	BigInt operator-();
	BigInt operator+ (int n);
	BigInt operator+ (BigInt n);
	virtual BigInt& operator+ (String&);
	BigInt operator- (int n);
	BigInt operator- (BigInt n);
	BigInt operator* (int n);
	BigInt operator* (BigInt n);
	BigInt operator/ (int n);
	BigInt operator/ (BigInt n);
	int divide(int n); 
	BigInt divide(BigInt n);
	BigInt operator* (long double n);

	bool operator!();
	operator bool();
	operator string();

	bool operator<(BigInt n);
	bool operator>(BigInt n);
	bool operator==(BigInt n);
	bool operator<(int n);
	bool operator>(int n);
	bool operator==(int n);
	int compare(BigInt n);

	int toInt();
	string toString();

public:
	friend istream &operator >> (istream &in, BigInt &n);
	friend ostream &operator<<(ostream &out, BigInt n);
};


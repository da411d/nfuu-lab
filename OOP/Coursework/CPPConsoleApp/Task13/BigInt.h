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
	int size;            // к-іть використаних байт (масиву p)
	int sign;            // -1, 0 або +1

public:
	/** Створює a BigInt with initial value n and initial capacity cap **/
	BigInt(int n, int cap);

	/** Creates a BigInt with initial value n **/
	BigInt(int n);

	/** Creates a BigInt with initial value floor( d ) **/
	BigInt(long double d);

	/** Creates a BigInt with value 0 **/
	BigInt();

	/** Creates a BigInt by reading the value from a string **/
	BigInt(string s);

	/** Creates a BigInt by reading the value from a C string **/
	BigInt(const char s[]);

	/** Copy constructor **/
	BigInt(const BigInt &n);

	/** Assignment operators **/
	const BigInt &operator=(const BigInt &n);
	const BigInt &operator=(int n);

	/** Cleans up **/
	virtual ~BigInt();

	/** Removes any leading zeros and adjusts the sign **/
	void normalize();

	/** Returns the sign of n: -1, 0 or 1 **/
	static int sig(int n);

	/** Returns the sign of n: -1, 0 or 1 **/
	static int sig(long double n);

	/** Returns the number of decimal digits **/
	inline int length() { return size; }

	/** Arithmetic **/
	BigInt operator++();
	BigInt operator++(int);
	BigInt operator--();
	BigInt operator--(int);
	BigInt operator-();
	BigInt operator+ (int n);
	BigInt operator+ (BigInt n);
	virtual BigInt& operator+ (String&); // віртуальний оператор додавання великих цілих чисел
	BigInt&operator+=(int n);
	BigInt&operator+=(BigInt n);
	BigInt operator- (int n);
	BigInt operator- (BigInt n);
	BigInt&operator-=(int n);
	BigInt&operator-=(BigInt n);
	BigInt operator* (int n);
	BigInt operator* (BigInt n);
	void   operator*=(int n);
	void   operator*=(BigInt n);
	BigInt operator/ (int n);
	BigInt operator/ (BigInt n);
	void   operator/=(int n);
	void   operator/=(BigInt n);
	int    operator% (int n);
	BigInt operator% (BigInt n);
	void   operator%=(int n);
	void   operator%=(BigInt n);
	int divide(int n);              // Divides storing quotient in *this and returning the remainder
	BigInt divide(BigInt n);        // Divides storing quotient in *this and returning the remainder
	BigInt operator* (long double n); // Multiplies by a double and truncates (always under-estimates!)
	void   operator*=(long double n); // Multiplies by a double and truncates (always under-estimates!)

									  /** Bitwise arithmetic **/
	BigInt operator<< (int n);
	void   operator<<=(int n);
	BigInt operator >> (int n);   // Works differently for negative numbers
	void   operator>>=(int n);   // Works differently for negative numbers
								 /*
								 BigInt operator&  ( int n    );
								 BigInt operator&  ( BigInt n );
								 void   operator&= ( int n    );
								 void   operator&= ( BigInt n );
								 BigInt operator|  ( int n    );
								 BigInt operator|  ( BigInt n );
								 void   operator|= ( int n    );
								 void   operator|= ( BigInt n );
								 BigInt operator^  ( int n    );
								 BigInt operator^  ( BigInt n );
								 void   operator^= ( int n    );
								 void   operator^= ( BigInt n );
								 BigInt operator~();
								 */
								 /** Concatenation ;-) **/
	BigInt operator,(int n);
	BigInt operator,(BigInt n);

	/** Casting **/
	bool operator!();
	operator bool();
	//operator int();   //XXX: Don't do this!!! It takes precedence over operator+(int,BigInt)
	operator string();

	/** Comparison **/
	bool operator<(BigInt n);
	bool operator>(BigInt n);
	bool operator==(BigInt n);
	bool operator<=(BigInt n);
	bool operator>=(BigInt n);
	bool operator<(int n);
	bool operator>(int n);
	bool operator==(int n);
	bool operator<=(int n);
	bool operator>=(int n);
	int compare(BigInt n);

	/** Returns the lowest value as an integer (watch out for overflow) **/
	int toInt();

	/** Returns the value as a decimal string **/
	string toString();

	/** Outputs decimal value to stdout **/
	virtual void print(ostream &os);

	/** Outputs the decimal value, with commas **/
	void printWithCommas(ostream &out);

public:
	/** Expansion **/
	void grow();

	/** I/O Friends **/
	friend istream &operator >> (istream &in, BigInt &n);
	friend ostream &operator<<(ostream &out, BigInt n);
private:
	/** Logarithms **/
	friend long double log2(BigInt x, long double epsilon);
	inline friend long double log(BigInt x, long double epsilon);
	inline friend long double log10(BigInt x, long double epsilon);
	inline friend long double lg(BigInt x, long double epsilon);
	inline friend long double ln(BigInt x, long double epsilon);
};


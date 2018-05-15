#include "stdafx.h"
#include "BigIntArray.h"
#include <iomanip>

BigIntArray::BigIntArray(void)
{
	pBigInts = new BigInt[0];
	Count = 0;
	uiPosition = 0;
}

BigIntArray::BigIntArray(int nCount)
{
	uiPosition = 0;
	Count = nCount;
	pBigInts = new BigInt[nCount];
}

BigIntArray::~BigIntArray(void)
{
	if (pBigInts) delete[] pBigInts;
}

void BigIntArray::Input()
{
	for (int i = 0; i < Count; i++)
	{
		cout << "×èñëî #" << i + 1 << endl;
		cin >> *(pBigInts + i);
	}

}

BigInt* BigIntArray::GetBigInts()
{
	return pBigInts;
}

int BigIntArray::GetCount()
{
	return Count;
}

void BigIntArray::Show()
{
	cout << endl;
	cout << "Âìiñò:" << endl;
	for (int i = 0; i < Count; i++)
		cout << *(pBigInts + i) << " ";
}

BigInt BigIntArray::Sum()
{
	BigInt sum(0);
	
	for (int i = 0; i < Count; i++)
	{
		sum = sum + pBigInts[i];
	}
	return sum;
}

BigInt* BigIntArray::begin()
{
	if (pBigInts == NULL || Count <= 0)
	{
		throw runtime_error("Bad pointer");
	}

	uiPosition = 0;

	return pBigInts;
}

BigInt* BigIntArray::end()
{
	if (pBigInts == NULL || Count <= 0)
	{
		throw runtime_error("Bad pointer");
	}

	return pBigInts + Count;
}

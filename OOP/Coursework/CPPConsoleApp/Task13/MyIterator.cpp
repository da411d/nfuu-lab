#include "StdAfx.h"
//#include "MyIterator.h"
//#include "Truck.h"

/*template <class T> MyIterator<T>::MyIterator(T *pElement, size_t iCount) :
	m_pBuffer(pElement), m_iCount(iCount)
{
	m_iPosition = 0;
}

template <class T> MyIterator<T>::~MyIterator()
{}

template <class T> T* MyIterator<T>::operator++()
{
	if (m_pBuffer == NULL || m_iCount <= 0)
	{
		throw runtime_error("Bad pointer");
	}

	if (m_iPosition > m_iCount)
	{
		throw runtime_error("Out of range");
	}

	m_iPosition++;
	T* pData = m_pBuffer + m_iPosition;
	return pData;
}

template <class T> T* MyIterator<T>::operator->()
{
	T* pData = m_pBuffer + m_iPosition;
	return pData;
}

template <class T> T* MyIterator<T>::operator=(T* lvalue)
{
	return m_pBuffer = lvalue;
}

template <class T> T MyIterator<T>::operator*()
{
	return *(m_pBuffer + m_iPosition);
}

template <class T> bool MyIterator<T>::operator!=(T* lvalue)
{
	bool pr;
	if ((m_pBuffer + m_iPosition) != lvalue) pr = true;
	else pr = false;
	return pr;
}*/

/*MyIterator::MyIterator(CTruck* p, size_t iCount) :
	m_pBuffer(p), m_iCount(iCount)
{
	m_iPosition = 0;
}

MyIterator::~MyIterator()
{}

CTruck* MyIterator::operator++()
{
	if(m_pBuffer == NULL || m_iCount <= 0)
	{
		throw runtime_error("Bad pointer");
	}

	if(m_iPosition > m_iCount)
	{
		throw runtime_error("Out of range");
	}

	m_iPosition++;
	CTruck* pData = m_pBuffer + m_iPosition;
	return pData;
}

CTruck* MyIterator::operator->()
{
	CTruck* pData = m_pBuffer + m_iPosition;

	return pData;
}

CTruck* MyIterator::operator=(CTruck* lvalue)
{
	return m_pBuffer = lvalue;
}

T MyIterator::operator*()
{
	return *(m_pBuffer + m_iPosition);
}

bool MyIterator::operator!=(CTruck* lvalue)
{
	bool pr;
	if ((m_pBuffer + m_iPosition) != lvalue) pr = true;
	else pr = false;
	return pr;
}*/
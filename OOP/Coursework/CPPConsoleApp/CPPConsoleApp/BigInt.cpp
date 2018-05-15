#include "stdafx.h"
#include "BigInt.h"

BigInt operator+(int m, BigInt &n)
{
	return n + m;
}

BigInt operator-(int m, BigInt &n)
{
	return -n + m;
}

BigInt operator*(int m, BigInt &n)
{
	return n * m;
}

BigInt operator/(int m, BigInt &n)
{
	return BigInt(m) / n;
}

BigInt operator%(int m, BigInt &n)
{
	return BigInt(m) % n;
}

/** Misc **/
inline bool isDigit(int c)
{
	return(c >= (int)'0' && c <= (int)'9');
}

/** Input/Output **/
istream &operator >> (istream &in, BigInt &n)
{
	n.size = 0;
	n.sign = 1;
	int sign = 1;
	int c;
	while ((c = in.peek()) >= 0 &&
		(c == ' ' || c == '\t' || c == '\r' || c == '\n'))
		in.get();
	if (c < 0 || (c != (int)'-' && !isDigit(c)))
	{
		in >> c;                
		return in;
	}
	if (c == (int)'-') { sign = -1; in.get(); }

	
	while ((c = in.peek()) >= 0 && isDigit(c))
	{
		in.get();
		n *= 10;
		n += (c - (int)'0');
	}
	n.sign = sign;      
	n.normalize();
	return in;
}

ostream &operator<<(ostream &out, BigInt n)       
{
	return out << n.toString();
}

BigInt::BigInt(int n, int cap)
{
	cap = max(cap, (int)sizeof(n) * 8);
	capacity = cap;
	sign = sig(n);
	n *= sign;
	p = new char[cap];
	memset(p, 0, cap);
	for (size = 0; n; size++)
	{
		p[size] = n % 10;
		n /= 10;
	}
}

BigInt::BigInt(int n)
{
	capacity = 1024;
	sign = sig(n);
	n *= sign;
	p = new char[capacity];
	memset(p, 0, capacity);
	size = 0;
	while (n)
	{
		p[size++] = n % 10;
		n /= 10;
	}
}

BigInt::BigInt(long double d)
{
	capacity = 1024;
	sign = (d < 0 ? -1 : d > 0 ? 1 : 0);
	d *= sign;
	p = new char[capacity];
	memset(p, 0, capacity);
	size = 0;
	d = floor(d);
	while (d > 0)
	{
		p[size++] = min(max(0, (int)((d - floor(d / 10) * 10) + 0.5)), 9);
		//p[size++] = 0 > ? (int)((d - floor(d / 10) * 10) + 0.5) < ? 9;
		d = floor(d / 10);
	}
}

BigInt::BigInt()
{
	capacity = 128;
	sign = 0;
	p = new char[capacity];
	memset(p, 0, capacity);
	size = 0;
}

BigInt::BigInt(string s)
{
	capacity = max((int)s.size(), 16);
	sign = 0;
	p = new char[capacity];
	memset(p, 0, capacity);

	istringstream in(s);
	in >> (*this);
}

BigInt::BigInt(const char s[])
{
	capacity = max((int)strlen(s), 16);
	sign = 0;
	p = new char[capacity];
	memset(p, 0, capacity);

	istringstream in(s);
	in >> (*this);
}

BigInt::BigInt(const BigInt &n)
{
	capacity = n.capacity;
	sign = n.sign;
	size = n.size;
	p = new char[capacity];
	memcpy(p, n.p, capacity);
}

const BigInt &BigInt::operator=(const BigInt &n)
{
	if (&n != this)
	{
		if (capacity < n.size)
		{
			capacity = n.capacity;
			delete[] p;
			p = new char[capacity];
		}
		sign = n.sign;
		size = n.size;
		memcpy(p, n.p, size);
		memset(p + size, 0, capacity - size);
	}
	return *this;
}

const BigInt &BigInt::operator=(int n)
{
	sign = sig(n);
	n *= sign;
	for (size = 0; n; size++)
	{
		p[size] = n % 10;
		n /= 10;
	}
	return *this;
}

BigInt::~BigInt()
{
}

void BigInt::normalize()
{
	while (size && !p[size - 1]) size--;
	if (!size) sign = 0;
}

int BigInt::sig(int n)
{
	return(n > 0 ? 1 : (n == 0 ? 0 : -1));
}

int BigInt::sig(long double n)
{
	return(n > 0 ? 1 : (n == 0 ? 0 : -1));
}

int BigInt::toInt()
{
	int result = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		result *= 10;
		result += p[i];
		if (result < 0) return sign * 0x7FFFFFFF;
	}
	return sign * result;
}

string BigInt::toString()
{
	string s = (sign >= 0 ? "" : "-");
	for (int i = size - 1; i >= 0; i--)
		s += (p[i] + '0');
	if (size == 0) s += '0';
	return s;
}

void BigInt::print(ostream &os)  //FIXME: make more efficient
{
	os << endl << "Результат:" << endl;
	os << toString();
}

void BigInt::printWithCommas(ostream &out)
{
	if (sign < 0) out.put('-');
	for (int i = size - 1; i >= 0; i--)
	{
		out.put(p[i] + '0');
		if (!(i % 3) && i) out.put(',');
	}
	if (size == 0) out.put('0');
}

void BigInt::grow()
{
	char *oldp = p;
	int oldCap = capacity;
	capacity *= 2;
	p = new char[capacity];
	memcpy(p, oldp, oldCap);
	memset(p + oldCap, 0, oldCap);
	delete[] oldp;
}

BigInt BigInt::operator++()
{
	operator+=(1);
	return *this;
}

BigInt BigInt::operator++(int)
{
	return operator++();
}

BigInt BigInt::operator--()
{
	operator-=(1);
	return *this;
}

BigInt BigInt::operator--(int)
{
	return operator--();
}

BigInt BigInt::operator-()
{
	BigInt result(*this);
	result.sign *= -1;
	return result;
}

BigInt BigInt::operator+(int n)
{
	BigInt result(*this);
	result += n;
	return result;
}

BigInt BigInt::operator+(BigInt n)
{
	BigInt result(*this);
	result += n;
	return result;
}

BigInt &BigInt::operator+(String &n)
{
	const BigInt *pBigInt = dynamic_cast<const BigInt*>(&n);
	*this += *pBigInt;
	return *this;
}

BigInt &BigInt::operator+=(int n)
{
	if (size == capacity) grow();

	int nsign = sig(n);
	if (!nsign) return *this;
	if (!sign) sign = nsign;
	if (sign == nsign)
	{
		n *= nsign;
		int carry = 0;
		int i;
		for (i = 0; n || carry; i++)
		{
			int dig = n % 10;
			int newdig = p[i] + dig + carry;
			p[i] = newdig % 10;
			carry = newdig / 10;
			n /= 10;
		}
		size = max(i, size);
	}
	else operator-=(-n);
	return *this;
}

BigInt &BigInt::operator+=(BigInt n)
{
	int maxS = max(size, n.size) + 1;
	while (maxS >= capacity) grow();  

	if (!n.sign) return *this;
	if (!sign) sign = n.sign;
	if (sign == n.sign)
	{
		int carry = 0;
		int i;
		for (i = 0; i < maxS - 1 || carry; i++)
		{
			int newdig = carry;
			if (i < size) newdig += p[i];
			if (i < n.size) newdig += n.p[i];
			p[i] = newdig % 10;
			carry = newdig / 10;
		}
		size = max(i, size);
	}
	else
	{
		n.sign *= -1;
		operator-=(n);
		n.sign *= -1;
	}
	return *this;
}

BigInt BigInt::operator-(int n)
{
	BigInt result(*this);
	result -= n;
	return result;
}

BigInt BigInt::operator-(BigInt n)
{
	BigInt result(*this);
	result -= n;
	return result;
}

BigInt &BigInt::operator-=(int n)
{
	if (size == capacity) grow();

	int nsign = sig(n);
	if (!nsign) return *this;
	if (!sign) sign = 1;
	if (sign == nsign)
	{
		BigInt bin = n;
		if (sign >= 0 && *this < bin || sign < 0 && *this > bin)
		{
			// Subtracting a bigger number
			operator=(toInt() - n);
			return *this;
		}

		n *= nsign;
		int carry = 0;
		int i;
		for (i = 0; n || carry; i++)
		{
			int dig = n % 10;
			int newdig = p[i] - dig + carry;
			if (newdig < 0) newdig += 10, carry = -1;
			else carry = 0;
			p[i] = newdig;
			n /= 10;
		}
		normalize();
	}
	else operator+=(-n);
	return *this;
}

BigInt &BigInt::operator-=(BigInt n)
{
	int maxS = max(size, n.size) + 1;
	while (maxS >= capacity) grow();       

	if (!n.sign) return *this;
	if (!sign) sign = 1;
	if (sign == n.sign)
	{
		if (sign >= 0 && *this < n || sign < 0 && *this > n)
		{
			// Subtracting a bigger number
			BigInt tmp = n;
			tmp -= *this;
			*this = tmp;
			sign = -sign;
			return *this;
		}

		int carry = 0;
		int i;
		for (i = 0; i < maxS - 1; i++)
		{
			int newdig = carry;
			if (i < size) newdig += p[i];
			if (i < n.size) newdig -= n.p[i];
			if (newdig < 0) newdig += 10, carry = -1;
			else carry = 0;
			p[i] = newdig;
		}
		if (carry)     // Subtracted a bigger number, need to flip sign
		{
			if (i) p[0] = 10 - p[0];
			size = (i ? 1 : 0);
			for (int j = 1; j < i; j++)
			{
				p[j] = 9 - p[j];
				if (p[i]) size = j + 1;
			}
			sign *= -1;
		}
		normalize();
	}
	else
	{
		n.sign *= -1;
		operator+=(n);
		n.sign *= -1;
	}
	return *this;
}

BigInt BigInt::operator*(int n)
{
	BigInt result(0, size + (int)sizeof(n) * 8);
	int nsign = sig(n);
	n *= nsign;
	result.sign = sign * nsign;
	if (!result.sign) return result;

	int i, j;
	for (i = 0; n; i++)
	{
		int dig = n % 10;
		if (dig)
		{
			int carry = 0;
			for (j = 0; j < size || carry; j++)
			{
				int newDig = result.p[i + j] + (j < size ? dig * p[j] : 0) + carry;
				result.p[i + j] = newDig % 10;
				carry = newDig / 10;
			}
		}
		n /= 10;
	}
	result.size = i + j - 1;
	return result;
}

BigInt BigInt::operator*(BigInt n)
{
	BigInt result(0, size + n.size);

	result.sign = sign * n.sign;
	if (!result.sign) return result;

	int i, j;
	for (i = 0; i < n.size; i++)
	{
		if (n.p[i])
		{
			int carry = 0;
			for (j = 0; j < size || carry; j++)
			{
				int newDig =
					result.p[i + j] +
					(j < size ? n.p[i] * p[j] : 0) +
					carry;
				result.p[i + j] = newDig % 10;
				carry = newDig / 10;
			}
		}
	}
	result.size = i + j - 1;

	return result;
}

void BigInt::operator*=(int n)
{
	operator=(operator*(n));
}

void BigInt::operator*=(BigInt n)
{
	operator=(operator*(n));
}

BigInt BigInt::operator/(int n)
{
	if (!n) n /= n;        

	BigInt result(*this);
	result /= n;
	return result;
}

BigInt BigInt::operator/(BigInt n)
{
	if (!n) n.size /= n.size;     

	BigInt result(*this);
	result /= n;
	return result;
}

void BigInt::operator/=(int n)
{
	divide(n);
}

void BigInt::operator/=(BigInt n)
{
	divide(n);
}

int BigInt::operator%(int n)
{
	BigInt tmp(*this);
	return tmp.divide(n);
}

void BigInt::operator%=(int n)
{
	operator=(divide(n));
}

BigInt BigInt::operator%(BigInt n)
{
	BigInt tmp(*this);
	return tmp.divide(n);
}

void BigInt::operator%=(BigInt n)
{
	operator=(divide(n));
}

int BigInt::divide(int n)
{
	if (!n) n /= n;        

	int nsign = sig(n);
	n *= nsign;
	if (!sign) return 0;
	sign *= nsign;

	int tmp = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		tmp *= 10;
		tmp += p[i];
		p[i] = tmp / n;
		tmp -= p[i] * n;
	}
	normalize();
	return tmp;
}

BigInt BigInt::divide(BigInt n)
{
	if (!n) n.size /= n.size;         

	if (!sign) return 0;
	sign *= n.sign;

	int oldSign = n.sign;
	n.sign = 1;

	BigInt tmp(0, size);
	for (int i = size - 1; i >= 0; i--)
	{
		tmp *= 10;
		tmp += p[i];
		p[i] = 0;
		while (tmp >= n) { tmp -= n; p[i]++; }
	}
	normalize();

	n.sign = oldSign;

	return tmp;
}

// This is only exact to the first 15 or so p, but it is
// never an over-estimate
BigInt BigInt::operator*(long double n)
{
	// the number of p after the decimal point to use
	const int DIGS_AFTER_DOT = 15;

	int nsign = sig(n);
	n *= nsign;
	int ndigs = n >= 1 ? (int)log10(n) + 1 : 0;
	BigInt result(0, size + ndigs);
	result.sign = sign * nsign;
	if (!result.sign) return result;

	if (n >= 1) for (int i = 0; i < ndigs; i++) n /= 10;
	result.size = 0;

	char afterDot[DIGS_AFTER_DOT + 1];
	memset(afterDot, 0, sizeof(afterDot));

	// Keep going until the DIGS_AFTER_DOT'th digit after the decimal point
	for (int i = ndigs - 1; i >= -DIGS_AFTER_DOT; i--)
	{
		n *= 10;
		int dig = (int)floor(n);
		n -= dig;
		if (!dig) continue;

		int carry = 0;
		for (int j = 0; j < size || carry; j++)
		{
			int newdig =
				(i + j < 0 ? afterDot[-(i + j)] : result.p[i + j])
				+ dig * p[j]
				+ carry;
			(i + j < 0 ? afterDot[-(i + j)] : result.p[i + j]) = newdig % 10;
			if (i + j >= 0 && result.p[i + j])  result.size = max(result.size, i + j + 1); //result.size >?= i + j + 1;
			carry = newdig / 10;
		}
	}
	if (!result.size) result.sign = 0;
	return result;
}

void BigInt::operator*=(long double n)
{
	operator=(operator*(n));
}

BigInt BigInt::operator<<(int n)
{
	BigInt result(*this);
	result <<= n;
	return result;
}

void BigInt::operator<<=(int n)
{
	if (n < 0) operator>>=(-n);
	else if (n > 0)
	{
		BigInt mult(1, 4 * n);
		for (int i = (1 << 30); i; i >>= 1)
		{
			mult *= mult;
			if (n & i) mult *= 2;
		}
		operator*=(mult);
	}
}

BigInt BigInt::operator >> (int n)
{
	BigInt result(*this);
	result >>= n;
	return result;
}

void BigInt::operator>>=(int n)
{
	if (n < 0) operator<<=(-n);
	else if (n > 0)
	{
		BigInt mult(1, 4 * n);
		for (int i = (1 << 30); i; i >>= 1)
		{
			mult *= mult;
			if (n & i) mult *= 2;
		}
		operator/=(mult);
	}
}

BigInt BigInt::operator,(int n)
{
	BigInt result(0, size + (int)sizeof(n) * 8);
	for (result.size = 0; n; result.size++)
	{
		result.p[result.size] = n % 10;
		n /= 10;
	}
	memcpy(result.p + result.size, p, size * sizeof(p[0]));
	result.size += size;
	result.sign = 1;
	result.normalize();
	return result;
}

BigInt BigInt::operator,(BigInt n)
{
	BigInt result(0, size + n.size);
	memcpy(result.p, n.p, n.size * sizeof(n.p[0]));
	memcpy(result.p + n.size, p, size * sizeof(p[0]));
	result.size = size + n.size;
	result.sign = 1;
	result.normalize();
	return result;
}

bool BigInt::operator!()
{
	return !size;
}

BigInt::operator bool()
{
	return size;
}

BigInt::operator string()
{
	return toString();
}

bool BigInt::operator<(BigInt n)
{
	return(compare(n) < 0);
}

bool BigInt::operator>(BigInt n)
{
	return(compare(n) > 0);
}

bool BigInt::operator==(BigInt n)
{
	return(compare(n) == 0);
}

bool BigInt::operator<=(BigInt n)
{
	return(compare(n) <= 0);
}

bool BigInt::operator>=(BigInt n)
{
	return(compare(n) >= 0);
}

bool BigInt::operator<(int n)
{
	return(compare(BigInt(n)) < 0);
}

bool BigInt::operator>(int n)
{
	return(compare(BigInt(n)) > 0);
}

bool BigInt::operator==(int n)
{
	return(compare(BigInt(n)) == 0);
}

bool BigInt::operator<=(int n)
{
	return(compare(BigInt(n)) <= 0);
}

bool BigInt::operator>=(int n)
{
	return(compare(BigInt(n)) >= 0);
}

int BigInt::compare(BigInt n)
{
	if (sign < n.sign) return -1;
	if (sign > n.sign) return 1;
	if (size < n.size) return -sign;
	if (size > n.size) return sign;
	for (int i = size - 1; i >= 0; i--)
	{
		if (p[i] < n.p[i]) return -sign;
		else if (p[i] > n.p[i]) return sign;
	}
	return 0;
}

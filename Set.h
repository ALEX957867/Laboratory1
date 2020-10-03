#pragma once

#include "bitfield.h"
#include"iostream"

class Set
{
private:
	int MaxPower;
	TBitField BitField;
public:
	Set(int mp);
	Set(const Set& s);
	Set(const TBitField& bf);
	operator TBitField();
	int GetMaxPower(void)const;
	void InsElem(const int n);
	void DelElem(const int n);

	int IsMember(const int n)const;
	int operator==(const Set& s);
	Set& operator=(const Set& s);
	Set operator+(const int n);
	Set operator-(const int n);
	Set operator+(const Set& s);
	Set operator*(const Set& s);
	Set operator~(void);
	friend std::istream& operator >> (std::istream& istr, Set& bf);
	friend std::ostream& operator<<(std::ostream& ostr, const Set& bf);
};

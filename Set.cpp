#include"set.h"
Set::Set(int mp) :MaxPower(mp), BitField(mp)
{

}
Set::Set(const Set& s) : MaxPower(s.MaxPower), BitField(s.BitField)
{

}
Set::Set(const  TBitField& bf) : MaxPower(bf.GetLength()), BitField(bf)
{

}
Set::operator TBitField()
{
	TBitField temp(this->BitField);
	return temp;
}
int Set::GetMaxPower(void)const
{
	return MaxPower;
}
int Set::IsMember(const int Elem)const
{
	return BitField.GetBit(Elem);
}
void Set::InsElem(const int Elem)
{
	BitField.SetBit(Elem);
}
void Set::DelElem(const int Elem)
{
	BitField.ClrBit(Elem);
}





Set& Set::operator=(const Set& s)
{
	BitField = s.BitField;
	MaxPower = s.GetMaxPower();
	return *this;
}
Set Set::operator+(const int n)
{
	if (n <= BitField.GetLength())
	{
		InsElem(n);
		return *this;
	}
	else
	{
		Set temp(n + 1);

		temp.BitField = BitField | temp.BitField;

		temp.InsElem(n);

		//std::cout << temp.BitField << std::endl;
		//std::cout << temp.BitField.GetLength() << std::endl;

		return temp;
	}

}
Set Set::operator-(const int n)
{
	if (n >= MaxPower)
	{
		return *this;

	}
	else
	{
		DelElem(n);


		int A = BitField.Optim();
		//std::cout << A << std::endl;
		Set demp(A);
		demp.BitField = BitField | demp.BitField;
		//std::cout << demp.MaxPower << std::endl;
		//::cout << demp.BitField.GetLength() << std::endl;
		//system("pause");
		return demp;

	}
}
int Set::operator==(const Set& s)
{
	return BitField == s.BitField;
}
Set Set::operator+(const Set& s)
{
	Set temp(BitField | s.BitField);
	return temp;
}
Set Set::operator*(const Set& s)
{
	Set temp(BitField & s.BitField);
	return temp;
}
Set Set::operator~(void)
{
	Set temp(~BitField);
	return temp;
}
std::istream& operator >> (std::istream& istr, Set& s)
{
	int temp; char ch;
	do(istr >> ch); while ((ch != ',') && (ch != '}'));
	do
	{
		istr >> temp;
		s.InsElem(temp);
		do (istr >> ch); while ((ch != ',') && (ch != '}'));
	} while (ch != '}');
	return istr;
}
std::ostream& operator<<(std::ostream& ostr, const Set& s)
{
	int i, n; char ch = ' ';
	ostr << "{";
	n = s.GetMaxPower();
	for (i = 0; i < n; i++)
	{
		if (s.IsMember(i)) { ostr << ch << ' ' << i; ch = ','; }
	}
	ostr << " }";
	return ostr;
}

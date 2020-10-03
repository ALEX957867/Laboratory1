#include "bitfield.h"

TBitField::TBitField(int len) :BitLen(len) {
	MemLen = (len + 31) >> 5;
	pMem = new TELEM[MemLen];
	if (pMem != NULL)
		for (int i = 0; i < MemLen; i++) pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) {
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	if (pMem != NULL)
	{
		for (int i = 0; i < MemLen; i++)
			pMem[i] = bf.pMem[i];
	}
}

TBitField :: ~TBitField() {
	delete pMem;
	pMem = NULL;
}



int TBitField::GetMemIndex(const int n)const {
	return n >> 5;
}

TELEM TBitField::GetMemMask(const int n)const {
	return 1 << (n & 31);
}

int TBitField::GetLength(void)const {
	return BitLen;
}

void TBitField::SetBit(const int n) {
	if ((n > -1) && (n < BitLen))
	{
		if ((n > -1) && (n < BitLen))
			pMem[GetMemIndex(n)] |= GetMemMask(n);
	}
}
void TBitField::ClrBit(const int n) {
	if ((n > -1) && (n < BitLen))
		pMem[GetMemIndex(n)] &= ~GetMemMask(n);

}
int TBitField::GetBit(const int n) const {
	if ((n > -1) && (n < BitLen))
		return pMem[GetMemIndex(n)] & GetMemMask(n);
	return 0;
}


int TBitField::Optim()
{
	int i;
	for (i = (MemLen - 1); i > 0; i--)
	{
		if (pMem[i] != 0)
		{

			break;
		}
	}
	//std::cout << i<< std::endl;;



	int h;
	for (h = (8 * sizeof(TELEM)); h > -1; h--)
	{
		int g = h + ((i) * 8 * sizeof(TELEM));

		if (GetBit(g) != 0)
		{

			break;
		}
	}
	//std::cout << (h + ((i) * 8 * sizeof(TELEM)) + 1) << std::endl;
	//system("pause");

	return (h + ((i) * 8 * sizeof(TELEM)) + 1);

}

TBitField& TBitField :: operator=(const TBitField& bf)
{
	BitLen = bf.BitLen;
	if (MemLen != bf.MemLen)
	{
		MemLen = bf.MemLen;
		if (pMem != NULL)delete pMem;
		pMem = new TELEM[MemLen];
	}
	if (pMem != NULL)
		for (int i = 0; i < bf.MemLen; i++) pMem[i] = bf.pMem[i];
	return *this;
}
int TBitField :: operator==(const TBitField& bf)
{
	int res = 1;
	if (BitLen != bf.BitLen) res = 0;
	else
		for (int i = 0; i < bf.MemLen; i++)
			if (pMem[i] != bf.pMem[i])
			{
				res = 0;
				break;
			}
	return res;
}
TBitField TBitField::operator|(const TBitField& bf)
{
	int i, len = BitLen;
	if (bf.BitLen > len)len = bf.BitLen;
	TBitField temp(len);
	for (i = 0; i < MemLen; i++)temp.pMem[i] = pMem[i];
	for (i = 0; i < bf.MemLen; i++)temp.pMem[i] |= bf.pMem[i];
	return temp;
}
TBitField TBitField::operator&(const TBitField& bf)
{
	int i, len = BitLen;
	if (bf.BitLen > len)len = bf.BitLen;
	TBitField temp(len);
	for (i = 0; i < MemLen; i++)temp.pMem[i] = pMem[i];
	for (i = 0; i < bf.MemLen; i++)temp.pMem[i] &= bf.pMem[i];
	return temp;
}
TBitField TBitField :: operator~(void)
{
	int len = BitLen;
	TBitField temp(len);
	for (int i = 0; i < MemLen; i++) temp.pMem[i] = ~pMem[i];
	return temp;
}
std::istream& operator >> (std::istream& istr, TBitField& bf)
{
	int i = 0; char ch;
	do { istr >> ch; } while (ch != ' ');
	while (1) { istr >> ch; if (ch == '0')bf.ClrBit(i++); else if (ch == '1')bf.SetBit(i++); else break; }
	return istr;
}

std::ostream& operator<<(std::ostream& ostr, const TBitField& bf)
{
	int len = bf.GetLength();
	for (int i = 0; i < len; i++)
	{
		if (bf.GetBit(i))ostr << '1'; else ostr << '0';
	}
	return ostr;
}
#include <iomanip>

#include <conio.h>
#include"bitfield.h"
#include"Set.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, ("rus"));
	int n, m, k, count;
	cout << "������������ �������� ��������� ������� ���������" << endl;
	cout << "������� ����������" << endl;
	cout << "������� ������� ������� ����� �������� - ";
	cin >> n;
	Set s(n + 1);
	for (m = 2; m <= n; m++)s.InsElem(m);
	for (m = 2; m * m <= n; m++)
		if (s.IsMember(m))
			for (k = 2 * m; k <= n; k += m)
				if (s.IsMember(k)) s.DelElem(k);
	cout << "������ ������� �����" << endl;
	count = 0; k = 1;
	for (m = 2; m <= n; m++)
		if (s.IsMember(m))
		{
			count++;
			cout << setw(3) << m << " ";
			if (k++ % 10 == 0)cout << endl;
		}
	cout << endl;
	cout << "� ������ " << n << " ������ " << count << " ������� " << endl;
	int F;
	cout << "�������� �������" << endl;
	cin >> F;
	s = s + F;
	cout << s.GetMaxPower()<<endl;
	cout << s << endl;

	cout << "������� �������" << endl;
	cin >> F;
	s = (s - F);

	cout << s.GetMaxPower() << endl;
	cout << s;
	system("pause");
	return 0;
}

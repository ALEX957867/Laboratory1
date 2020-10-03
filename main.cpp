#include <iomanip>

#include <conio.h>
#include"bitfield.h"
#include"Set.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, ("rus"));
	int n, m, k, count;
	cout << "Тестирование программ поддержки понития множества" << endl;
	cout << "Решение Эратосфена" << endl;
	cout << "Введите верхнюю границу целых значений - ";
	cin >> n;
	Set s(n + 1);
	for (m = 2; m <= n; m++)s.InsElem(m);
	for (m = 2; m * m <= n; m++)
		if (s.IsMember(m))
			for (k = 2 * m; k <= n; k += m)
				if (s.IsMember(k)) s.DelElem(k);
	cout << "Печать простых чисел" << endl;
	count = 0; k = 1;
	for (m = 2; m <= n; m++)
		if (s.IsMember(m))
		{
			count++;
			cout << setw(3) << m << " ";
			if (k++ % 10 == 0)cout << endl;
		}
	cout << endl;
	cout << "В первых " << n << " числах " << count << " простых " << endl;
	int F;
	cout << "Добавьте элемент" << endl;
	cin >> F;
	s = s + F;
	cout << s.GetMaxPower()<<endl;
	cout << s << endl;

	cout << "Уберите элемент" << endl;
	cin >> F;
	s = (s - F);

	cout << s.GetMaxPower() << endl;
	cout << s;
	system("pause");
	return 0;
}

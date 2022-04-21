#include <iostream>
using namespace std;

double f(double x)
{
	return x * x + 6 * x + 13;
}

int main() {
	double a = -6, b = 4; // Интервал неопределенности [a0, b0]
	double e = 0.5; // Погрешность эпсилон
	double l = 2 * e; // Точность l
	double d = 0.2; // Дельта
	double k = 0; // Предположение
	double y, z;
	double L;

	setlocale(LC_ALL, "Russian");
	cout << "Шаг 1. Зададим начальный интервал неопределенности L0 = [a0, b0]." << endl; 
	cout << "Начальный интервал неопределенности [" << a << ", " << b << "]" << endl;
	cout << "Зададим допустимую и предельную погрешность." << endl;
	cout << "Eps = " << e << endl;
	cout << "Точность l = " << l << endl;
	cout << "Delta = " << d << endl;
	cout << endl;

	if (e < d)
	{
		cout << "Предельная погрешность должна быть << допустимой погрешности!" << endl;
		return 0;
	}

	cout << "Шаг 2. Положим k = " << k << endl;
	cout << endl;

	while ((b - a) > l)
	{
		cout << "Шаг 3. Вычислим Ук, Zк, f(Ук), f(Zк): " << endl;
		y = (a + b - d) / 2;
		cout << "y(k) = " << y << endl;
		z = (a + b + d) / 2;
		cout << "z(k) = " << z << endl;
		cout << "f(y) = " << f(y) << ", " << "f(z) =  " << f(z) << endl;
		cout << endl;
		cout << "Шаг 4. Сравним f(Ук) с f(Zк): " << endl;
		if (f(y) <= f(z))
		{
			cout << "Условие а) выполняется!" << endl;
			a = a;
			b = z;
			cout << "a(k+1) = a(k) = " << a << endl;
			cout << "b(k+1) = z(k) =" << b << endl;
			cout << endl;
			cout << "Шаг 5. Вычислим |L2(k+1)|=|b(k+1)-a(k+1)| и проверим условие окончания:" << endl;
			L = abs(b - a);
			cout << "L =" << L << endl;
			if (L <= l)
			{
				cout << " L <= l, Процесс поиска завершен! Точка минимума принадлежит интервалу:" << endl;
				cout << a << " " << b << endl;
				cout << "Минимум функции равен : " << (a + b) / 2 << endl;
			}
			else
			{
				cout << "L > l, Положим k = k+1 и вернемся к шагу 3" << endl;
				k++;
				cout << "k = " << k << endl;
				cout << endl;
			}
		}
		else
			if (f(y) > f(z))
			{
				cout << "Условие б) выполняется!" << endl;
				a = y;
				b = b;
				cout << "a(k+1) = y(k) = " << a << endl;
				cout << "b(k+1) = b(k) = " << b << endl;
				cout << endl;
				cout << "Шаг 5. Вычислим |L2(k+1)|=|b(k+1)-a(k+1)|:" << endl;
				double L = abs(b - a);
				cout << "L =" << L << endl;
				if (L <= l)
				{
					cout << "L <= l, Процесс поиска завершен! Точка минимума принадлежит интервалу:" << endl;
					cout << a << " " << b << endl;
					cout << "Минимум функции равен : " << (a + b) / 2 << " +- " << (b - a) / 2 << endl;
				}
				else
				{
					cout << "L > l, Положим k = k+1 и вернемся к шагу 3" << endl;
					k++;
					cout << "k = " << k << endl;
					cout << endl;
				}
			}
	}
	system("pause");
	return 0;
}
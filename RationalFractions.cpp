#include "RationalFractions.h"
#include <cstdlib>
#include <Windows.h>
#include<fstream>

void menu(RationalFractions &f1, RationalFractions &f2, Rezult &r, MixedFraction &m);//главное меню
int select();
void setMenu(char* fname1, char* fname2, int &a, int &b, int &c, int &d); //меню ввода данных
void setFile(char *fname1, char *fname2, int &a, int &b, int &c, int &d);//ввод данных из файла
void setKeyboard(char *fname1, char *fname2, int &a, int &b, int &c, int &d);//ввод данных с клавиатуры
void redactMenu(RationalFractions &f1, RationalFractions &f2, Rezult &r);//меню редактирования дробей
void edition(int c, RationalFractions &f1, RationalFractions &f2);// редактирование числителя и знаменателя
void newFractions(RationalFractions &f1, RationalFractions  &f2);//ввод новых дробей

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num1, num2, den1, den2;
	int s1 = 20;
	int s2 = 20;
	char *fname1 = new char[s1];
	char *fname2 = new char[s2];
	setMenu(fname1, fname2, num1, den1, num2, den2);
	RationalFractions fract1(fname1, num1, den1);
	RationalFractions fract2(fname2, num2, den2);
	Rezult rez;
	MixedFraction mix;
	menu(fract1, fract2, rez, mix);
	delete[] fname1;
	delete[] fname2;
}

void menu(RationalFractions &f1, RationalFractions &f2, Rezult &r, MixedFraction &m)
{
	int a;
	do {
		system("cls");
		char buff[50];
		ifstream in("menu.txt");
		try {
			if (!in)
			{
				throw 404;
			}
			while (!in.eof())// пока не достигнут конец файла (eof)
			{
				in.getline(buff, 50);
				cout << buff << endl;//вывод меню из файла на экран
			}
			in.close(); // закрываем файл
		}
		catch (int x)
		{
			cout << "ОШИБКА! Файл меню не найден! Нажмите 0 для выхода из программы!" << endl;
		}
		a = select();
		system("cls");
		if (a == 1)
		{
			try
			{
				m = f1 + f2;
				r = f1 + f2;
				cout << f1 << "+ " << f2 << "= " << m << " или " << r << endl;
			}
			catch (int x)
			{
				if (x == 1)
				{
					cout << "ОШИБКА! Знаменатель первой дроби = 0!" << endl;
				}
				if (x == 2)
				{
					cout << "ОШИБКА! Знаменатель второй дроби = 0!" << endl;
				}
				if (x == 3)
				{
					cout << "ОШИБКА! Знаменатели = 0!" << endl;
				}
			}
		}
		else if (a == 2)
		{
			try
			{
				m = f1 - f2; //используем перегруженный оператор присваивания и перегруженный оператор вычитания
				r = f1 - f2;
				cout << f1 << "- " << f2 << "= " << m << " или " << r << endl;
			}
			catch (int x)
			{
				if (x == 1)
				{
					cout << "ОШИБКА! Знаменатель первой дроби = 0!" << endl;
				}
				if (x == 2)
				{
					cout << "ОШИБКА! Знаменатель второй дроби = 0!" << endl;
				}
				if (x == 3)
				{
					cout << "ОШИБКА! Знаменатели = 0!" << endl;
				}
			}
		}
		else if (a == 3)
		{
			try
			{
				m = f1 * f2;
				r = f1 * f2;
				cout << f1 << "* " << f2 << "= " << m << " или " << r << endl;
			}
			catch (int x)
			{
				if (x == 1)
				{
					cout << "ОШИБКА! Знаменатель первой дроби = 0!" << endl;
				}
				if (x == 2)
				{
					cout << "ОШИБКА! Знаменатель второй дроби = 0!" << endl;
				}
				if (x == 3)
				{
					cout << "ОШИБКА! Знаменатели = 0!" << endl;
				}
			}
		}
		else if (a == 4)
		{
			try
			{
				m = f1 / f2;
				r = f1 / f2;
				cout << f1 << "/ " << f2 << "= " << m << " или " << r << endl;
			}
			catch (int x)
			{
				if (x == 1)
				{
					cout << "ОШИБКА! Знаменатель первой дроби = 0!" << endl;
				}
				if (x == 2)
				{
					cout << "ОШИБКА! Знаменатель второй дроби = 0!" << endl;
				}
				if (x == 3)
				{
					cout << "ОШИБКА! Знаменатели = 0!" << endl;
				}
			}
		}
		else if (a == 5)
		{
			try
			{
				bool b = f1 == f2;
				if (b == true)
				{
					cout << "Дроби равны" << endl;
				}
				else
				{
					cout << "Дроби не равны" << endl;
				}
			}
			catch (int x)
			{
				if (x == 1)
				{
					cout << "ОШИБКА! Знаменатель первой дроби = 0!" << endl;
				}
				if (x == 2)
				{
					cout << "ОШИБКА! Знаменатель второй дроби = 0!" << endl;
				}
				if (x == 3)
				{
					cout << "ОШИБКА! Знаменатели = 0!" << endl;
				}
			}
		}
		else if (a == 6)
		{
			//вывод на экран (используем виртуальные функции)
			f1.getFraction();
			f2.getFraction();
			r.getFraction();
			m.getFraction();
			//вывод в файл
			ofstream out("dataFractions.txt");
			out << f1.getNameFraction() << "\t" << f1.getNumerator() << "\t" << f1.getDenominator() << endl;
			out << f2.getNameFraction() << "\t" << f2.getNumerator() << "\t" << f2.getDenominator() << endl;
			out << r.getNameFraction() << "\t" << r << endl;
			out << m.getNameFraction() << "\t" << m << endl;
			out.close();
		}
		else if (a == 7)
		{
			redactMenu(f1, f2, r);
		}
		else if (a == 8)
		{
			newFractions(f1, f2);
			cout << "Данные загружены" << endl;
		}
		else if (a == 0)
		{
			break;
		}
		system("pause");
	} while (a != 0);
}

int select()
{
	int x;
	cin >> x;
	return x;
}

void setMenu(char *fname1, char *fname2, int &a, int &b, int &c, int &d)//меню первоначального ввода дробей
{
	int i;
	do {
		cout << "Выберите способ ввода данных:" << endl;
		cout << "1 - из файла" << endl;
		cout << "2 - с клавиатуры" << endl;
		i = select();
		if (i == 1)
		{
			try {
				setFile(fname1, fname2, a, b, c, d);
				cout << "Данные из файла загружены" << endl;


			}
			catch (int x) {
				cout << "Файл не найден" << endl;
				cout << "Выберите пункт [8] и введите данные с клавиатуры!" << endl;
			}
			system("pause");
		}
		else if (i == 2)
		{
			setKeyboard(fname1, fname2, a, b, c, d);
		}
	} while ((i != 1) && (i != 2));
}

void redactMenu(RationalFractions &f1, RationalFractions &f2, Rezult &r)//меню редактирования дробей
{
	int c;
	do {
		system("cls");
		cout << "Укажите, какое значение дроби требуется редактировать:" << endl;
		cout << "[1] - имя первой дроби\n[2] - имя второй дроби\n[3] - имя результата" << endl;
		cout << "[4] - числитель первой дроби\n[5] - числитель второй дроби" << endl;
		cout << "[6] - знаменатель первой дроби\n[7] - знаменатель второй дроби\n[0] - выход" << endl;
		c = select();
		if (c == 1)
		{

			char *name = new char[20];
			cout << "Введите имя первой дроби:" << endl;
			cin >> name;
			f1.setNameFraction(name);
			delete[] name;
		}
		if (c == 2)
		{
			char *name = new char[20];
			cout << "Введите имя второй дроби:" << endl;
			cin >> name;
			f2.setNameFraction(name);
			delete[] name;
		}
		if (c == 3)
		{
			char *name = new char[20];
			cout << "Введите имя результата:" << endl;
			cin >> name;
			r.setNameFraction(name);
			delete[] name;
		}
		if ((c >= 4) && (c <= 7))
		{
			edition(c, f1, f2);
		}
		if (c == 0)
		{
			break;
		}
		cout << "Изменения внесены" << endl;
		system("pause");
	} while (c != 0);
}

void edition(int c, RationalFractions &f1, RationalFractions &f2)//редактирование числителя и знаменателя
{
	int n;
	if ((c == 4) || (c == 5))
	{
		cout << "Введите новое значение числителя" << endl;
		cin >> n;
		if (c == 4)
		{
			f1.setNumerator(n);
		}
		else
		{
			f2.setNumerator(n);
		}
	}
	if ((c == 6) || (c == 7))
	{
		cout << "Введите новое значение знаменателя" << endl;
		cin >> n;
		if (c == 6)
		{
			f1.setDenominator(n);
		}
		else
		{
			f2.setDenominator(n);
		}
	}
}

void newFractions(RationalFractions &f1, RationalFractions  &f2)
{
	int a, b, c, d;
	char *name1 = new char[20];
	cout << "Введите имя первой дроби:" << endl;
	cin >> name1;
	f1.setNameFraction(name1);
	delete[] name1;
	cout << "Введите первую дробь:" << endl;
	cin >> a;
	f1.setNumerator(a);
	cout << "/" << endl;
	cin >> b;
	f1.setDenominator(b);
	char *name2 = new char[20];
	cout << "Введите имя второй дроби:" << endl;
	cin >> name2;
	f2.setNameFraction(name2);
	delete[] name2;
	cout << "Введите вторую дробь" << endl;
	cin >> c;
	f2.setNumerator(c);
	cout << "/" << endl;
	cin >> d;
	f2.setDenominator(d);
}

void setFile(char *fname1, char *fname2, int &a, int &b, int &c, int &d)//ввод данных из файла
{
	char buff[20];
	int t;
	ifstream in("inDataFractions.txt");
	if (!in)
	{
		throw 404;
	}
	in >> buff;
	strcpy_s(fname1, 20, buff);
	in >> t;
	a = t;
	in >> t;
	b = t;
	in >> buff;
	strcpy_s(fname2, 20, buff);
	in >> t;
	c = t;
	in >> t;
	d = t;
	in.close();
}

void setKeyboard(char *fname1, char *fname2, int &a, int &b, int &c, int &d)//ввод данных с клавиатуры
{
	cout << "Введите имя первой дроби:" << endl;
	cin >> fname1;
	cout << "Введите первую дробь:" << endl;
	cin >> a;
	cout << "/" << endl;
	cin >> b;
	cout << "Введите имя второй дроби:" << endl;
	cin >> fname2;
	cout << "Введите вторую дробь" << endl;
	cin >> c;
	cout << "/" << endl;
	cin >> d;
}
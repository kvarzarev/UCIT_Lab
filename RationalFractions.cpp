#include "RationalFractions.h"
#include <cstdlib>
#include <Windows.h>
#include<fstream>

void menu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3);//главное меню
int select();
void setMenu(char* fname1, char* fname2, int &a, int &b, int &c, int &d); //меню ввода данных
void setFile(char *fname1, char *fname2, int &a, int &b, int &c, int &d);//ввод данных из файла
void setKeyboard(char *fname1, char *fname2, int &a, int &b, int &c, int &d);//ввод данных с клавиатуры
void outResult(int a, RationalFractions &f1, RationalFractions &f2, RationalFractions &f3); //вывод результатов вычислений
void setMenu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3);//меню редактирования дробей
void edition(int c, RationalFractions &f1, RationalFractions &f2);// редактирование числителя и знаменателя
void newFractions(RationalFractions &f1, RationalFractions  &f2, RationalFractions  &f3);//ввод новых дробей

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
	RationalFractions fract3(1, 1);
	menu(fract1, fract2, fract3);
	delete[] fname1;
	delete[] fname2;
}

void menu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3)
{
	int a;
	do {
		system("cls");
		char buff[50];
		ifstream in("menu.txt");
		while (!in.eof())// пока не достигнут конец файла (eof)
		{
			in.getline(buff, 50);
			cout << buff << endl;//вывод меню из файла на экран
		}
		in.close(); // закрываем файл
		ofstream out("menu.txt");
		out << "Выберите действие с дробями:" << endl;
		out << "[1] - сложение\n[2] - вычитание\n[3] - умножение\n[4] - деление\n[5] - сравнение '=='" << endl;
		out << "[6] - вывод дробей на экран\n[7] - редактирование дробей\n[8] - повторный ввод дробей\n[0] - выход" << endl;
		out.close();
		a = select();
		system("cls");
		if (a == 1)
		{
			f3 = f1 + f2; //используем перегруженный оператор присваивания и перегруженный оператор сложения
			outResult(a, f1, f2, f3);
		}
		else if (a == 2)
		{
			f3 = f1 - f2; //используем перегруженный оператор присваивания и перегруженный оператор вычитания
			outResult(a, f1, f2, f3);
		}
		else if (a == 3)
		{
			f3 = f1 * f2; //используем перегруженный оператор присваивания и перегруженный оператор умножения
			outResult(a, f1, f2, f3);
		}
		else if (a == 4)
		{
			f3 = f1 / f2; //используем перегруженный оператор присваивания и перегруженный оператор деления
			outResult(a, f1, f2, f3);
		}
		else if (a == 5)
		{
			bool b = f1 == f2; // используем перегруженный оператор сравнения
			if (b == true)
			{
				cout << "Дроби равны" << endl;
			}
			else
			{
				cout << "Дроби не равны" << endl;
			}
		}
		else if (a == 6)
		{
			//вывод на экран
			cout << f1.getNameFraction() << " " << f1.getNumerator() << "/" << f1.getDenominator() << endl;
			cout << f2.getNameFraction() << " " << f2.getNumerator() << "/" << f2.getDenominator() << endl;
			cout << f3.getNameFraction() << " " << f3.getNumerator() << "/" << f3.getDenominator() << endl;
			//вывод в файл
			ofstream out("dataFractions.txt"); //, ios_base::app);
			out << f1.getNameFraction() << "\t" << f1.getNumerator() << "\t" << f1.getDenominator() << endl;
			out << f2.getNameFraction() << "\t" << f2.getNumerator() << "\t" << f2.getDenominator() << endl;
			out << f3.getNameFraction() << "\t" << f3.getNumerator() << "\t" << f3.getDenominator() << endl;
			out.close();
		}
		else if (a == 7)
		{
			setMenu(f1, f2, f3);
		}
		else if (a == 8)
		{
			newFractions(f1, f2, f3);
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
			setFile(fname1, fname2, a, b, c, d);
			cout << "Данные из файла загружены" << endl;
			system("pause");
		}
		else if (i == 2)
		{
			setKeyboard(fname1, fname2, a, b, c, d);
		}
	} while ((i != 1) && (i != 2));
}

void outResult(int a, RationalFractions &f1, RationalFractions &f2, RationalFractions &f3)
{
	RationalFractions rezF(f3);
	cout << f1; // используем перегруженный оператор вывода данных из потока
				//f1.getFraction(); // вместо метода вывода дроби на экран
	if (a == 1)
	{
		cout << " + ";
	}
	else if (a == 2)
	{
		cout << " - ";
	}
	else if (a == 3)
	{
		cout << " * ";
	}
	else if (a == 4)
	{
		cout << " / ";
	}
	cout << f2; // используем перегруженный оператор вывода данных из потока
				//f2.getFraction(); // вместо метода вывода дроби на экран
	cout << " = ";
	cout << rezF; // используем перегруженный оператор вывода данных из потока
				  //rezF.getResult(); // вместо метода вывода дроби на экран
	cout << "  или " << (double)f3 << endl; // используем перегруженный оператор приведения к типу double
}

void setMenu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3)//меню редактирования дробей
{
	int c;
	do {
		system("cls");
		cout << "Укажите, какое значение дроби требуется редактировать:" << endl;
		cout << "[1] - имя первой дроби\n[2] - имя второй дроби\n[3] - имя третьей дроби" << endl;
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
			cout << "Введите имя третьей дроби:" << endl;
			cin >> name;
			f3.setNameFraction(name);
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

void newFractions(RationalFractions &f1, RationalFractions  &f2, RationalFractions  &f3)
{
	char buff[20];
	int a;
	ifstream in("dataFractions.txt");
	in >> buff;
	f1.setNameFraction(buff);
	in >> f1; //используем перегруженный оператор для ввода данных в поток
	in >> buff;
	f2.setNameFraction(buff);
	in >> f2; //используем перегруженный оператор для ввода данных в поток
	in >> buff;
	f3.setNameFraction(buff);
	in >> f3; //используем перегруженный оператор для ввода данных в поток
	in.close();
}

void setFile(char *fname1, char *fname2, int &a, int &b, int &c, int &d)//ввод данных из файла
{
	char buff[20];
	int t;
	ifstream in("inDataFractions.txt");
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
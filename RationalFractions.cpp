#include "RationalFractions.h"
#include <cstdlib>
#include <Windows.h>

void menu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3);//главное меню
int select(); 
void setData(char* fname1, char* fname2, int &a, int &b, int &c, int &d); //ввод данных
void outResult(int a, RationalFractions f1, RationalFractions f2, RationalFractions f3); //вывод результатов вычислений
void setMenu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3);//меню редактировани¤ дробей
void edition(int c, RationalFractions &f1, RationalFractions &f2);// редактирование числител¤ и знаменател¤
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
	setData(fname1, fname2, num1, den1, num2, den2);
	RationalFractions fract1(fname1, s1, num1, den1);
	RationalFractions fract2(fname2, s2, num2, den2);
	RationalFractions fract3(1,1);
	menu(fract1, fract2, fract3);
	delete[] fname1;
	delete[] fname2;
}

void menu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3)
{
	system("pause");
	int a;
		do {
			system("cls");
			cout << "[1] - сложение\n[2] - вычитание\n[3] - умножение\n[4] - деление\n[5] - сравнение '=='" << endl;
			cout << "[6] - вывод дробей на экран\n[7] - редактирование дробей\n[8] - ввод новых дробей\n[0] - выход" << endl << endl;
			a = select();
			system("cls");
			if (a == 1)
			{
				RationalFractions tmp = f1.addition(f2);
				outResult(a, f1, f2, tmp);
				f3.setNumerator(tmp.getNumerator());
				f3.setDenominator(tmp.getDenominator());
			}
			else if (a == 2)
			{
				RationalFractions tmp = f1.subtraction(f2);
				outResult(a, f1, f2, tmp);
				f3.setNumerator(tmp.getNumerator());
				f3.setDenominator(tmp.getDenominator());
			}
			else if (a == 3)
			{
				RationalFractions tmp =f1.multiplication(f2);
				outResult(a, f1, f2, tmp);
				f3.setNumerator(tmp.getNumerator());
				f3.setDenominator(tmp.getDenominator());
			}
			else if (a == 4)
			{
				RationalFractions tmp =f1.separation(f2);
				outResult(a, f1, f2, tmp);
				f3.setNumerator(tmp.getNumerator());
				f3.setDenominator(tmp.getDenominator());
			}
			else if (a == 5)
			{
				bool b = f1.compare(f2);
				if (b == true)
				{
					cout << "ƒроби равны" << endl;
				}
				else
				{
					cout << "ƒроби не равны" << endl;
				}
			}
			else if (a == 6)
			{
				cout << f1.getNameFraction() << " " << f1.getNumerator() << "/" << f1.getDenominator() << endl;
				cout << f2.getNameFraction() << " " << f2.getNumerator() << "/" << f2.getDenominator() << endl;
				cout << f3.getNameFraction() << " " << f3.getNumerator() << "/" << f3.getDenominator() << endl;
			}
			else if (a == 7)
			{
				setMenu(f1, f2, f3);
			}
			else if (a == 8)
			{
				newFractions(f1,f2);
			}
			else if (a == 0)
			{
				break;
			}
			system("pause");
	} while (a!=0);
}

int select()
{
	int x;
	cin >> x;
	return x;
}

void setData(char *fname1, char* fname2, int &a, int &b, int &c, int &d)//первоначальный ввод дробей
{
	cout << "¬ведите им¤ первой дроби:" << endl;
	cin >> fname1;
	cout << "¬ведите первую дробь:" << endl;
	cin >> a;
	cout << "/"<<endl;
	cin >> b;
	cout << "¬ведите им¤ второй дроби:" << endl;
	cin >> fname2;
	cout << "¬ведите вторую дробь" << endl;
	cin >> c;
	cout << "/"<<endl;
	cin >> d;
}

void outResult(int a, RationalFractions f1, RationalFractions f2, RationalFractions f3)
{
	RationalFractions rezF(f3);
	f1.getFraction();
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
	f2.getFraction();
	cout << " = ";
	rezF.getResult();
	cout << "  или " << f3.decimal() << endl;
}

void setMenu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3)//меню редактировани¤ дробей
{
	
	int c;
	do {
		system("cls");
		cout << "”кажите, какое значение дроби требуетс¤ редактировать:" << endl;
		cout << "[1] - им¤ первой дроби\n[2] - им¤ второй дроби\n[3] - им¤ третьей дроби" << endl;
		cout << "[4] - числитель первой дроби\n[5] - числитель второй дроби" << endl;
		cout << "[6] - знаменатель первой дроби\n[7] - знаменатель второй дроби\n[0] - выход" << endl;
		c = select();
		if (c == 1)
		{
			char* name = new char[20];
			cout << "Введите имя первой дроби:" << endl;
			cin >> name;
			f1.setNameFraction(name);
			delete[] name;
		}
		if (c == 2)
		{
			char* name = new char[20];
			cout << "Введите имя второй дроби:" << endl;
			cin >> name;
			f2.setNameFraction(name);
			delete[] name;
		}
		if (c == 3)
		{
			char* name = new char[20];
			cout << "Введите имя третьей дроби:" << endl;
			сin >> name;
			f3.setNameFraction(name);
			delete[] name;
		}
		if ((c>=4)&&(c<=7))
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

void edition(int c, RationalFractions &f1, RationalFractions &f2)//редактирование числител¤ и знаменател¤
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
		cout << "¬ведите новое значение знаменател¤" << endl;
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
	cout << "¬ведите первую дробь:" << endl;
	cin >> a;
	f1.setNumerator(a);
	cout << "/" << endl;
	cin >> b;
	f1.setDenominator(b);
	cout << "¬ведите вторую дробь" << endl;
	cin >> c;
	f2.setNumerator(c);
	cout << "/" << endl;
	cin >> d;
	f2.setDenominator(d);
}

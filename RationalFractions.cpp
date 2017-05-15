#include "RationalFractions.h"
#include <cstdlib>
#include <Windows.h>

void menu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3);//������� ����
int select(); 
void setData(char* fname1, char* fname2, int &a, int &b, int &c, int &d); //���� ������
void outResult(int a, RationalFractions f1, RationalFractions f2, RationalFractions f3); //����� ����������� ����������
void setMenu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3);//���� �������������� ������
void edition(int c, RationalFractions &f1, RationalFractions &f2);// �������������� ��������� � �����������
void newFractions(RationalFractions &f1, RationalFractions  &f2);//���� ����� ������

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
			cout << "[1] - ��������\n[2] - ���������\n[3] - ���������\n[4] - �������\n[5] - ��������� '=='" << endl;
			cout << "[6] - ����� ������ �� �����\n[7] - �������������� ������\n[8] - ���� ����� ������\n[0] - �����" << endl << endl;
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
					cout << "����� �����" << endl;
				}
				else
				{
					cout << "����� �� �����" << endl;
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

void setData(char *fname1, char* fname2, int &a, int &b, int &c, int &d)//�������������� ���� ������
{
	cout << "������� ��� ������ �����:" << endl;
	cin >> fname1;
	cout << "������� ������ �����:" << endl;
	cin >> a;
	cout << "/"<<endl;
	cin >> b;
	cout << "������� ��� ������ �����:" << endl;
	cin >> fname2;
	cout << "������� ������ �����" << endl;
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
	cout << "  ��� " << f3.decimal() << endl;
}

void setMenu(RationalFractions &f1, RationalFractions &f2, RationalFractions &f3)//���� �������������� ������
{
	
	int c;
	do {
		system("cls");
		cout << "�������, ����� �������� ����� ��������� �������������:" << endl;
		cout << "[1] - ��� ������ �����\n[2] - ��� ������ �����\n[3] - ��� ������� �����" << endl;
		cout << "[4] - ��������� ������ �����\n[5] - ��������� ������ �����" << endl;
		cout << "[6] - ����������� ������ �����\n[7] - ����������� ������ �����\n[0] - �����" << endl;
		c = select();
		if (c == 1)
		{
			char name[20];
			cout << "������� ��� ������ �����:" << endl;
			cin >> name;
			f1.setNameFraction(name);
		}
		if (c == 2)
		{
			cout << "������� ��� ������ �����:" << endl;
			char name[20];
			cin >> name;
			f2.setNameFraction(name);
		}
		if (c == 3)
		{
			cout << "������� ��� ������� �����:" << endl;
			char name[20];
			cin >> name;
			f3.setNameFraction(name);
		}
		if ((c>=4)&&(c<=7))
		{
			edition(c, f1, f2);
		}
		if (c == 0)
		{
			break;
		}
		cout << "��������� �������" << endl;
		system("pause");
	} while (c != 0);
}

void edition(int c, RationalFractions &f1, RationalFractions &f2)//�������������� ��������� � �����������
{
	int n;
	if ((c == 4) || (c == 5))
	{
		cout << "������� ����� �������� ���������" << endl;
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
		cout << "������� ����� �������� �����������" << endl;
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
	cout << "������� ������ �����:" << endl;
	cin >> a;
	f1.setNumerator(a);
	cout << "/" << endl;
	cin >> b;
	f1.setDenominator(b);
	cout << "������� ������ �����" << endl;
	cin >> c;
	f2.setNumerator(c);
	cout << "/" << endl;
	cin >> d;
	f2.setDenominator(d);
}
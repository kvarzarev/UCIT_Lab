#include "RationalFractions.h"

int RationalFractions::count = 0; // �������������� ������� Count

RationalFractions::RationalFractions()// ����� ��� ������������ �� ���������
{
	//cout << "Constructor-defolt\n";
	nameFraction = new char[100];
	strcpy_s (nameFraction, 100, "Empty ");
	numerator = 0;
	denominator = 1;
	count++;
}

RationalFractions::RationalFractions(char* name, int size, int num, int den)// ����� ��� ������������ � ����������� -1
{
	//cout << "Constructor\n";
	nameFraction = new char[size];
	strcpy_s (nameFraction, size, name);
	numerator = num;
	if (den != 0) {
		denominator = den;
	}
	else { denominator = 1; }
	count++;
}

RationalFractions::RationalFractions(int num, int den)// ����� ��� ������������ � �����������-2
{
	//cout << "Constructor\n";
	nameFraction = new char[100];
	strcpy_s(nameFraction, 100, "Rezult");
	numerator = num;
	if (den != 0) {
		denominator = den;
	}
	else { denominator = 1; }
	count++;
}

RationalFractions::RationalFractions(const RationalFractions& fraction)//����� ��� ������������ �����������
{
	//cout<<"Constructor-copy"<<endl;
	nameFraction = new char[strlen(fraction.nameFraction)+1];
	strcpy_s(nameFraction, strlen(fraction.nameFraction) + 1, fraction.nameFraction);
	numerator = fraction.numerator;
	denominator = fraction.denominator;
	count++;
}

RationalFractions::~RationalFractions()//����� ��� �����������
{
	//cout << "Destructor!\n";
	count--;
	delete[] nameFraction;
}

int RationalFractions::GetCount() //������� Count 
{ 
	return count; 
}

void RationalFractions::getFraction()//����� ������
{
	cout << numerator << "/" << denominator;
}

void RationalFractions::getResult()//����� ����������� ���������� � ���� ���������� ������� �����
{
	int whole;
	if (numerator >= denominator)
	{
		whole = numerator / denominator;
		numerator = numerator % denominator;
		cout << whole <<" " << numerator << "/" << denominator;
	}
	else
	{
		cout << numerator << "/" << denominator;
	}
}

void RationalFractions::reduction()//���������� �����
{
	int nod = NOD(numerator, denominator);
	numerator = numerator / nod;
	denominator = denominator / nod;
}

int RationalFractions::NOD(int den1, int den2)//���������� ����� ��������
{
	while (den1 != den2)
	{
		if (den1 > den2) { den1 -= den2; }
		else { den2 -= den1; }
	}
	return den1;
}

int RationalFractions::NOK(int den1, int den2)//���������� ����� �������
{
	if ((den1 > den2) && (den1 % den2 == 0)) 
	{ return den1; }
	else if ((den1 < den2) && (den2 % den1 == 0)) 
	{ return den2; }
	else
		return den1*den2 / NOD(den1, den2);
}

RationalFractions RationalFractions::addition(RationalFractions & F)// �������� ������
{
	RationalFractions tmp;
	if (denominator != F.denominator)
	{
		int nok = NOK(denominator, F.denominator);
		tmp.numerator = (numerator * (nok / denominator) + F.numerator * (nok / F.denominator));
		tmp.denominator = nok;
	}
	else
	{
		tmp.numerator = numerator + F.numerator;
		tmp.denominator = denominator;
	}
	tmp.reduction();
	return tmp;
}

RationalFractions RationalFractions::subtraction(RationalFractions & F)//��������� ������
{
	RationalFractions tmp;
	if (denominator != F.denominator)
	{
		int nok = NOK(denominator, F.denominator);
		tmp.numerator = (numerator * (nok / denominator) - F.numerator * (nok / F.denominator));
		tmp.denominator = nok;
	}
	else
	{
		tmp.numerator = numerator - F.numerator;
		tmp.denominator = denominator;
	}
	tmp.reduction();
	return tmp;
}

RationalFractions RationalFractions::multiplication(RationalFractions &F)//��������� ������
{
	RationalFractions tmp;
	tmp.numerator = numerator * F.numerator;
	tmp.denominator = denominator * F.denominator;
	tmp.reduction();
	return tmp;
}

RationalFractions RationalFractions::separation(RationalFractions &F)//������� ������
{
	RationalFractions tmp;
	tmp.numerator = numerator * F.denominator;
	tmp.denominator = denominator * F.numerator;
	tmp.reduction();
	return tmp;
}

bool RationalFractions::compare(RationalFractions &F)//��������� ������
{
	if (((double)numerator / (double)denominator) == ((double)F.numerator / (double)F.denominator))
	{
		return true;
	}
	else
	{
		return false;
	}
}

double RationalFractions::decimal() // �������������� ������� ����� � ����������
{
	double result = (double)numerator / (double)denominator;
	return result;
}

void RationalFractions::setNameFraction(char *name)
{
	strcpy_s (nameFraction, 20, name);
}

void RationalFractions::setNumerator(int num)//�������� ���������
{
	numerator = num;
}

void RationalFractions::setDenominator(int den)//�������� �����������
{
	denominator = den;
}

char *RationalFractions::getNameFraction()
{
	return nameFraction;
}

int RationalFractions::getDenominator()
{
	return denominator;
}

int RationalFractions::getNumerator()
{
	return numerator;
}

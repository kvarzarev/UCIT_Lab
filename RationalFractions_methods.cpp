#include "RationalFractions.h"

int RationalFractions::count = 0; // Инициализируем счетчик Count

RationalFractions::RationalFractions()// метод для конструктора по умолчанию
{
	//cout << "Constructor-defolt\n";
	nameFraction = new char[100];
	strcpy_s(nameFraction, 100, "Empty");
	numerator = 0;
	denominator = 1;
	count++;
}

RationalFractions::RationalFractions(char* name, int num, int den)// метод для конструктора с параметрами -1
{
	//cout << "Constructor\n";
	nameFraction = new char[strlen(name) + 1];
	strcpy_s(nameFraction, strlen(name) + 1, name);
	numerator = num;
	if (den != 0) {
		denominator = den;
	}
	else { denominator = 1; }
	count++;
}

RationalFractions::RationalFractions(int num, int den)// метод для конструктора с параметрами-2
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

RationalFractions::RationalFractions(const RationalFractions &fraction)//метод для конструктора копирования
{
	//cout << "Constructor-copy" << endl;
	nameFraction = new char[strlen(fraction.nameFraction) + 1];
	strcpy_s(nameFraction, strlen(fraction.nameFraction) + 1, fraction.nameFraction);
	numerator = fraction.numerator;
	denominator = fraction.denominator;
	count++;
}

RationalFractions::~RationalFractions()//метод для деструктора
{
	//cout << "Destructor!\n";
	count--;
	delete[] nameFraction;
}

int RationalFractions::GetCount() //Счетчик Count 
{
	return count;
}

void RationalFractions::getFraction()//вывод данных
{
	cout << numerator << "/" << denominator;
}

void RationalFractions::getResult()//вывод результатов вычислений в виде правильной простой дроби
{
	int whole;
	if (numerator >= denominator)
	{
		whole = numerator / denominator;
		numerator = numerator % denominator;
		cout << whole << " " << numerator << "/" << denominator;
	}
	else
	{
		cout << numerator << "/" << denominator;
	}
}

void RationalFractions::reduction()//сокращение дроби
{
	int nod = NOD(numerator, denominator);
	numerator = numerator / nod;
	denominator = denominator / nod;
}

int RationalFractions::NOD(int den1, int den2)//наибольший общий делитель
{
	while (den1 != den2)
	{
		if (den1 > den2) { den1 -= den2; }
		else { den2 -= den1; }
	}
	return den1;
}

int RationalFractions::NOK(int den1, int den2)//наименьшее общее кратное
{
	if ((den1 > den2) && (den1 % den2 == 0))
	{
		return den1;
	}
	else if ((den1 < den2) && (den2 % den1 == 0))
	{
		return den2;
	}
	else
		return den1*den2 / NOD(den1, den2);
}

//перегрузка операторов

RationalFractions RationalFractions::operator+(RationalFractions & F)// перегрузка оператора сложения
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

RationalFractions RationalFractions::operator-(RationalFractions & F)//перегрузка оператора вычитания
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

RationalFractions RationalFractions::operator*(RationalFractions &F)//перегрузка оператора умножения
{
	RationalFractions tmp;
	tmp.numerator = numerator * F.numerator;
	tmp.denominator = denominator * F.denominator;
	tmp.reduction();
	return tmp;
}

RationalFractions RationalFractions::operator/(RationalFractions &F)//перегрузка оператора деления
{
	RationalFractions tmp;
	tmp.numerator = numerator * F.denominator;
	tmp.denominator = denominator * F.numerator;
	tmp.reduction();
	return tmp;
}

RationalFractions RationalFractions::operator++(int) //перегрузка постфиксного инкремента
{
	RationalFractions tmp(*this);
	numerator++;
	denominator++;
	return tmp;
}

RationalFractions RationalFractions::operator--() //перегрузка префиксного декремента
{
	numerator--;
	denominator--;
	return *this;
}

bool RationalFractions::operator==(RationalFractions &F)//перегрузка оператора сравнения
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

RationalFractions::operator double() // перегрузка оператора приведения к типу doudle
{
	return (double)numerator / (double)denominator;
}

RationalFractions &RationalFractions::operator = (RationalFractions &F)//перегрузка оператора присваивания
{
	if ((*this) == F)
		return *this;
	delete[] nameFraction; //строки 206-208 можно не использовать. При использовании меняется имя результирующей дроби, т.к.отрабатывает конструктор копирования
	nameFraction = new char[strlen(F.nameFraction) + 1];
	strcpy_s(nameFraction, strlen(F.nameFraction) + 1, F.nameFraction);
	numerator = F.numerator;
	denominator = F.denominator;
	return *this;
}

ostream& operator <<(ostream& out, RationalFractions& F)// перегрузка оператора вывода данных из потока
{
	out << F.numerator << "/" << F.denominator << " ";
	return out;
}

istream& operator >> (istream& in, RationalFractions& F)// перегрузка оператора помещения данных в поток
{
	in >> F.numerator;
	in >> F.denominator;
	return in;
}

void RationalFractions::setNameFraction(char* name)
{
	delete[] nameFraction;
	nameFraction = new char[strlen(name) + 1];
	strcpy_s(nameFraction, strlen(name) + 1, name);
}

void RationalFractions::setNumerator(int num)//изменить числитель
{
	numerator = num;
}

void RationalFractions::setDenominator(int den)//изменить знаменатель
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
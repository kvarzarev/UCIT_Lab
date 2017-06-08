#include <iostream>
using namespace std;

class RationalFractions
{
	int numerator; //числитель
	int denominator; //знаменатель
	char *nameFraction; //имя дроби (как пример, исключительно для динамического выделения памяти)
	static int count;
	static int NOD(int, int); // наибольший общий делитель
	static int NOK(int, int); // наименьшее общее кратное
	void reduction(); //сокращение дроби
public:
	RationalFractions(); //конструктор по умолчанию
	RationalFractions(char*, int, int); //конструктор с параметрами-1
	RationalFractions(int, int); //конструктор с параметрам-2
	RationalFractions(const RationalFractions&F);//конструктор копирования
	~RationalFractions(); //деструктор
	static int GetCount(); // счетчик количества созданных объектов
						   //Перегрузка операторов
	RationalFractions operator+(RationalFractions &); // перегрузка оператора сложения
	RationalFractions operator-(RationalFractions &);// перегрузка оператора вычитания
	RationalFractions operator*(RationalFractions &);// перегрузка оператора умножения
	RationalFractions operator/(RationalFractions &);// перегрузка оператора деления
	bool operator==(RationalFractions &);//перегрузка оператора сравнения
	RationalFractions &operator = (RationalFractions &F); //перегрузка оператора присваивания
	friend ostream& operator <<(ostream&out, RationalFractions&); //перегрузка оператора cout
	friend istream& operator >> (istream&in, RationalFractions&);//перегрузка оператора cin

	virtual void getFraction(); //функция вывода дроби (без имени)
	void getResult(); //вывод результатов вычислений в виде правильной простой дроби
	void setNameFraction(char*);
	void setNumerator(int);
	void setDenominator(int);
	char *getNameFraction();
	int getNumerator();
	int getDenominator();
};

class Rezult :public RationalFractions // класс-наследник "Результат"
{
	double rezult; // результат в виде десятичной дроби
public:
	Rezult();
	Rezult(double);
	Rezult &operator=(RationalFractions &);
	friend ostream& operator <<(ostream&out, Rezult&); //перегрузка оператора cout
	friend istream& operator >> (istream&in, Rezult&);//перегрузка оператора cin
	virtual void getFraction();
};



class MixedFraction :public RationalFractions // класс-наследник "Смешанная дробь"
{
	int integer; // целое число
public:
	MixedFraction();
	MixedFraction(int);
	MixedFraction(int, int, int);
	virtual void getFraction();
	MixedFraction &operator = (RationalFractions &R);
	friend ostream& operator <<(ostream&out, MixedFraction&); //перегрузка оператора cout
	friend istream& operator >> (istream&in, MixedFraction&);//перегрузка оператора cin
};
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
	RationalFractions operator++(int); //перегрузка постфиксного инкремента
	RationalFractions operator--(); //перегрузка префиксного декремента
	bool operator==(RationalFractions &);//перегрузка оператора сравнения
	operator double(); //перегрузка оператора приведения к типу
	RationalFractions &operator = (RationalFractions &F); //перегрузка оператора присваивания
	friend ostream& operator <<(ostream&out, RationalFractions&F); //перегрузка оператора cout
	friend istream& operator >> (istream&in, RationalFractions&F);//перегрузка оператора cin

	void getFraction(); //функция вывода дроби (без имени)
	void getResult(); //вывод результатов вычислений в виде правильной простой дроби
	void setNameFraction(char*);
	void setNumerator(int);
	void setDenominator(int);
	char *getNameFraction();
	int getNumerator();
	int getDenominator();
};

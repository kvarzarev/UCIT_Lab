#include <iostream>
using namespace std;

class RationalFractions
{
	int numerator; //числитель
	int denominator; //знаменатель
	char *nameFraction; //имя дроби (как пример, исключительно для динамического выделения памяти)
	int size; //размер имени
	static int count;
	static int NOD(int, int); // наибольший общий делитель
	static int NOK(int, int); // наименьшее общее кратное
	void reduction(); //сокращение дроби
public:
	RationalFractions(); //конструктор по умолчанию
	RationalFractions(char*, int, int, int); //конструктор с параметрами
	RationalFractions(int num, int den);
	RationalFractions(const RationalFractions& F);//конструктор копирования
	~RationalFractions(); //деструктор
	static int GetCount(); // счетчик количества созданных объектов
	RationalFractions addition(RationalFractions &); // сложение дробей
	RationalFractions subtraction(RationalFractions &);// вычитание дробей
	RationalFractions multiplication(RationalFractions &);// умножение дробей
	RationalFractions separation(RationalFractions &);// деление дробей
	bool compare(RationalFractions &);//сравнение дробей
	void getFraction(); //метод вывода дроби (без имени)
	void getResult(); //вывод результатов вычислений в виде правильной простой дроби
	double decimal(); //преобразование простой дроби в десятичную
	void setNameFraction(char *);
	void setNumerator(int); 
	void setDenominator(int);
	char *getNameFraction();
	int getNumerator();
	int getDenominator();
};
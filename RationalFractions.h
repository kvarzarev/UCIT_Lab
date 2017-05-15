#include <iostream>
using namespace std;

class RationalFractions
{
	int numerator; //���������
	int denominator; //�����������
	char *nameFraction; //��� ����� (��� ������, ������������� ��� ������������� ��������� ������)
	int size; //������ �����
	static int count;
	static int NOD(int, int); // ���������� ����� ��������
	static int NOK(int, int); // ���������� ����� �������
	void reduction(); //���������� �����
public:
	RationalFractions(); //����������� �� ���������
	RationalFractions(char*, int, int, int); //����������� � �����������
	RationalFractions(int num, int den);
	RationalFractions(const RationalFractions& F);//����������� �����������
	~RationalFractions(); //����������
	static int GetCount(); // ������� ���������� ��������� ��������
	RationalFractions addition(RationalFractions &); // �������� ������
	RationalFractions subtraction(RationalFractions &);// ��������� ������
	RationalFractions multiplication(RationalFractions &);// ��������� ������
	RationalFractions separation(RationalFractions &);// ������� ������
	bool compare(RationalFractions &);//��������� ������
	void getFraction(); //����� ������ ����� (��� �����)
	void getResult(); //����� ����������� ���������� � ���� ���������� ������� �����
	double decimal(); //�������������� ������� ����� � ����������
	void setNameFraction(char *);
	void setNumerator(int); 
	void setDenominator(int);
	char *getNameFraction();
	int getNumerator();
	int getDenominator();
};
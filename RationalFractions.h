#include <iostream>
using namespace std;

class RationalFractions
{
	int numerator; //числитель
	int denominator; //знаменатель
	char *nameFraction; //èìÿ äðîáè (êàê ïðèìåð, èñêëþ÷èòåëüíî äëÿ äèíàìè÷åñêîãî âûäåëåíèÿ ïàìÿòè)
	int size; //ðàçìåð èìåíè
	static int count;
	static int NOD(int, int); // íàèáîëüøèé îáùèé äåëèòåëü
	static int NOK(int, int); // íàèìåíüøåå îáùåå êðàòíîå
	void reduction(); //ñîêðàùåíèå äðîáè
public:
	RationalFractions(); //êîíñòðóêòîð ïî óìîë÷àíèþ
	RationalFractions(char*, int, int, int); //êîíñòðóêòîð ñ ïàðàìåòðàìè
	RationalFractions(int num, int den);
	RationalFractions(const RationalFractions& F);//êîíñòðóêòîð êîïèðîâàíèÿ
	~RationalFractions(); //äåñòðóêòîð
	static int GetCount(); // ñ÷åò÷èê êîëè÷åñòâà ñîçäàííûõ îáúåêòîâ
	RationalFractions addition(RationalFractions &); // ñëîæåíèå äðîáåé
	RationalFractions subtraction(RationalFractions &);// âû÷èòàíèå äðîáåé
	RationalFractions multiplication(RationalFractions &);// óìíîæåíèå äðîáåé
	RationalFractions separation(RationalFractions &);// äåëåíèå äðîáåé
	bool compare(RationalFractions &);//ñðàâíåíèå äðîáåé
	void getFraction(); //ìåòîä âûâîäà äðîáè (áåç èìåíè)
	void getResult(); //âûâîä ðåçóëüòàòîâ âû÷èñëåíèé â âèäå ïðàâèëüíîé ïðîñòîé äðîáè
	double decimal(); //ïðåîáðàçîâàíèå ïðîñòîé äðîáè â äåñÿòè÷íóþ
	void setNameFraction(char *);
	void setNumerator(int); 
	void setDenominator(int);
	char *getNameFraction();
	int getNumerator();
	int getDenominator();
};

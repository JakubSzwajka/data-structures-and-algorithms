#include <string>

using namespace std; 

class Duza_liczba
{
public : 
	Duza_liczba();
	Duza_liczba(string liczba);
	Duza_liczba(int intLiczba);
	~Duza_liczba()
	{
		delete [] tablica;
	}
	void print();

	static int length;

	bool operator == (const Duza_liczba &a);
	bool operator != (const Duza_liczba &a);
	Duza_liczba & operator = (const Duza_liczba &a);
	Duza_liczba operator + (const Duza_liczba &a);
	Duza_liczba operator * (const Duza_liczba &a);
	friend Duza_liczba odejmowaniePisemne(Duza_liczba x, Duza_liczba y);

private: 
	int *tablica; 
};

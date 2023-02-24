#include <iostream>
#include <string>
#include "duza_liczba.hpp"


using namespace std;


int main()
{
	
	Duza_liczba silnia(1);
	Duza_liczba B(1);
	Duza_liczba C(1);

	int n;
	cin>>n;

	for(int i = 1; i <= n; i++)
	{
		C = C * silnia;
		silnia = silnia + B;
	}

	C.print();
	return 0;
}

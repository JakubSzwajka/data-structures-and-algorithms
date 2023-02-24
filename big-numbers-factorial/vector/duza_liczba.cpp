#include "duza_liczba.hpp"
#include <string>
#include <iostream>

using namespace std;

int Duza_liczba::length = 200;

#pragma region konstruktory
// konstruktor bezargumentowy 
Duza_liczba::Duza_liczba()
{
	tablica.assign(length, 0);
}
// konstruktor z argumentem typu string
Duza_liczba::Duza_liczba(string liczba)
{
	//tablica = new int[length];	
	//for (int i = 0; i < length; i++)	tablica[i] = 0;

	tablica.assign(length, 0);
	int stringLength = liczba.size();

	for (int i = 0; i <= stringLength; i++)
		Duza_liczba::tablica[length - i] = liczba[stringLength - i] - 48;
}
Duza_liczba::Duza_liczba(int intLiczba)
{
	//tablica = new int[length];
	//for (int i = 0; i < length; i++)	tablica[i] = 0;

	tablica.assign(length, 0);
	int mod = 10;
	for(int i = length - 1 ; i >= 0;i --)
	{
		tablica[i] = intLiczba % mod;
		intLiczba = intLiczba / 10;
		if(intLiczba==0) break;
	}
}
#pragma endregion

#pragma region metody
// funkcja drukująca na ekran duza liczbe
void Duza_liczba::print()
{
	bool firstZero = false;
	for (int i = 0; i < length; i++)
	{
		if(tablica[i] != 0)
			firstZero = true;
		if(firstZero == true)
			cout << tablica[i];
	}
	cout << endl;
}
#pragma endregion

// operator mnożenia
Duza_liczba Duza_liczba::operator * (const Duza_liczba &a)
{
	Duza_liczba temp("");

	int step = 0;
	int tempPos = 0;
	for(int i = length - 1;i >= 0; i-- )
	{
		for(int j = length - 1; j >= 0 ; j --)
		{
			tempPos = j - step;
			if(tempPos < 0) tempPos = 0;
			temp.tablica[tempPos] =(temp.tablica[tempPos] + (a.tablica[i] * tablica[j]));

			if(temp.tablica[tempPos]>= 10)
			{
				temp.tablica[tempPos - 1] = temp.tablica[tempPos - 1] + (temp.tablica[tempPos] / 10);
				temp.tablica[tempPos] = temp.tablica[tempPos]%10; 
			}
		}
		step++;
	}
	return temp;
}
#pragma region operatory przypisania i porównywania
// operator przypisania
Duza_liczba & Duza_liczba::operator = (const Duza_liczba & a)
{
	if(this == &a){return *this;}
	else{
	for (int i = 0; i < length; i++)
	{
		tablica[i] = a.tablica[i];
	}
	return *this;
	}
}
// operator porównania
bool Duza_liczba::operator == (const Duza_liczba &a)
{	
	for (int i = 0; i < length; i++)
	{
		if (tablica[i] != a.tablica[i])
		{
			return false;
		}
	}
	return true;
}
// operator nierówności
bool Duza_liczba::operator != (const Duza_liczba &a)
{
	for (int i = 0; i < length; i++)
	{
		if (tablica[i] != a.tablica[i])
		{
			return true;
		}
	}
	return false;
}
#pragma endregion

#pragma region operatory dodawania i odejmowania
// operator dodawania
Duza_liczba Duza_liczba::operator + (const Duza_liczba &a)
{
	Duza_liczba temp(0);

	for(int i = length -1 ; i >0; i--)
	{
		temp.tablica[i] += (a.tablica[i] + tablica[i]) % 10;
		temp.tablica[i - 1] += (a.tablica[i] + tablica[i])/10;
	}
	return temp;
}
#pragma endregion
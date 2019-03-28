#include "duza_liczba.hpp"
#include <string>
#include <iostream>

using namespace std;

//int Duza_liczba::length = 100;

#pragma region konstruktory
// konstruktor bezargumentowy tworzy tablice dlugosci 1
Duza_liczba::Duza_liczba()
{
	length = 1;
	tablica = new int[1];
	for (int i = 0; i < length; i++)	tablica[i] = 0;
}
// konstruktor z argumentem typu string
Duza_liczba::Duza_liczba(string liczba)
{
	int stringLength = liczba.length();
	length = stringLength;
	tablica = new int[length];	

	for (int i = 0; i <= length; i++)
		tablica[length - i] = liczba[length - i] - 48;
}
Duza_liczba::Duza_liczba(int intLiczba)
{
	int licz = intLiczba;
	int mod = 10;
	length = 0;
	while (licz != 0)
	{
		licz /= mod;
		length ++ ;
	}
	// zabezpieczenie przed wpisaniem 0
	if(intLiczba == 0) length = 1;

	tablica = new int[length];
	for (int i = 0; i < length; i++)
		tablica[i] = 0;

	
	for (int i = length - 1; i >= 0; i--)
	{
		tablica[i] = intLiczba % mod;
		intLiczba = intLiczba / 10;
		if (intLiczba == 0)
			break;
	}
}
#pragma endregion

#pragma region metody
// funkcja drukująca na ekran duza liczbe
void Duza_liczba::print()
{
	for(int i = 0; i < length; i ++) cout << tablica[i];
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
// operator przypisania
Duza_liczba & Duza_liczba::operator = (const Duza_liczba & a)
{
	if(this == &a){return *this;}
	else{
		Duza_liczba reWrited(0);
		Duza_liczba original(0);
		if (a.length != length)
		{
			if (a.length > length)
			{
				original.length = length;
				original.tablica = new int[original.length];
				for (int i = 0; i < length; i++)
					original.tablica[i] = a.tablica[i];

				reWrited.length = a.length;
				reWrited = reWriteToBigger(*this, reWrited.length);

				for (int i = 0; i < reWrited.length; i++)
					reWrited.tablica[i]= original.tablica[i];

					return reWrited;
			}
			else
			{
				original.length = a.length;
				original.tablica = new int[original.length];
				for (int i = 0; i < length; i++)
					original.tablica[i] = tablica[i];

				reWrited.length = length;
				reWrited = reWriteToBigger(a, reWrited.length);

				for (int i = 0; i < reWrited.length; i++)
					reWrited.tablica[i] = original.tablica[i];

				return reWrited;
			}

			//for(int i = 0 ; i < reWrited.length; i++) 
		}

		for(int i = 0; i < length; i ++)
		{
			tablica[i] = a.tablica[i];
		}

		return *this;
	}
}
#pragma region operatory dodawania i odejmowania
// operator dodawania
Duza_liczba Duza_liczba::operator + (const Duza_liczba &a)
{
// PRZEPISANIE TABLICY KRÓTSZEJ DO TABLICY O RÓWNEJ DŁUGOŚCI
// ZA POMOCĄ METODY REWRITETOBIGGER

	Duza_liczba reWrited(0);
	if(a.length != length)
	{
		if(a.length > length)
		{
			reWrited.length = a.length;
			reWrited = reWriteToBigger(*this, reWrited.length);
		}
		else 
		{
			reWrited.length = length;
			reWrited = reWriteToBigger(a, reWrited.length);
		}

	}


// DODAWANIE PO PRZEPISANIU DO TABLIC O RÓWNEJ DŁUGOSCI 

	Duza_liczba temp("");
	//delete [] tablica;
	//tablica = new int [length];

	for(int i = length -1 ; i >0; i--)
	{
		temp.tablica[i] += (a.tablica[i] + tablica[i]) % 10;
		temp.tablica[i - 1] += (a.tablica[i] + tablica[i])/10;
	}
	return temp;
}
#pragma endregion

// METODA PRZYJMUJE ELEMENT TYPU DUZA LICZBA I PRZEPISUJE GO DO DŁUŻSZEJ
// TABLICY O ZADANEJ DŁUGOSCI WYPEŁNIONĄ ZERAMI Z PRZODU

Duza_liczba Duza_liczba::reWriteToBigger(Duza_liczba a, int dlugosc)
{
	

	if(a.length > dlugosc) cout << "Error! Błąd systemu złe długości tablic!" << endl;

	Duza_liczba temp(0);
	temp.length = dlugosc;
	temp.tablica = new int [dlugosc];

	for(int i = 0 ; i < dlugosc; i++)
	{
		temp.tablica[i] = 0;
	}
	for(int i = a.length - 1; i >= 0; i--)
	{
		temp.tablica[i] = a.tablica[i];
	}

	return temp;
}
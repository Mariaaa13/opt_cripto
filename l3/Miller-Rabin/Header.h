#pragma once
#include <fstream> 
#include<iostream> 
#include<time.h> 
using namespace std;
int a_la_b_mod_c(int a, int b, int c) {
	int p = 1;
	while (b)
	{

		if (b % 2)//verifica ca b sa fie nenul
		{
			p = (p * a) % c;
		}



		a = (a * a) % c;
		b /= 2;

	}
	return p;
}

int cmmdc(int a, int b)
{
	int r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

bool test_Fermat(int n, int nr_incercari) {
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (; nr_incercari > 0; nr_incercari--) {
		int b = rand();
		b = 2 + b % (n - 2);
		if (cmmdc(b, n) != 1) return 0;
		if (a_la_b_mod_c(b, n - 1, n) != 1) return 0;
	}
	return 1;
}

bool test_Miller_Rabin(int n, int nr_incercari)
{
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (; nr_incercari > 0; nr_incercari--)
	{
		int s = 0, t = n - 1, b = rand();
		b = 2 + b % (n - 2);
		while (t % 2 == 0)
		{
			s++;
			t /= 2;
		}
		t = a_la_b_mod_c(b, t, n);//in t pastram acum puterile b^t,b^(2t),...
		if (t != 1)
		{
			while ((t != n - 1) && (--s > 0))
			{//testam pentru nr de forma b^((2^r)*t) cu r din multimea {1,2,...,s-1}
				t = (t * t) % n;
				if (t == 1) return 0;
			}
			if (t != n - 1) return 0;
		}
	}
	return 1;
}
bool prim(int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i <= sqrt((double)n); i += 2)
		if (n % i == 0) return 0;
	return 1;
}
int** calculFactorizare(unsigned int n, int& nr)
{
	int** descompunere = new int* [2];
	descompunere[0] = new int[n];
	descompunere[1] = new int[n];
	for (unsigned long long i = 0; i < n; i++)
		descompunere[0][i] = descompunere[1][i] = 0;
	if (n % 2 == 0)
	{
		descompunere[0][0] = 2;
		nr++;
		while (n % 2 == 0)
		{
			descompunere[1][0]++;
			n /= 2;
		}
	}
	for (unsigned long long i = 3; i <= n; i += 2)
	{
		if (n % i == 0)
		{
			descompunere[0][nr] = i;
			while (n % i == 0)
			{
				descompunere[1][nr]++;
				n /= i;
			}
			nr++;
		}
	}
	return descompunere;
}

char* citeste_din_fisier(ifstream& in)
{
	char* mesaj = new char[100];
	char c;
	int i = 0;
	if (in.good())
	{
		cout << "Fisierul a fost deschis cu succes.\nContinutul acestuia este:\n\n"; 
	}
	else
		while (!in.eof()) // cat timp nu s-a ajuns la sfarsitul fisierului sursa 
		{
			in >> noskipws >> c;
			mesaj[i] = c;
			i++;
		}
	mesaj[--i] = '\0';
	cout << "Eroare la deschiderea fisierului.";
	return mesaj;
}
void scrie_in_fisier(char* mesaj)
{//vom scrie caracter cu caracter 
	ofstream out("destinatie.txt"); //deschidem fisierul pentru scriere 
	//echivalent cu: 
	//fstream out("destinatie.txt",ios::out);) 
	//pentru a adauga text intr-un fisier: 
	 //fstream out("destinatie.txt",ios::app); 
	int i = 0;
	while (mesaj[i] != '\0') // cat timp nu s-a ajuns la sfarsitul mesajului 
	{
		out << mesaj[i];
		i++;
	}
	out.close();//inchidem fisierul 
}

struct bloc
{
	char c;
	int nr;
};
bloc character[100] = { 0 };
int N = 0;
int da_cod(char c)
{
	for (int i = 0; i < N; i++)
		if (character[i].c == c)
			return i;
	return -1;
}

char da_caracter(int cod)
{
	return character[cod % N].c;
}
void citeste_alfabet(ifstream& in)
{
	if (!in.good())
		perror("Fisier inexistent");
	char c;
	while (in >> noskipws >> c)
	{
		character[N].c = c;
		N++;
	}
	if (N == 0)
		cout << "Alfabetul dat are 0 caractere" << endl;
}

void frecv(ifstream& fin)
{
	if (!fin.good())
		perror("Fisier inexistent");
	char c;
	while (fin >> noskipws >> c)
	{
		int cod = da_cod(c);
		if (cod >= 0 && cod < N)
			character[cod].nr++;
	}
	int ordonat = 0;
	while (!ordonat)
	{
		ordonat = 1;
		for (int i = 0; i < N - 1; i++)
		{
			if (character[i].nr < character[i + 1].nr)
			{
				ordonat = 0;
				bloc temp = character[i];
				character[i] = character[i + 1];
				character[i + 1] = temp;
			}
		}
	}
}
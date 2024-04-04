#include "Header.h"
int main() {

	ifstream in("alfabet.txt");
	citeste_alfabet(in);
	in.close();
	ofstream out("destinatie.txt");
	ifstream in2("sursa.txt");//fisierul cu textul sursa 
	/*criptareCezar(in2, out, 21);//pe ultima pozi?ie trebuie cheia de criptare 
	spargereCezar(in2, out);//pe ultima pozi?ie trebuie cheia de criptare 
	criptareAfina(in2, out, 3, 2);//pe ultimele pozi?ii trebuie cheia de criptare
	spargereafina(in2, out);*/
	/*int** a = new int* [2];
	int* b = new int[2];
	for (int i = 0; i < 2; i++)
		a[i] = new int[2];
	a[0][0] = 2;
	a[0][1] = 3;
	a[1][0] = 7;
	a[1][1] = 8;
	b[0] = 0;
	b[1] = 0;
	cheieAfina k;
	k.n = 2;
	k.a = a;
	k.b = b;
	criptareAfina(in2, out, k);
	in2.close(); out.close();*/
	int** a = new int* [2];
	int* b = new int[2];
	for (int i = 0; i < 2; i++)
		a[i] = new int[2];
	a[0][0] = 27;
	a[0][1] = 7;
	a[1][0] = 1;
	a[1][1] = 20;
	b[0] = 0;
	b[1] = 0;
	cheieAfina k;
	k.n = 2;
	k.a = calcul_matr_inv_Zn(a, k.n, N);
	k.b = b;
	criptareAfina(in2, out, k);
	in2.close(); out.close();


}


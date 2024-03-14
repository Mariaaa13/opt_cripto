#include<iostream>
#include <stdlib.h> 
#include<time.h>
using namespace std;
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
int a_la_b_mod_c(int a, int b, int c)
{
	int p = 1;
	a =a%c;
	while (b > 0)
	{
		if (b % 2)
			p = ((p * a)% c);
		a = ((a * a)% c);
		b /= 2;
	}
	return p;
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
int main() {
	int n, nr_incercari;
	srand(time(NULL));
	cout << "Programul va stabili daca numarul ""n""  poate fi prim aplicand testul Fermat de un numar dat de ori" << endl; 
		cout << "\nDati un numar natural nenul-->";
	cin >> n;
	cout << "\nDati numarul maxim de incercari-->";
	cin >> nr_incercari;
	if (test_Fermat(n, nr_incercari))
		cout << "\nNumarul " << n << " poate fi prim" << endl;
	else
		cout << "\nNumarul " << n << " nu este prim" << endl;
	return 0;
}
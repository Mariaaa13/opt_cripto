#include<iostream>

using namespace std;
int calculExponentiereModulara(int a, int b, int c) { //a^b mod c
	int p = 1;
	while (b) {
		if (b % 2) 
			p = (p * a) % c;
		
		a = (a * a) % c;
		b /= 2;
	}
	return p;
}

int main() {
	cout << calculExponentiereModulara(2, 40, 105);
}
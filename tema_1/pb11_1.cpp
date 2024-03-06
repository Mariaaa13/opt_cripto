#include<iostream>

using namespace std;


int Euclid_b(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;

	}
	return(a);

}

int coef(int a, int b) {
	int a_vechi, p = 0, d[2], v[2], nou[2], r=0, i;
	a_vechi = a;
	d[0] = 1;
	d[1] = 0;
	v[0] = 0;
	v[1] = 1;
	while (a > 1) {
		if (b != 0)
			while (a / b >= 1){
				a = a / b;
				p++; //aflam puterea divizorului (in primul caz fiind b)

			}
			if (p >= 1) {
				r = a_vechi - (p * b);  //aflam restul obtinut dupa ce il impartim pe a prin b la puterea cea mai mare
				nou[0] = d[0] * p - r * v[0];
				nou[1] = d[1] * p - r * v[1];
				d[0] = v[0];
				d[1] = v[1];
				v[0] = nou[0];
				v[1] = nou[1];

			}
			a_vechi = a;
			a = b;
			b = r;
			p = 0;
		}
	for (i = 0; i < 2; i++) {
		return(nou[i]);
	}
	
}
int main() {
	int a, b;
	cout << coef(22333, 44341) << endl<<"taaaare"<<endl << Euclid_b(22333, 44341) << endl;

}
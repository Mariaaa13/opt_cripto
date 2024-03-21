#include"Header.h"
int main() {
	cout << prim(91) << endl;
	int nr = 0;
	int** factorizare = calculFactorizare(15347, nr);
	for (int i = 0; i < nr; i++)
		cout << factorizare[0][i] << " la puterea " << factorizare[1][i] << endl;
	ifstream("sursa.txt");
	char* c = citeste_din_fisier(in);
	const char d[20] = "bob are mere";
	ofstream out("destinatie.txt");
	cout << c << endl;

	return 0;
}

/*#include<bitset>
int r;
cout << "r = " << bitset<16>(r) << endl;*/
#include<iostream> 
#include<bitset> 
using namespace std;
int main()
{
	int m, s[100], w, i, n, r1;
	cout << "dati secretul";
	cin >> m;
	cin >> w; /*w e nr de pers n*/
	/*r = rand() | rand();
	cout << "r = " << bitset<16>(r) << endl;
	s = m ^ r;
	cout << "s = " << bitset<16>(s) << endl;
	n = s ^ r;*/
	s[0] = rand() | rand();
	for (i = 1; i <= w; i++) {
		r1 = rand() | rand();
		cout << "s[i-1] = " << bitset<16>(s[i-1]) << endl;
		r1 = m ^ s[i-1];
		cout << "s[1] = " << bitset<16>(r1) << endl;
	}
	for (i = 1; i <= w; i++) {
		n = s[0] ^ s[i];
		cout << n;
	}
	return 0;
}
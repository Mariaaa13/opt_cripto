#include"Header.h"
int main()
{
	ifstream in("alfabet.txt");
	citeste_alfabet(in);
	in.close();
	ifstream in2("date.txt");
	frecv(in2);
	in2.close();
	for (int i = 0; i < N; i++)
		if (character[i].nr > 0)
			cout << character[i].c << " " << character[i].nr << endl;
	return 0;
}
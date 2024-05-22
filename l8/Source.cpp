#include "Header.h"

int main() {
	ifstream in("alfabet.txt");
	RSA_key cheieA, cheieB;
	ifstream in2("sursa.txt");
	ofstream destinatie("destinatie.txt");
	cheieA.n = 2047;
	cheieA.d = 3;
	cheieA.j = 2;
	cheieA.l = 3;
	cheieB.n = 2813;
	cheieB.e = 5;
	cheieB.j = 2;
	cheieB.l = 3;

}
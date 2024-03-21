#include<iostream> 
#include<time.h> 
using namespace std;
int a_la_b_mod_c(int a, int b, int c) {
    int p = 1;
    a = a % c;
    while (b > 0)
    {
        if (b % 2)
            p = ((p * a) % c);
        a = ((a * a) % c);
        b /= 2;
    }
    return p;
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
            {//testam pentru nr de forma b^((2^r)*t) cu r din multimea { 1, 2, ..., s - 1 }
                t = (t * t) % n;
                if (t == 1) return 0;
            }
            if (t != n - 1) return 0;
        }
    }
    return 1;
}
/*void main() {
    int n;
    int nr_incercari;
    srand(time(NULL));
    cout << "Programul va stabili daca numarul ""n""  poate fi prim aplicand testul Miller - Rabin de un numar dat de ori" << endl;
    cout << "\nDati un numar natural nenul-->";
    cin >> n;
    cout << "\nDati numarul maxim de incercari-->";
    cin >> nr_incercari;
    if (test_Miller_Rabin(n, nr_incercari))
        cout << "\nNumarul " << n << " poate fi prim" << endl;
    else
        cout << "\nNumarul " << n << " nu este prim" << endl;
}*/
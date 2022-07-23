#include <iostream>

using namespace std;
unsigned int NCD(unsigned int a, unsigned int b) {

    if (a == b)
        return a;
    if (a > b)
        return NCD(a - b, b);
    return NCD(a, b - a);
}

class Fraction
{
private:
    int integer = 0;
    double numer;
    double denom;
public:
    Fraction(int n = 0, int d = 1) {
        this->numer = n;
        this->denom = d;
        this->integer = 0;
    }
    void comparison(Fraction a, Fraction b) {
        a.reduce();
        b.reduce();
        if (a.numer / a.denom == b.numer / b.denom && a.integer == b.integer)   print(1, a, b);
        if (a.integer > b.integer || a.numer / a.denom > b.numer / b.denom)     print(2, a, b);
        if (a.integer < b.integer || a.numer / a.denom < b.numer / b.denom)     print(3, a, b);
    }
    void print(int n, Fraction a, Fraction b)
    {
        switch (n)
        {
        case 1:
            cout << "Integer: " << a.integer << " " << a.numer << "/" << a.denom << " = " << "integer: " << b.integer << " " << b.numer << "/" << b.denom << endl;
            break;
        case 2:
            cout << "Integer: " << a.integer << " " << a.numer << "/" << a.denom << " > " << "integer: " << b.integer << " " << b.numer << "/" << b.denom << endl;
            break;
        case 3:
            cout << "Integer: " << a.integer << " " << a.numer << "/" << a.denom << " < " << "integer: " << b.integer << " " << b.numer << "/" << b.denom << endl;
            break;
        }
    }
    void reduce() {
        if (this->numer > this->denom) {
            while (this->numer >= this->denom) {
                this->numer -= this->denom;
                this->integer++;
            }
        }
        else
        {
            int buff = NCD(this->numer, this->denom);
            this->numer /= buff;
            this->denom /= buff;
        }
    }
};
int main()
{
    setlocale(LC_ALL, "Ukrainian");
    double n1 = 0, d1 = 0, n2 = 0, d2 = 0;
    cout << "Input first numer --> ";
    cin >> n1;
    cout << endl << "Input first denom --> ";
    cin >> d1;
    cout << endl << "Input second numer --> ";
    cin >> n2;
    cout << endl << "Input second denom --> ";
    cin >> d2;
    cout << endl;
    Fraction object1(n1, d1), object2(n2, d2);
    object1.comparison(object1, object2);
}
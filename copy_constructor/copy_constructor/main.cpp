#include <iostream>
using namespace std;
int gcd(int a, int b){
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
class Rational{
private:
    int *numeral, *denominator;
    void reducing(){
        int d = gcd(*numeral, *denominator);
        *denominator /= d;
        *numeral /= d;
    }
public:
    Rational(int a, int b){
        numeral = new int(a);
        denominator = new int(b);
    }
    Rational(){
        numeral = 0;
        denominator = 0;
    }
    Rational(int a){
        numeral = new int(a);
        denominator = new int(1);
    }
    int getN(){
        return *numeral;
    }
    int getD(){
        return *denominator;
    }
    Rational(const Rational&t){
        this->numeral = new int;
        *(this->numeral) = *(t.numeral);
        this->denominator = new int;
        *(this->denominator) = *(t.denominator);
    }
    void show(){
        cout << *numeral <<'/' << *denominator;
    }
    ~Rational(){
        delete numeral;
        delete denominator;
    }
};
Rational sum(Rational a, Rational b){
    int totalD = a.getD() * b.getD();
    int totalN = a.getN() * b.getD() + b.getN() * a.getD();
    int devizor = gcd(totalD, totalN);
    totalD /= devizor;
    totalN /= devizor;
    Rational res(totalN, totalD);
    return res;
}
Rational div(Rational a, Rational b){
    int totalN = a.getN() * b.getD();
    int totalD = a.getD() * b.getN();
    int devizor = gcd(totalD, totalN);
    totalD /= devizor;
    totalN /= devizor;
    Rational res(totalN, totalD);
    return res;
}
Rational multi(Rational a, Rational b){
    int totalN = a.getN() * b.getN();
    int totalD = a.getD() * b.getD();
    int devizor = gcd(totalD, totalN);
    totalD /= devizor;
    totalN /= devizor;
    Rational res(totalN, totalD);
    return res;
}
Rational sub(Rational a, Rational b){
    int totalD = a.getD() * b.getD();
    int totalN = a.getN() * b.getD() - b.getN() * a.getD();
    int devizor = gcd(totalD, totalN);
    totalD /= devizor;
    totalN /= devizor;
    Rational res(totalN, totalD);
    return res;
}
int main() {
    int p, q;
    cin >> p >> q;
    Rational first(p, q);
    cin >> p >> q;
    Rational second(p, q);
    Rational s = sum(first, second);
    cout << "Sum = ";
    s.show();
    cout << '\n';
    Rational su = sub(first, second);
    cout << "Sub = ";
    su.show();
    cout << '\n';
    Rational m = multi(first, second);
    cout << "Multi = ";
    m.show();
    cout << '\n';
    Rational d =  div(first, second);
    cout << "Div = ";
    d.show();
    return 0;
}

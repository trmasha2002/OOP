#include <iostream>
using namespace std;
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
class Rational{
private:
    int *numeral, *denominator;
    void reducing(){
        int d = gcd(abs(*numeral), abs(*denominator));
        *denominator /= d;
        *numeral /= d;
    }
public:
    Rational(int a, int b){
        numeral = new int(a);
        denominator = new int(b);
        reducing();
    }
    Rational(int a){
        numeral = new int(a);
        denominator = new int(1);
    }
    
    Rational(const Rational&t) {
        this->numeral = new int;
        *(this->numeral) = *(t.numeral);
        this->denominator = new int;
        *(this->denominator) = *(t.denominator);
    }
    ~Rational(){
        delete numeral;
        delete denominator;
    }
    int operator[](int pos) const {
        if (pos == 0){
            return *numeral;
        }
        else {
            return *denominator;
        }
    }
    
    friend ostream &operator << (ostream &out, Rational a) {
        if (a.numeral == 0){
            out << 0;
        }
        else if (*a.denominator < 0){
            out << -*a.numeral << '/' << -*a.denominator;
        }
        else{
            out << *a.numeral;
            if (*a.denominator != 1){
                out << '/' <<  *a.denominator;
            }
        }
        return out;
    }
    
    Rational operator + (const Rational &other) {
        int totalD = *denominator * *other.denominator;
        int totalN = *numeral * *other.denominator + *other.numeral * *denominator;
        int devizor = gcd(abs(totalN), abs(totalD));
        totalD /= devizor;
        totalN /= devizor;
        Rational res(totalN, totalD);
        return res;
    }
    
    
    Rational operator - (const Rational &other) const {
        int totalD = *denominator * *other.denominator;
        int totalN = *numeral * *other.denominator - *other.numeral * *denominator;
        int devizor = gcd(abs(totalN), abs(totalD));
        totalD /= devizor;
        totalN /= devizor;
        Rational res(totalN, totalD);
        return res;
    }
    
    Rational operator * (const Rational &other) {
        int totalN = *numeral * *other.numeral;
        int totalD = *denominator * *other.denominator;
        int devizor = gcd(abs(totalN), abs(totalD));
        totalD /= devizor;
        totalN /= devizor;
        Rational res(totalN, totalD);
        return res;
    }
    friend Rational operator --(Rational& i) {
        *i.numeral -= *i.denominator;
        int devizor = gcd(abs(*i.numeral), abs(*i.denominator));
        *i.numeral /= devizor;
        *i.denominator /= devizor;
        return i;
    }
    friend Rational operator --(Rational& i, int) {
        Rational res(*i.numeral, *i.denominator);
        *i.numeral -= *i.denominator;
        int devizor = gcd(abs(*i.numeral), abs(*i.denominator));
        *i.numeral /= devizor;
        *i.denominator /= devizor;
        return res;
    }
    
    friend Rational operator ++(Rational& i) {
        *i.numeral += *i.denominator;
        int devizor = gcd(abs(*i.numeral), abs(*i.denominator));
        *i.numeral /= devizor;
        *i.denominator /= devizor;
        return i;
    }
    friend Rational operator ++(Rational& i, int) {
        Rational res(*i.numeral, *i.denominator);
        *i.numeral += *i.denominator;
        int devizor = gcd(abs(*i.numeral), abs(*i.denominator));
        *i.numeral /= devizor;
        *i.denominator /= devizor;
        return res;
    }
    
    
    friend bool operator < (const Rational &me, const Rational &other) {
        if (*me.numeral / *me.denominator < *other.numeral / *other.denominator){
            return true;
        }
        else{
            return false;
        }
    }
    friend Rational operator + (int a, const Rational &me) {
        int totalN = *me.numeral + a * *me.denominator;
        int totalD = *me.denominator;
        int devizor = gcd(abs(totalN), abs(totalD));
        Rational res(totalN, totalD);
        return res;
    }
    void operator -=(int a) {
        *numeral -= a * *denominator;
        int devizor = gcd(abs(*numeral), abs(*denominator));
        *numeral /= devizor;
        *denominator /= devizor;
    }
    void operator () (string s) {
        bool good = false;
        int n = *numeral / *denominator;
        for (int i = 0; i < n; i++) {
            cout << s;
            good = true;
        }
        if (good == false){
            cout << '-';
        }
    }
    
};

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Rational AB(a, b), CD(c, d), C(c); // a/b, c/d, c/1
    cout << AB << " " << CD << endl; // красивый вывод рационального.
    //Если знаменатель - 1, то не выводить его
    cout << AB[0] << " " << AB[1] << endl; // числитель и знаменатель соответственно
    cout << (AB + CD) << endl; // сложение двух рациональных
    cout << (++AB - CD--) << endl; // Прибавление и вычитание единицы соответственно
    cout << AB * c << endl; // домножение рационального на целое
    CD -= 5; // вычитание целого
    cout << AB * CD << endl; // перемножение рациональных
    cout << AB + C << endl; // прибавление рационального
    cout << AB + c << endl; // прибавление целого справа
    cout << a + CD << endl; // прибавление целого слева
    cout << ((AB < CD)?"Yes":"No") << endl; // сравнение рациональных
    AB("MSHP"); // Вывести строку столько раз, сколько целых частей в AB.
    //Если это число не положительно - то вывести "-"
    
    return 0;
}

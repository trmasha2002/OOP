#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Rational {
private:
    int p;
    int q;
    void reduce()
    {
        int a = abs(p), b = q;
        while (b > 0) { // Euclidean algorithm
            int r = a % b;
            a = b;
            b = r;
        }
        p /= a;
        q /= a;
    }
    
public:
    Rational (int p = 0, int q = 1) : p(p), q(q) {
        reduce();
    }
    int get_numerator(){
        return p;
    } // code here
    int get_denominator(){
        return q;
    } // code here
    friend Rational operator + (const Rational& r1, const Rational &r2){
        int totalD = r1.q * r2.q;
        int totalN = r1.p * r2.q + r2.p * r1.q;
        Rational res(totalN, totalD);
        res.reduce();
        return res;
    } // code here
    friend Rational operator - (const Rational& r1, const Rational &r2){
        int totalD = r1.q * r2.q;
        int totalN = r1.p * r2.q - r2.p * r1.q;
        Rational res(totalN, totalD);
        res.reduce();
        return res;
    } // code here
    friend Rational operator / (const Rational& r, int n){
        int totalD = r.q * n;
        int totalN = r.p;
        Rational res(totalN, totalD);
        res.reduce();
        return res;
    }
    
    friend std::ostream &operator << (std::ostream &out, const Rational& r) {
        out << r.p;
        if (r.q != 1)
            out  << "/" << r.q;
        return out;
    }
    
    friend std::istream& operator >> (std::istream& in, Rational& r) {
        int p, q;
        in >> p >> q;
        r.p = p;
        r.q = q;
        r.reduce();
        return in;
    }
};
class StackException{
public:
    virtual void ShowError() = 0;
    virtual string what() {
        return "StackException";
    }
};
template <class X> class StackExceptionNegative :public StackException{
private:
    X elem;
public:
    StackExceptionNegative(X a) : elem(a){}
    void ShowError() {
        cout << elem  << " is negative\n";
    }
    string what(){
        return "StackExceptionNegative";
    }
};
class StackExceptionEmpty : public StackException{
private:
    string message;
public:
    StackExceptionEmpty(string message):message(message){};
    void ShowError(){
        cout << message << '\n';
    }
    string what() {
        return "StackExceptionEmpty";
    }
};
class StackExceptionFull : public StackException{
private:
    int number;
    string message;
public:
    StackExceptionFull(int number, string message):number(number), message(message){};
    void ShowError(){
        cout << number << message << '\n';
    }
    string what() {
        return "StackExceptionFull";
    }
};
// class StackException
// template class StackExceptionNegative:public StackException
// class StackExceptionFull:public StackException
// class StackExceptionEmpty:public StackException

template<class T>
bool is_negative(T x){
    return x < 0;
}

template<>
bool is_negative<Rational>(Rational x){
    return x.get_numerator() * x.get_denominator() < 0;
} // code here

template<class T>
class Stack {
private:
    int max_size, size = -1;
    T sum = 0;
    T * array;
public:
    Stack(int m_size){
        max_size = m_size;
        array = new T[m_size];
    }
    void push(T x){
        if (is_negative(x)){
            throw new StackExceptionNegative<T>(x);
        }
        if (size + 1 >= max_size) {
            throw new StackExceptionFull(max_size, ", max size of the stack is reached");
        }
        size++;
        array[size] = x;
        sum = sum + x;
        
    }
    T pop(){
        if (size < 0){
            throw  new StackExceptionEmpty("Stack is empty");
        }
        T result = array[size];
        size--;
        sum = sum - result;
        return result;
        
    }
    T mean(){
        if (size < 0){
            throw  new StackExceptionEmpty("Stack is empty");
        }
        return sum / (size + 1);
    }
    ~Stack(){
        delete[] array;
    }
    // constructor
    // destructor
    // pop()
    // push(T x)
    // mean()
};

template<class T>
void solve() {
    int n, m;
    cin >> n >> m;
    Stack<T> st(m);
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        try {
            if (t == 1) {
                T x;
                cin >> x;
                st.push(x);
            } else if (t == 2){
                cout << st.pop() << endl;
            } else {
                cout << st.mean()  << endl;
            }
        }
        catch (StackException *e) {
            e->ShowError();
            cout << e->what() << endl;
        }
    }
    
}

int main() {
    string T;
    cin >> T;
    if (T == "Rational") {
        solve<Rational>();
    } else if (T == "int") {
        solve<int>();
    } else if (T == "double") {
        cout << fixed << setprecision(2);
        solve<double>();
    } else {
        cout << "Invalid type" << endl;
    }
    return 0;
}

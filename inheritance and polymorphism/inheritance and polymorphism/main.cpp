#include <iostream>

using namespace std;
class Array{
public:
    int *mas;
    int len;
    Array(int length){
        len = length;
        mas = new int[len];
        for (int i = 0; i < len; i++){
            mas[i] = 0;
        }
    }
    Array( const Array &other ) :len(other.len){
        mas = new int [len];
        for (int i = 0; i < len; i++)
            mas[i] = other.mas[i];
    }
    friend ostream &operator << (ostream &out, Array a){
        for (int i = 0; i < a.len; i++){
            out << a[i] << ' ';
        }
        cout << '\n';
        return out;
    }
    friend istream &operator >> (istream &in, Array& a){
        for (int i = 0; i < a.len; i++){
            in >> a[i];
        }
        return in;
    }
    ~Array(){
        delete[] mas;
    }
    int& operator[](int pos) const{
        return mas[pos];
    }
    void push(int number){
        int s = len;
        Array time(s);
        time = *this;
        delete[] mas;
        mas = new int[s + 1];
        for (int i = 0; i < s; i++){
            mas[i] = time.mas[i];
        }
        mas[s] = number;
    }
};
class ReversedArray : public Array{
public:
    ReversedArray(int n): Array(n){}
    int& operator[](int pos) const{
        return mas[len - pos - 1];
    }
};
int main()
{
    ReversedArray *p2 = new ReversedArray(3);
    Array *p = p2;
    (*p)[0] = 3; (*p)[1] = 5; (*p)[2] = -1;
    for (int i = 0; i < 3; ++i)
        cout << (*p2)[i];
}

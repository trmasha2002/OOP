#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int k = 0;
void f(int a){
    cout << sqrt(a) << ' ';
}
void w(int a){
    cout << a << ' ';
}
int my_rand() {
    return rand() % 100;
}
int change(int s){
    return s - k;
}
bool prime(int number){
    int i = 2;
    while (i * i <= number){
        if (number % i == 0)
            return false;
        i++;
    }
    return true;
}
struct date{
    int day;
    int month;
    int year;
    date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    };
    date(){
        day = 0;
        month = 0;
        year = 0;
    }
};

date rand_data(){
    int day = rand() % 32;
    int month = rand() % 13;
    int year = rand() % 2018;
    date s(day, month, year);
    return s;
}
void cout_data(date a){
    cout << a.day << ' ' << a.month << ' ' << a.year << "   ";
}

bool leap(date a){
    return (a.year % 4 == 0 and a.year % 100 != 0) || (a.year % 400 == 0);
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    vector <date> dats(n);
    generate(a.begin(), a.end(), my_rand);
    cout << "mas a = ";
    for_each(a.begin(), a.end(), w);
    cout << '\n';
    cout << "sqrt a = ";
    for_each(a.begin(), a.end(), f);
    cout << '\n';
    cout << "k = ";
    cin >> k;
    transform(a.begin(), a.end(), b.begin(), change);
    cout << "mas b = ";
    for_each(b.begin(), b.end(), w);
    cout << '\n';
    swap_ranges(a.begin(), a.end(), b.begin());
    cout << "swap mas b = ";
    for_each(b.begin(), b.end(), w);
    cout << '\n';
    cout <<"prime = " <<*(find_if(b.begin(), b.end(), prime)) << ' ';
    cout << '\n';
    random_shuffle(b.begin(), b.end());
    cout << "random_b = ";
    for_each(b.begin(), b.end(), w);
    cout << '\n';
    generate(dats.begin(), dats.end(), rand_data);
    cout << "dates = ";
    for_each(dats.begin(), dats.end(), cout_data);
    cout << '\n';
    if (any_of(dats.begin(), dats.end(), leap)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}

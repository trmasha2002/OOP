#include <iostream>

using namespace std;
class Animal{
public:
    virtual void say() = 0;
};
class Fish : public Animal{
public:
    void say(){
        cout << "bulb" << '\n';
    }
};
class Human : public Animal{
public:
    virtual void drink() = 0;
};
class Russian : public Human{
public:
    void say(){
        cout << "Privet" << '\n';
    }
    void drink(){
        cout << "Vodka" << '\n';
    }
};
class French : public Human{
public:
    void say(){
        cout << "Bonjour" << '\n';
    }
    void drink(){
        cout << "Wine" << '\n';
    }
};
int main()
{
    French fr;
    Russian rus;
    Fish f;
    Animal * an = NULL;
    Human * hum = NULL;
    string s;
    cin >> s;
    if (s == "French") {
        an = &fr;
        hum = &fr;
    }
    else if (s == "Russian"){
        an = &rus;
        hum = &rus;
    }
    else if (s == "Fish") {
        an = &f;
    }
    an->say();
    if (hum != NULL)
        hum->drink();
    return 0;
}

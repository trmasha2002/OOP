#include <iostream>
using namespace std;
class Car{
private:
    string name;
    int year, price;
public:
    Car(string name, int year, int price);
    Car(){};
    void set_price(int new_price){
        price = new_price;
    }
    int get_year(){
        return year;
    }
    string get_name(){
        return name;
    }
    int get_price(){
        return price;
    }
    
    void show();
    ~Car(){};
};
class Catalog{
private:
    Car *array;
    int size = 0;
public:
    Catalog() {
        array = new Car[100];
    }
    void search_name(string name);
    void search_year(int year);
    void search_price(int price);
    void add(Car a){
        
        array[size++] = a;
    }
    
    ~Catalog(){
        delete[] array;
    }
};

Car::Car(string name, int year, int price) {
    this->name = name;
    this->year =  year;
    this->price = price;
}
void Catalog::search_name(string name) {
    for (int i = 0; i <= size; i++){
        if (array[i].get_name() == name){
            array[i].show();
        }
    }
}
void Catalog::search_year(int year) {
    for (int i = 0; i <= size; i++){
        if (array[i].get_year() == year){
            array[i].show();
        }
    }
}
void Catalog::search_price(int price) {
    for (int i = 0; i <= size; i++){
        if (array[i].get_price() == price){
            array[i].show();
        }
    }
}
void Car :: show(){
    cout << name << ' ' << year << ' ' << price << '\n';
}
int main() {
    Catalog Directory;
    int n, index;
    string name;
    int price, year;
    cout << "Введите количество машин: ";
    cin >> n;
    cout << '\n';
    for (int i = 0; i < n; i++){
        cout << "Введите новую машину " << '\n' << '\n';
        cout << "Введите имя машины: ";
        cin >> name;
        cout << '\n';
        cout << "Введите год машины: ";
        cin >> year;
        cout << '\n';
        cout << "Введите цену машины: ";
        
        cin >> price;
        cout << '\n';
        Car a(name, year, price);
        Directory.add(a);
        
    }
    cout << "Введите 1, если хотите искать по имени, 2, если по году, 3, если по цене: ";
    cin >> index;
    if (index == 1){
        cout << "Введите имя: ";
        cin >> name;
        Directory.search_name(name);
        
    }
    else if(index == 2){
        cout << "Введите год: ";
        cin >> year;
        Directory.search_year(year);
    }
    else{
        cout << "Введите цену: ";
        cin >> price;
        Directory.search_price(price);
    }
    return 0;
}

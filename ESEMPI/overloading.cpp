#include <iostream>
using namespace std;

int somma(int a, int b){
    return a+b;
}
int somma(double a, int b){
    return (int)a+b;
}
int somma(int a, double b){
    return a+(int)b;
}
int somma(int a, int b, int c){
    return a+b+c;
}

int main(){
    cout << somma(3, 5) << " " << somma(1.7, 7) << " " << somma(5, 7.6) << " " << somma(1, 2, 3) << endl; 
}

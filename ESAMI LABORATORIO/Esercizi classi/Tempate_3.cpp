/*Definire una funzione template che restituisca 
il valore assoluto di qualunque tipo di dato 
passato in input.*/

#include <iostream>
using namespace std;

template<typename T>
T assoluto(T a){
    return abs(a);
}

int main(){
    int n=-4;
    double d=-2.5;
    cout << assoluto<int>(n) << endl; 
    cout << assoluto<double>(d) <<endl;
}

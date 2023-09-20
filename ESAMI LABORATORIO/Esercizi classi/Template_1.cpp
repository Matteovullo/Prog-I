/*(Esercizio adattato da Luis Joyanes Aguilar. 
Fondamenti di programmazione in C++. Mc Graw Hill.
 Seconda Edizione)
Definire due funzioni template min emax che 
restituiscano il minore e il maggiore di due 
valori. Testare i le due funzioni con i tipi int, 
double, string.*/

#include <iostream>
using namespace std;

template<typename T>
T minimo(T a, T b){
    if(a > b){
        return b;
    }else{
        return a;
    }
}

template<typename T>
T massimo(T a, T b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int n1=3; 
    int n2=5;
    string s1="ciao", s2="ei";
    double d1=2.5, d2=5.1;

    cout << minimo<int>(n1, n2) << endl;
    cout << minimo<string>(s1, s2) << endl;
    cout << minimo<double>(d1, d2) << endl;
    cout << massimo<int>(n1, n2) << endl;
    cout << massimo<string>(s1, s2) << endl;
    cout << massimo<double>(d1, d2) << endl;
}
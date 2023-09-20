/*Definire due funzioni template min emax che restituiscano il minore e il maggiore di due valori. 
Testare i le due funzioni con i tipi int, double, string.*/

#include <iostream>
using namespace std;

template<typename T>
T max(T x,T y){
    if(x > y) return x;
    else return y;
}

int main(){
    cout<<max <int>(3,7)<<endl;
    cout<<max <double>(2.5,2.7)<<endl;
    cout<<max <string>("ciao", "ciaocomestai")<<endl;
}

/*Data una sequenza S di valori, una salita è una qualunque sottosequenza di elementi di 
S consecutivi e non-decrescenti. Scrivere un metodo che prenda come parametro formale un 
array S di long e restituisca l’indice del primo elemento della salita più lunga in S.*/

#include <iostream>
#define n 4
using namespace std;

long fun(long *a){
    int len=0;
    long indice=0;
    long max=a[0];
    int salita_max=0;

    for(int i=0; i<n-1; i++){
        if(a[i] > max){
            max=a[i];
            len++;
            if(len > salita_max){
                salita_max=len;
                indice=salita_max;
            }
        }else{
            len=0;
            max=a[i+1];
        }
    }

    //if(len == 0){
      //  return -1;
    //}else{
        return indice;
    //}
}

int main(){
    long *x=new long [n];
    x[0]=10;
    x[1]=2;
    x[2]=3;
    x[3]=0;

    cout<<fun(x);
}
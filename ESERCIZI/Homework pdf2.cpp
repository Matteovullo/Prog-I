#include <iostream>

using namespace std;

int main(){
	//Scrivere un programma in C++ che chieda all’utente due numeri a e b. Il programma
    //conserva il primo numero in una variabile in virgola mobile, e conserva il secondo
   //numero in una variabile intera, successivamente stampa entrambi i numeri. ??
   
   float a,somma,differenza,max;
   int b;
   cout<<"ins a: " ; cin>>a;
   cout<<"ins b: " ; cin>>b;
   cout<<a<<endl<<b<<endl;
   somma=a+b;
   differenza=a-b;
   if (a>b)
   {
   	a=max;
   }
   else
   {
   	b=max;
   }
   cout<<somma<<endl<<differenza<<endl<<max<<endl;
   
}
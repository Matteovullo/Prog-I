#include<iostream>
#include<cmath>
#include<sstream>
using namespace std;

int main(){
  //Si scriva un programma che:
  //Definisca le variabili float a, b e c;
  //Inserisca dentro le tre variabili i valori nan, inf, -inf e 0 ottenuti mediante debite operazioni artimetiche.::::
  
  float b,c,d,e;
  b=0.0/0;
  c=1.0/0;
  d=-1.0/0;
  e=1/INFINITY;
  cout<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
  
  //Si scriva un programma che:
  //Chiede all’utente di inserire il proprio nome completo (nome e cognome) e lo salva su una variabile di tipo stringa;
  //Chiede all’utente di inserire la propria età e la salva su una variabile intera;
  //Dichiara una variabile di tipo stringa e pone il suo valore pari a “Buongiorno” se l’età è inferiore a 25, “Ciao” altrimenti;
  //Stampa a schermo il messaggio “Buongiorno nome completo” se l’età è inferiore a 25 o “Ciao nome completo”, se l’età è superiore a 25. ????
  
  string nome,cognome;
  cout<<"nome: "; cin>>nome;
  cout<<"cognome: "; cin>>cognome;
  
  int eta;
  cout<<"eta: "; cin>>eta;
  
  if(eta<25)
  {
  	cout<<"ciao"<<nome<<endl;
  }
  else
  {
  	cout<<"buongiorno"<<nome<<endl;
  }
  
  
}


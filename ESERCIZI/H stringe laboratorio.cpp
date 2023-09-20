#include<iostream>

using namespace std;

int main(){

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
  	cout<<"ciao "<<nome<<endl;
  }
  else
  {
  	cout<<"buongiorno "<<nome<<endl;
  }
  
  
}
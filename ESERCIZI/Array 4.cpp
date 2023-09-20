#include <iostream>

using namespace std;

int main (){ 

/*Scrivere un programma che permetta di definire un array dall’input dell’utente.
 Il programma chiede prima all’utente la dimensione dell’array, poi chiede di inserire
  tutti gli elementi dell’array uno per uno. Infine, il programma stampa tutti gli elementi dell’array.*/
  
  int dim;
  
  cout<<"dimensione: ";cin>>dim;
  
  int x[dim];
  
  for(int indice=0; indice<dim; indice++){
     cout<<"inserire numero"<<endl;
	 cin>>x[indice];
	}

  
  for(int indice=0; indice<dim; indice++){
     cout<<"["<<x[indice]<<"]"<<endl;
	}
  
 
}
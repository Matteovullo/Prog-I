/*
Creare una classe chiamata Impiegato che contenga come membri dato il nome e il numero di impiegato e come funzioni membro leggereDati()
e vedereDati() che leggano i dati da tastiera e li visualizzino su schermo rispettivamente. Scrivere un programma che utilizzi la classe,
creando un array di tipo Impiegato e riempiendolo con dati corrispondenti a 10 impiegati. Una volta riempito l’array, visualizzare i dati 
di tutti gli impiegati.
*/

#include<iostream>
using namespace std;

class Impiegato{
	private:
		string nome;
		int numero_impiegato;
	public:
		Impiegato(): nome("nessun nome"), numero_impiegato(0){}
		string leggereDati1(string n){
			nome=n;
			return nome;
		}
		int leggereDati2(int n){
			numero_impiegato=n;
			return numero_impiegato;
		}
		void vedereDati(){
			cout<<"Nome: "<<nome<<endl;
			cout<<"Numero Impiegato: "<<numero_impiegato<<endl;
		}
		
};

int main(){
	Impiegato arr[20];
	for(int i=0; i<20-1; i++){
		string nome_;
		cin>>nome_;
		cout<<endl;
		arr[i].leggereDati1(nome_);
		int numero;
		cin>>numero;
		cout<<endl;
		arr[i+1].leggereDati2(numero);
	}
	for(int i=0; i<20; i++){
		arr[i].vedereDati();
	}
}

/*
Si costruisca una classe Pesce con i seguenti attributi:
nome;
specie;
eta.
La classe pesce deve contenere un metodo getAlong che prende in input un altro pesce e restituisce
true se i due pesci possono andare d’accordo (in base alle specie) e false altrimenti.
Si costruisca una classe Acquario con i seguenti attributi:
capienza massima (massimo numero di pesci);
una collezione di pesci;
La classe Acquario deve permettere di:
inserire un nuovo pesce nell’acquario. Bisogna controllare che il nuovo pesce vada d’accordo con tutti gli altri;
estrarre un pesce dall’acquario;
contare il numero di pesci nell’acquario;
restituire il numero di posti disponibili nell’acquario;
stampare un messaggio del tipo “Acquario di xxx, yyy, …, zzz”, dove xxx, yyy, …, zzz sono i nomi dei pesci contenuti nell’acquario.
*/

#include<string>
#include <iostream>
using namespace std;

class Pesci{
	private:
		string nome;
		string specie;
		int eta;
	public:
		Pesci(string n, string s,int e){
			nome=n;
			specie=s;
			eta=e;
		}
		bool getAlong(Pesci p){
			bool valore;
			if(p.getSpecie()==specie){
				valore=true;
			}else{
				valore=false;
			}
			return valore;
		}
		string getSpecie(){return specie;}
};

#define n 10
class Acquario{
	private:
		int capienza;
		Pesci *arr[n];
	public:
		Acquario(int x){
			capienza=x;
			for(int i=0; i<n; i++){
				arr[i]=nullptr;
			}
		}
		void inserire_pesce(Pesci *p){
			for(int i=0; i<n-1; i++){
				if(arr[i]!=nullptr){
					arr[i]=p;
				}
			}
		}
		void estrarre(int x){
			arr[x]=nullptr;
		}
		int contare(){
			int count;
			for(int i=0; i<n; i++){
				if(arr[i]!=nullptr){
					count++;
				}
			}
			return count;
		}
		int posti_disponibili(){
			int count;
			for(int i=0; i<n; i++){
				if(arr[i]==nullptr){
					count++;
				}
			}
			return count;
		}
		void stampa(){
			cout<<"acquario di "<<endl;
			for(int i=0; i<capienza; i++){
				cout<<arr[i]<<endl;
			}
		}
};

int main(){
	return 0;
}

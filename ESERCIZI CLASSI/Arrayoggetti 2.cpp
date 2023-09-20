/*
Si costruisca una classe Veicolo con i seguenti attributi:
modello;
numero di ruote;
tipologia (può essere motociclo, automobile, furgone o mezzo pesante).
Si costruisca dunque una classe Parcheggio con i seguenti attributi:
capienza;
indirizzo;
un array di puntatori a Veicolo.
La classe Parcheggio deve possedere dei metodi che permettono di:
inserire un veicolo nel parcheggio (prende in input un puntatore a Veicolo e restituisce il numero di stallo);
rimuovere un veicolo dal parcheggio (prende in input il numero di stallo e restituisce un puntatore a Veicolo);
calcolare la tariffa dato un veicolo e un numero di giorno. 
La tariffa è ottenuta moltiplicando il numero di giorni per 4.5 per le automobili, 3.5 per i motocicli, 5 per i furgoni
 e 7 per i mezzi pesanti;
contare quanti veicoli sono presenti nel parcheggio;
calcolare il numero di stalli liberi;
restituire il numero del primo stallo libero.
I metodi implementati devono effettuare i controlli necessari per assicurarsi che gli inserimenti 
e le rimozioni siano consistenti (es. controllare che non si ecceda la capienza massima).
*/

#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Veicolo{
	private:
		string modello;
		int numero_di_ruote;
		string tipologia;
	public:
		Veicolo(string modello_, int numero_di_ruote_, string tipologia_) : modello(modello_), numero_di_ruote(numero_di_ruote_), tipologia(tipologia_){}
		string getTipologia(){return tipologia;}
};

 #define n 40
 
class Parcheggio{
	private:
		int capienza;
		int indirizzo;
		Veicolo *arr[n];
		double prezzo;
		int stallo;
	public:
		Parcheggio() : capienza(20){}
		Parcheggio(int c) : capienza(c) {}
		int veicolo_parcheggiato(Veicolo *v){
			srand(time(0));
			int stallo=rand()%capienza+1;
			return stallo;
		}
		int getStallo(){return stallo;}
		Veicolo* rimuovere_veicolo(){
			arr[getStallo()]=nullptr;
			Veicolo *p=nullptr;
			return p;
		}
		double calcolo_tariffa(int giorno, Veicolo v){
			if(v.getTipologia()=="automobili"){
				prezzo=4.5*giorno;
			}
			if(v.getTipologia()=="motociclo"){
				prezzo=3.5*giorno;
			}
			if(v.getTipologia()=="furgone"){
				prezzo=5*giorno;
			}
			if(v.getTipologia()=="mezzo pesante"){
				prezzo=7*giorno;
			}
			return prezzo;
		}
		int conta(){
			int count;
			for(int i=0; i<capienza; i++){
				if(arr[i]!=nullptr){
					count++;
				}
			}
			return count;
		}
		int stalli_liberi(){
			int count;
			for(int i=0; i<capienza; i++){
				if(arr[i]==nullptr){
					count++;
				}
			}
			return count;
		}
		int prox_stallo_libero(){
			return getStallo()+1;
		}
};
int main(){
	return 0;
}

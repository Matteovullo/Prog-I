/*
Creare una classe Ora che abbia membri dati di tipo int per ore, minuti e secondi. 
Un costruttore inizializzerà questi dati a 0, mentre un altro li inizializzerà a valori passati al costruttore.
Una funzione membro dovrà visualizzare l’ora in formato 11:59:59. Un’altra funzione membro sommerà 
l’oggetto di tipo Ora a un altro oggetto di tipo Ora preso in input come argomento. Una funzione principale main() deve
creare due oggetti inizializzati con valori passati al costruttore e un terzo inizializzato con zeri. 
Stampare i valori dei tre oggetti, poi sommare il secondo al primo e il secondo al terzo e stampare i valori del primo e del terzo.
*/

#include <iostream>
using namespace std;

class Ora{
	private:
		int ora, minuti, secondi;
	public:
		Ora(int _ora, int _minuti, int _secondi) : ora(_ora), minuti(_minuti), secondi(_secondi) {};
		void ora_corrente(){
			cout<<ora<<":"<<minuti<<":"<<secondi<<endl;
		}
		int getOra(){return ora;}
		int getMinuti(){return minuti;}
		int getSecondi(){return secondi;}
		void somma(Ora o){
			ora+=o.getOra();
			minuti+=o.getMinuti();
			secondi+=o.getSecondi();
		}
};

int main(){
	Ora o1(11,2,3);
	Ora o2(2,3,4);
	Ora o3(0,0,0);
	o1.ora_corrente();
	o2.ora_corrente();
	o3.ora_corrente();
	o2.somma(o1);
	o2.somma(o3);
	o1.ora_corrente();
	o3.ora_corrente();
	return 0;
}

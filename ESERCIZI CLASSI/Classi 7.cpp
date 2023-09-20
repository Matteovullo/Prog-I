/*
Si costruisca un oggetto ContoInBanca che memorizzi i seguenti dati:
Numero di conto;
Giacenza;
Nome del proprietario;
E permetta di eseguire queste operazioni:
Ottenere il nome del proprietario;
Ottenere il numero di conto;
Ottenere la giacenza;
Effettuare un prelievo;
Effettuare un versamento;
Pagare l’imposta di bollo (pari a 34,20 €);
Pagare le spese mensili del conto (pari a 12 €);
L’oggetto deve avere due costruttori:
Un costruttore prende in input il nome del proprietario, il numero del conto e la giacenza;
Un costruttore prende in input il nome del proprietario e il numero del conto, e imposta la giacenza a zero.
Costruire una funzione main che definisca e utilizzi diversi conti correnti intestati a diverse persone.
*/

#include <iostream>
using namespace std;

class ContoInBanca{
	private:
		int numero_conto;
		double giacenza;
		string nome_proprietario;
	public:
		ContoInBanca(string s, int c, double g) : nome_proprietario(s), numero_conto(c), giacenza(g) {}
		ContoInBanca(string s, int c) : nome_proprietario(s), numero_conto(c), giacenza(0) {}
		void prelievo(double x){
			giacenza=giacenza-x;
		}
		void versamento(double y){
			giacenza=giacenza+y;
		}
		void bollo(){
			giacenza=giacenza-34,20;
		}
		void spese_mensili(){
			giacenza=giacenza-12;
		}
		int getNumeroConto(){return numero_conto;}
		double getGiacenza(){return giacenza;}
		string getNomePropietario(){return nome_proprietario;}
};

int main(){
	ContoInBanca a("claudio",123456789,1000);
	a.prelievo(200.00);
	cout<<a.getGiacenza();
	return 0;
}

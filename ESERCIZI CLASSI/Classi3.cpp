/*
Si costruisca una classe Moneta che implementi una moneta a due facce.
Il costruttore prende in input un double p e controlla che questa sia compreso tra 0 e 1. 
Quando la moneta viene lanciata, uscirà “testa” con probabilità p e “croce” con probabilità 1−p. 
Prevedere un costruttore che non prende in input alcun parametro e imposta p=0.5.
 Costruire un programma che crei due monete con probabilità p casuali, le lanci 1000 volte e mostri,
le probabilità assegnate e il numero di teste ottenute da entrambe le monete.
NOTA: Un modo semplice per eseguire una riga di codice con probabilità p è il seguente:
double rnd = double(rand())/RAND_MAX;
if(rnd>p) {
    //codice
}
*/

class Moneta{
	private:
		double probabilita;
	public:
		Moneta(double p){
			if(p<0 && p>1){
				cout<<"erroe!";
			}
			probabilita=p;
		}
		Moneta(double p=0.5) : probabilita(p){}
		void lancio(){
			rnd = double(rand())/RAND_MAX;
			if(rnd>p) {
				
			}
		}

};

int main(){
	Moneta m;
	Moneta t;
	for(int i=0; i<1000; i++){
		
	}
	return 0;
}

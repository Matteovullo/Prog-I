/*
Implementare una clase Random per la generazione di numeri pseudocasuali. La funzione deve possedere:
Un costruttore di default che imposta un seed che dipende dall’ora attuale;
Un costruttore che permette di impostare un seed che dipende dall’ora passata in input (tipo tipe_t);
Un costruttore che permette di impostare il seed passato in input al costruttore.
Un metodo generateDouble che prende in input due parametri double a e b e genera un numero compreso tra a e b. 
Se nessun parametro è passato al metodo, si assume che a=0 e b=1;
Un metodo generateInt che prende in input due parametri int a e b e genera un numero compreso tra a e b. 
Se nessun parametro è passato al metodo, si assume a=0 e b=RAND_MAX.
*/

#include<cstdlib>
#include<ctime>
using namespace std;

class Random{
	private:
		double random1;
		int random2;
	public:
		Random(){
			srand(time(0));
		}
		Random(time_t seed){
			srand(seed);
		}
		Random(int ora){
			srand(ora);
		}
		double generateDouble(double a=0.0, double b=1.0){
			random1=rand()/(RAND_MAX*b);
			return random1;
		}
		int generateInt(int a=0, int b=RAND_MAX){
			random2=rand()%a+b;
			return random2;
		}
};

int main(){
	return 0;
}

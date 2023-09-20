/*Implementare una clase Random per la generazione di numeri pseudocasuali. La funzione deve possedere:
Un costruttore di default che imposta un seed che dipende dall’ora attuale;
Un costruttore che permette di impostare un seed che dipende dall’ora passata in input (tipo tipe_t);
Un costruttore che permette di impostare il seed passato in input al costruttore.
Un metodo generateDouble che prende in input due parametri double a e b e genera un 
numero compreso tra a e b. Se nessun parametro è passato al metodo, si assume che a=0 e b=1;
Un metodo generateInt che prende in input due parametri int a e b e genera un numero compreso 
tra a e b. Se nessun parametro è passato al metodo, si assume a=0 e b=RAND_MAX.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Random{
    private:

    public:
        Random(){
            srand(time(0));
        }
        Random(time_t curtime){
            srand(time(&curtime));
        }
        Random(int i){
            srand(i);
        }
        double generaDouble(double a=0, double b=1){
            if(a > b)
                return (b-a)*(1.0*rand()/RAND_MAX)+a;
            else   
                return (a-b)*(1.0*rand()/RAND_MAX)+b;
        }
        int generaInt(int a=0, int b=RAND_MAX){
            if(a < b)
                return rand()%(b-a+1)+a;
            else
                return rand()%(a-b+1)+a;
        }
};

int main(){
    Random r;
    for(int i=0; i<20; i++){
        cout << r.generaDouble(0.22, 0.33) << endl;
    }
    cout << r.generaInt(2, 5) << endl;
}

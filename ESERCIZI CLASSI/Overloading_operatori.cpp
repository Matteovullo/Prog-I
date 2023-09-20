/*Scrivere una classe Razionale per i numeri razionali, cioè i numeri he possono essere 
rappresentati come frazioni (1/2, 3/5, ecc). La classe deve possedere un metodo stampa che 
stampi il contenuto dell’oggetto (es. 1/2). Sovraccaricare i seguenti opeartori in modo da 
permettere operazioni e confronti tra oggetti di tipo Razionale:

==;

<;

<=;

>;

>=;

+;

-;

*;

/.

Scrivere un programma che testi la correttezza del codice scritto.*/

#include <iostream>
using namespace std;

class Razionale{
    int parteintera;
    int partedecimale;
    public:
        Raziononale(int parteintera, int partedecimale){
            this->parteintera=parteintera;
            this->partedecimale=partedecimale;
        }
        void stampa(){
            cout<<parteintera<<"/"<<partedecimale<<endl;
        }
};

Razionale operator+(Razionale a, Razionale b){
    return Razionale(a.x+b.x, a.y+b.y);
}

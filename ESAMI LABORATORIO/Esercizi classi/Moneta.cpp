/*Si costruisca una classe Moneta che implementi una moneta a due facce. 
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

#include <iostream>

using namespace std;

class Moneta{
    private:
        int testa=0;
        int croce=0;
        double probalitita;

    public:
        Moneta(double p){
            probalitita=p;
            if(p < 0 && p >1){
            do{
                cout << "Inserie p=";
                cin >> probalitita;
            }while(p < 0 && p >1);
            }
        }
        Moneta(){
            probalitita=0.5;
        }
        void lancia(){
            double rnd = double(rand())/RAND_MAX;
                if(rnd>=probalitita) {
                    croce++;
                }else{
                    testa++;
                }
        }
        int getTesta(){
            return testa;
        }
};

int main(){
    Moneta m1(1);
    Moneta m2(0.5);
    for(int i=0; i<1000; i++){
        m1.lancia();
        m2.lancia();
    }
    cout << m1.getTesta() << endl;
    cout << m2.getTesta() << endl;
}


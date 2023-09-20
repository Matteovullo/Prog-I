/*Si costruisca un oggetto ContoInBanca che memorizzi i 
seguenti dati:
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
Un costruttore prende in input il nome del proprietario, 
il numero del conto e la giacenza;
Un costruttore prende in input il nome del proprietario e
il numero del conto, e imposta la giacenza a zero.
Costruire una funzione main che definisca e utilizzi diversi 
conti correnti intestati a diverse persone.*/

#include <iostream>

using namespace std;

class ContoInBanca{
    private:
        int numero_conto;
        double giacenza;
        string nome_propietario;

    public:
        ContoInBanca(int numero_conto, string nome_propietario){
            this->numero_conto=numero_conto;
            this->nome_propietario=nome_propietario;
            giacenza=0.0;
        }
        ContoInBanca(int numero_conto, string nome_propietario, double giacenza){
            this->numero_conto=numero_conto;
            this->nome_propietario=nome_propietario;
            this->giacenza=giacenza;
        }
        string getNome_propietario(){
            return nome_propietario;
        }
        int getNumero_conto(){
            return numero_conto;
        }
        double getGiacenza(){
            return giacenza;
        }
        void prelievo(double d){
            giacenza-=d;
        }
        void prelievo(int i){
            giacenza-=i;
        }
        void versamento(double d){
            giacenza+=d;
        }
        void versamento(int i){
            giacenza+=i;
        }
        void imposta(){
            giacenza-=34.20;
        }
        void spese_mensili(){
            giacenza-=12.00;
        }
};

int main(){
    ContoInBanca c2(1111, "Matteo");
    ContoInBanca c1(1111, "Matteo", 10000.00);
    cout << c1.getNome_propietario() << endl;
    cout << c1.getNumero_conto() << endl;
    cout << c1.getGiacenza() << endl;
    c1.prelievo(1000);
    c1.imposta();
    c1.spese_mensili();
    c1.versamento(100);
    cout << c1.getGiacenza() << endl;
}
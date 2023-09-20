/*Creare una classe chiamata Impiegato che contenga come 
membri dato il nome e il numero di impiegato e come funzioni 
membro leggereDati() e vedereDati() che leggano i dati da 
tastiera e li visualizzino su schermo rispettivamente. 
Scrivere un programma che utilizzi la classe, creando 
un array di tipo Impiegato e riempiendolo con dati 
corrispondenti a 10 impiegati. Una volta riempito l’array, 
visualizzare i dati di tutti gli impiegati.*/

#include <iostream>

using namespace std;

class Impiegato{
    private:
        string nome;
        string numero;

    public:
        Impiegato(string nome, string numero){
            this->nome=nome;
            this->numero=numero;
        }
        string leggereDati(){
            return nome+" "+numero;
        }
        void vedereDati(){
            cout << leggereDati() << endl;
        }
};

int main(){
    Impiegato **array=new Impiegato*[10];
    for(int i=0; i<10; i++){
        array[i]=new Impiegato("Matteo", "1000034661");
        array[i]->vedereDati();
    }
}
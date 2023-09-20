/*Si costruisca una classe Pesce con i seguenti attributi:
nome;
specie;
eta.
La classe pesce deve contenere un metodo getAlong 
che prende in input un altro pesce e restituisce true 
se i due pesci possono 
andare d’accordo (in base alle specie) e false altrimenti.
Si costruisca una classe Acquario con i seguenti attributi:
capienza massima (massimo numero di pesci);
una collezione di pesci;
La classe Acquario deve permettere di:
inserire un nuovo pesce nell’acquario. Bisogna controllare 
che il nuovo pesce vada d’accordo con tutti gli altri;
estrarre un pesce dall’acquario;
contare il numero di pesci nell’acquario;
restituire il numero di posti disponibili nell’acquario;
stampare un messaggio del tipo “Acquario di
 xxx, yyy, …, zzz”, dove xxx, yyy, …, zzz sono i 
 nomi dei pesci contenuti nell’acquario.*/

#include <iostream>

using namespace std;

class Pesce{
    private:
        string nome;
        string specie;
        int eta;

    public:
        Pesce(string nome, string specie, int eta){
            this->nome=nome;
            this->specie=specie;
            this->eta=eta;
        }
        string getSpecie(){
            return specie;
        }
        string getNome(){
            return nome;
        }
        bool getAlong(Pesce *p){
            if(p->getSpecie() == specie){
                return true;
            }else{
                return false;
            }
        }
};

class Aquario{
    private:
        int capienza_massima;
        Pesce **array;

    public:
        Aquario(int capienza_massima){
            this->capienza_massima=capienza_massima;
            array=new Pesce*[capienza_massima];
            for(int i=0; i<capienza_massima; i++){
                array[i]=nullptr;
            }
        }
        void inserire(Pesce *p){
            bool daccordo=false;
            int c=0;
            for(int i=0; i<capienza_massima; i++){
                if(array[i] && array[i]->getAlong(p))
                    c++;
            }
            if(c == numero()){
                for(int i=0; i<capienza_massima; i++){
                    if(array[i] == nullptr)
                        array[i]=p;
                        break;
                }
            }
        }
        Pesce* estrarre(int i){
            if(i < capienza_massima){
                Pesce *ptr;
                ptr=array[i];
                array[i]=nullptr;
                return ptr;
            }else{
                return nullptr;
            }
        }
        int numero(){
            int c=0;
            for(int i=0; i<capienza_massima; i++){
                if(array[i])
                    c++;
            }
            return c;
        }
        int disponibilita(){
            int c=0;
            for(int i=0; i<capienza_massima; i++){
                if(array[i] == nullptr)
                    c++;
            }
            return c;
        }
        void stampa(){
            cout << "Aquario di: ";
            for(int i=0; i<capienza_massima; i++){
                if(array[i])
                    cout << array[i]->getNome() << " ";
            }
            cout << endl;
        }
};

int main(){
    Aquario a(10);
    Pesce p("eee", "pesce cane", 10);
    Pesce *ptr;
    ptr=&p;
    a.inserire(ptr);
    cout << a.disponibilita() << endl;
    cout << a.numero() << endl;
    a.stampa();
    a.estrarre(0);
}
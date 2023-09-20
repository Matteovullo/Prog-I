#include <iostream>

using namespace std;

class Scatola{
    private:
        int peso, altezza, lunghezza, larghezza;

    public:
        Scatola(int peso, int altezza, int lunghezza, int larghezza){
            this->altezza=altezza;
            this->peso=peso;
            this->lunghezza=lunghezza;
            this->larghezza=larghezza;
        }
        int getLunghezza(){
            return lunghezza;
        }
        int getLarghezza(){
            return larghezza;
        }
        int getPeso(){
            return peso;
        }
        int getAltezza(){
            return altezza;
        }
        int base(){
            return (larghezza*lunghezza)/2;
        }
        int densitamedia(){
            return peso/volume();
        }
        int volume(){
            return base()*altezza;
        }
        void print(){
            cout << "Peso: " << getPeso() << "Altezza: " << getAltezza() << "Lunghezza: " << getLunghezza() << endl;
        }
};

class Giocoinscatola : public Scatola{
    protected:
        string nome;
        int giocatori;

    public:
        Giocoinscatola(int p, int a, int l, int l2, string nome, int giocatori) : Scatola(p, a, l ,l2){
            this->nome=nome;
            this->giocatori=giocatori;
        }
        int getGiocatori(){
            return giocatori;
        }
        string getNome(){
            return nome;
        }
        void print(){
            cout << "Peso: " << getPeso() << "Altezza: " << getAltezza() << "Lunghezza: " << getLunghezza() << "numero di giocatori: " << giocatori << ", mome gioco" << nome << endl;
        }
};

int main(){
    Giocoinscatola g1(100, 10, 10, 2, "IIIIIII", 10);
    Giocoinscatola g2(10, 1, 5, 2, "IIIIIII", 10);

    if(g1.volume()/g1.getGiocatori() >  g2.volume()/g2.getGiocatori()){
        cout << "g1 ha un rapporto superiore";
    }else{
        cout << "g2 ha un rapporto superiore";
    }
    return 0;
}
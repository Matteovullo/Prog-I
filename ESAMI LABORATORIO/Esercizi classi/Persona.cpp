/*Si costruisca una classe “Persona” che abbia gli attributi:
string: nome: contiene il nome della persona;
string: cognome: contiene il cognome della persona;
int: eta: contiene l’età della persona;
e i seguenti metodi:
Persona(): il costruttore: deve prendere in input i parametri appropriati per costruire l’oggetto 
inizializzando gli attributi;
saluta(): stampa a schermo un testo a caso tra “Buongiorno”, “Buonasera” e “Ciao”;
dici_nome(): stampa a schermo il testo “Mi chiamo nome cognome”, dove nome e cognome sono i valori degli 
omonimi attributi;
dici_eta(): stampa a schermo il testo “La mia eta’ e’: eta”, dove eta è il valore dell’attributo eta;
invecchia(): incrementa l’età di una unità;
saluta_persona(): prende in input un oggetto di tipo Persona e stampa il testo “saluto nome cognome, 
piacere di conoscerti”, dove nome e cognome sono i valori degli omonimi attributi dell’oggetto Persona preso in input, mentre saluto è uguale a “Buongiorno” se l’età della persona salutata è superiore all’età della persona che saluta, “Ciao” altrimenti.
La classe dovrà contenere inoltre i metodi setter e getter per ciascun attributo.
Definire quindi un main che costruisca più oggetti persona e li faccia interagire.*/

#include <iostream>

using namespace std;

class Persona{
    private:
        string nome;
        string cognome;
        int eta;

    public:
        Persona(string nome, string cognome, int eta){
            this->nome=nome;
            this->cognome=cognome;
            this->eta=eta;
        }
        void saluta(){
            int r=rand()%(3-1+1)+1;
            if(r==1)
                cout << "Buongiorno" << endl;
            if(r==2)
                cout << "Buonasera" << endl;
            if(r==3)
                cout << "Ciao" << endl;
        }
        void dici_nome(){
            cout << "Mi chiamo " << nome << " " << cognome << endl;
        }
        void dici_eta(){
            cout << "La mia eta è: " << eta << endl;
        }
        void invecchia(){
            eta++;
        }
        string getNome(){
            return nome;
        }
        string getCognome(){
            return cognome;
        }
        int getEta(){
            return eta;
        }
        void setNome(string nome){
            this->nome=nome;
        }
        void setCognome(string cognome){
            this->cognome=cognome;
        }
        void setEta(int eta){
            this->eta=eta;
        }
        void saluta_persona(Persona p){
            if(getEta() < p.getEta())
                cout << "Buongiorno";
            else
                cout << "Ciao";
            
            cout << " " << p.getNome() << " " << p.getCognome() << endl;
        }
};

int main(){
    Persona p1("Matteo", "Vullo", 19);
    Persona p2("Luca", "Vullo", 30);
    p1.invecchia();
    p1.invecchia();
    p1.invecchia();
    p1.saluta_persona(p2);
    p1.dici_eta();
    p1.dici_nome();
    p1.saluta();
    cout << p1.getEta() << endl;
}
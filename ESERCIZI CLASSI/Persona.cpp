/*Si costruisca una classe “Persona” che abbia gli attributi:
string: nome: contiene il nome della persona;
string: cognome: contiene il cognome della persona;
int: eta: contiene l’età della persona;
e i seguenti metodi:
Persona(): il costruttore: deve prendere in input i parametri appropriati per costruire 
l’oggetto inizializzando gli attributi;
saluta(): stampa a schermo un testo a caso tra “Buongiorno”, “Buonasera” e “Ciao”;
dici_nome(): stampa a schermo il testo “Mi chiamo nome cognome”, dove nome e cognome 
sono i valori degli omonimi attributi;
dici_eta(): stampa a schermo il testo “La mia eta’ e’: eta”, dove eta è il valore dell’attributo eta;
invecchia(): incrementa l’età di una unità;
saluta_persona(): prende in input un oggetto di tipo Persona e stampa il testo “saluto nome cognome,
piacere di conoscerti”, dove nome e cognome sono i valori degli omonimi attributi dell’oggetto Persona 
preso in input, mentre saluto è uguale a “Buongiorno” se l’età della persona salutata è superiore 
all’età della persona che saluta, “Ciao” altrimenti.
La classe dovrà contenere inoltre i metodi setter e getter per ciascun attributo.
Definire quindi un main che costruisca più oggetti persona e li faccia interagire.*/

#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Persona{
    private:
    string nome;
    string cognome;
    int eta;
    public:
    Persona(string _nome, string _cognome, int _eta) : nome(_nome), cognome(_cognome), eta(_eta) {};

    void saluta(){
        srand(time(0));

        int r = rand()%3+1;
        if(r==1){
            cout<<"buongiorno";
        }else if(r==2){
            cout<<"buonasera";
        }else if(r==3){
            cout<<"ciao";
        }
    }

    void dici_nome(){
        cout<<"mi chiamo"<<nome<<cognome<<endl;
    }

    void dici_eta(){
        cout<<"la mia età è:"<<eta<<endl;
    }

    void invecchia(){
        eta++;
    }

    void saluta_persone(Persona pe1){
        string saluto;
        if(pe1.getEta()<getEta()){
        	saluto="buongiorno";
		}else{
			saluto="ciao!";
		}
        cout<<saluto<<" "<<pe1.getNome()<<" "<<pe1.getCognome()<<",piacere di conoscerti !"<<endl;
    }

    string getNome(){return nome;}
    string getCognome(){return cognome;}
    int getEta (){return eta;} 
    void setNome (string a){nome=a;} ;
    void setCognome (string b){cognome=b;};
    void setEta (int c){eta=c;};


};
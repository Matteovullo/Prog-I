/*Si modifichi l’esercizio precedente rappresentando 
ciascun giocatore con la classe Persona. A tale scopo, 
chiedere all’utente di inserire i nomi, i cognomi e le età 
di ciascun giocatore. Il gioco va avanti come definito 
nell’esercizio precedente, con la differenza che i dadi 
vengono tirati nell’ordine discendente definito dalle età. 
Nelle stampe del tipo “Il giocatore x tira il dado”, 
sostituire “giocatore x” con il nome del giocatore.*/

#include<iostream>
#include<cstdlib>
#include<ctime>

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

class Dado {
    private:
        short valore; //questo attributo contiene il valore attuale del dado
                      //si tratta del valore della faccia rivolta verso l'alto
    public:
        Dado(); //costruttore di default
        Dado(time_t); //costruttore alternativo che permette di impostare un particolare seed
        void lancia(); //lancia il dado
        short getValore(); //legge il valore del dado
};

Dado::Dado() {
    // imposta il seed di default
    srand(time(0));
    lancia(); //lanciamo il dado appena creato
}

Dado::Dado(time_t seed) {
    srand(seed); //impostiamo il seed ricevuto in input
    lancia(); //lanciamo il dado appena creato
}

void Dado::lancia() {
    valore = rand()%6 + 1 ; //numero casuale tra 1 e 6
}

short Dado::getValore() {
    return valore;
}

class Mazzo {
    bool carte_pescate[40]; //indica se la carta di indice i è stata pescata
    public:
        Mazzo(); //costruttore
        short pescaCarta(); //pesca una carta
        short contaCarte(); //conta le carte non pescate
        void ricomponi(); //ricompone il mazzo recuperando le carte pescate
};

// costruttore
Mazzo::Mazzo() {
    ricomponi(); //ricompone il mazzo
    srand(time(0)); //imposta un seed
}

// pesca una carta
short Mazzo::pescaCarta() {
    // se non ci sono più carte, restituisci -1
    if(contaCarte()==0)
        return -1;
    // variabile che contiene l'indice della carta
    short carta;
    do {
        carta = rand() % 40; //numero casuale intero tra 0 e 39
    } while(carte_pescate[carta]==true); //ripeti finché la carta scelta è già pescata
    carte_pescate[carta] = true; //imposta la carta come pescata
    return carta+1; //restituisci carta+1 (le carte vanno da 1 a 40, mentre gli inidici da 0 a 39)
}

//conta le carte non pescate del mazzo
short Mazzo::contaCarte() {
    // inizializza una variabile contatore
    short num = 0;
    for(int i=0; i<40; i++) // scorri il mazzo
        num+=!carte_pescate[i]; //conta solo le carte non pescate
    return num; //restituisci il numero
}

// ricompone il mazzo
void Mazzo::ricomponi() {
    // reimposta tutte le carte come non pescate
    for(int i=0; i<40; i++) {
        carte_pescate[i] = false;
    }
}

int main(){
    string n1="";
    string c1="";
    int e1=0;
    Mazzo m1;
    Persona p1("", "", 0);
    Persona p2("", "", 0);
    Persona p3("", "", 0);
    for(int i=0; i<3; i++){
        cin >> n1;
        cin >> c1;
        cin >> e1;
        if(i==0){
            p1.setNome(n1);
            p1.setCognome(c1);
            p1.setEta(e1);
        }
        if(i==1){
            p2.setNome(n1);
            p2.setCognome(c1);
            p2.setEta(e1);
        }
        if(i==2){
            p3.setNome(n1);
            p3.setCognome(c1);
            p3.setEta(e1);
        }
    }

    short p1=0;
    short p2=0;
    short p3=0;
    Dado d1;
    Mazzo m1;
    int array[3];
    bool valore=true;
    do{
    for(int i=0; i<3; i++){
        if(p1.getEta() < p2.getEta() && p1.getEta() < p3.getEta()){
            d1.lancia();
            array[i]=d1.getValore();
        }
         
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i!=j && array[i]==array[j]){
                valore=false;
            }
        }
    }
    valore=true;
    }while(!valore);

    for(int i=0; i<10; i++){
        if(array[0] > array[1] && array[0] > array[2]){
            p1+=m1.pescaCarta();
            if(array[1] > array[2]){
                p2+=m1.pescaCarta();
                p3+=m1.pescaCarta();
            }else{
                p3+=m1.pescaCarta();
                p2+=m1.pescaCarta();
            }
        }
        if(array[1] > array[0] && array[1] > array[2]){
            p2+=m1.pescaCarta();
            if(array[0] > array[2]){
                p1+=m1.pescaCarta();
                p3+=m1.pescaCarta();
            }else{
                p3+=m1.pescaCarta();
                p1+=m1.pescaCarta();
            }
        }
        if(array[2] > array[0] && array[2] > array[0]){
            p3+=m1.pescaCarta();
            if(array[0] > array[1]){
                p1+=m1.pescaCarta();
                p2+=m1.pescaCarta();
            }else{
                p2+=m1.pescaCarta();
                p1+=m1.pescaCarta();
            }
        }
    }

    cout << p1 << " " << p2 << " " << p3;
}
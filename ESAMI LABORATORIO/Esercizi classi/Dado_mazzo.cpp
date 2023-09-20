/*Si utilizzino le classi Dado e Mazzo per costruire un 
programma che simuli un gioco con tre giocatori in cui:
Ad ogni turno i tre giocatori tirano un dado a testa. 
Chi ottiene il numero più alto sarà il primo a pescare 
una carta. Se due o più giocatori hanno ottenuto lo stesso 
numero, questi tirano nuovamente i dadi finché non viene stabilito un ordine univoco tra i tre giocatori;
I giocatori pescano una carte a testa dal mazzo nell’ordine 
indicato dalla mano di dadi e sommano il valore della carta 
al proprio punteggio;
Il gioco va avanti così per 10 mani. Vince il giocatore che h
a ottenuto il punteggio totale maggiore.*/


#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

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
    short p1=0;
    short p2=0;
    short p3=0;
    Dado d1;
    Mazzo m1;
    int array[3];
    bool valore=true;
    do{
    for(int i=0; i<3; i++){
        d1.lancia();
        array[i]=d1.getValore();
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
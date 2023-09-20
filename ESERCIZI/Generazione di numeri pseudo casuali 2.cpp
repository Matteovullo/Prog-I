#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*Scrivere un programma che simula una partita a carte tra l’utente e il calcolatore. Le regole del gioco sono molto semplici:
 il giocatore pesca una carta da un mazzo di 10 carte numerate da 1 a 10. Il calcolatore pesca una carta dalle restanti 9.
  Chi ottiene il numero più alto vince. Per simulare il fatto che il giocatore “pesca” dal mazzo, 
sarà permesso al giocatore di inserire un numero intero che, sommato al tempo corrente, verrà usato come seed per la simulazione.*/

int main(){
	int n;
	cout<<"inserire un numero intero: ";cin>>n;
	
	if (cin.fail()){
		cout<<"errore numero non valido";
		return EXIT_FAILURE;
	}
	srand(time(0)+n);
	
	int carta_utente=rand()% 10+1;
	int carta_calcolatore;
	
	
	do {
        carta_calcolatore = rand() % 10 + 1;
    } while(carta_utente==carta_calcolatore);

    if (carta_utente>carta_calcolatore) {
        cout << "Vince il giocatore con la carta " << carta_utente << " contro la carta " << carta_calcolatore << " del calcolatore";
    } else if (carta_calcolatore > carta_utente) {
        cout << "Vince il calcolatore con la carta " << carta_calcolatore << " contro la carta " << carta_utente << " del giocatore";
    } else {
        cout << "Pari!";
    }
	

	
	
}
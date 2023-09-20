/*
Si utilizzino le classi Dado e Mazzo per costruire un programma che simuli un gioco con tre giocatori in cui:
Ad ogni turno i tre giocatori tirano un dado a testa. 
Chi ottiene il numero più alto sarà il primo a pescare una carta.
Se due o più giocatori hanno ottenuto lo stesso numero, questi tirano nuovamente i dadi finché non viene stabilito
un ordine univoco tra i tre giocatori;
I giocatori pescano una carte a testa dal mazzo nell’ordine indicato dalla mano di dadi e sommano il valore della carta al proprio punteggio;
Il gioco va avanti così per 10 mani. Vince il giocatore che ha ottenuto il punteggio totale maggiore.
*/

#include "dado.h"
#include "mazzo.h"
#include <iostream>
using namespace std;


int main(){
	Dado d1;
	Dado d2;
	Dado d3;
	Mazzo m;
	
	short g1;
	short g2;
	short g3;
	
	short c1;
	short c2;
	short c3;
	
	int punteggio1;
	int punteggio2;
	int punteggio3;
	
	d1.lancia();
	d2.lancia();
	d3.lancia();
	
	g1=d1.getValore();
	g2=d2.getValore();
	g3=d3.getValore();
		
		if(g1==g2 || g1==g3 || g2==g3){
			d1.lancia();
			d2.lancia();
			d3.lancia();
			g1=d1.getValore();
			g2=d2.getValore();
			g3=d3.getValore();
		}
	
	for(int i=0; i<10; i++){
		if(g1>g2 && g1>g3){
			c1=m.pescaCarta();
			if(g2>g3){
				c2=m.pescaCarta();
				c3=m.pescaCarta();
			}else{
				c3=m.pescaCarta();
				c2=m.pescaCarta();
			}
		}else if(g2>g1 && g2>g1){
			c3=m.pescaCarta();
			if(g1>g3){
				c1=m.pescaCarta();
				c3=m.pescaCarta();
			}else{
				c3=m.pescaCarta();
				c1=m.pescaCarta();
			}
		}else if(g3>g1 && g3>g2){
			c3=m.pescaCarta();
			if(g2>g1){
				c2=m.pescaCarta();
				c1=m.pescaCarta();
			}else{
				c1=m.pescaCarta();
				c2=m.pescaCarta();
			}
		}
		punteggio1+=c1;
		punteggio2+=c2;
		punteggio3+=c3;
	}
	
	if(punteggio1>punteggio2 && punteggio1>punteggio2){
		cout<<"ha vinto il giocatore 1";
	}
	if(punteggio2>punteggio1 && punteggio2>punteggio3){
		cout<<"ha vinto il giocatore 2";
	}
	if(punteggio3>punteggio1 && punteggio3>punteggio2){
		cout<<"ha vinto il giocatore 3";
	}
	return 0;
}

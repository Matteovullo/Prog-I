/*Data una sequenza S di valori, una salita è una qualunque sottosequenza di elementi di S consecutivi e 
non-decrescenti. Scrivere un metodo che prenda come parametro formale un array S di long e restituisca 
l’indice del primo elemento della salita più lunga in S.*/

#include <iostream>
using namespace std;
#define N 10;

short fun(long *S, int n){
    int c=1;
    int index=0;
    int lunghezza_corrente=1;
    int lunghezza_max=1;
    for(int i=0; i<n; i++){
        for(int j=i; j<n-1; j++){
            if(S[j+1] > S[j]){
                lunghezza_corrente++;
                c++;
            }else{
                c=1;
                lunghezza_corrente=1;
                break;
            }
            if(lunghezza_corrente > lunghezza_max){
                lunghezza_max=lunghezza_corrente;
                index=i;
            }
        }
        c=1;
        lunghezza_corrente=1;
    }
    return index;
}

/*int main(){
    int c=0;
    long *s=new long[10];
    for(int i=0; i<10; i++){
        s[i]=c;
        c++;
        cout << s[i] << " ";
    }
    cout << endl;
    s[0]=5;
    s[1]=6;
    s[2]=7;
    cout << fun(s, 10) << endl;
}*/

/*#include<stdio.h>

int es4(long S[], int n) {
	int inizio_salita_massima = 0;
	int inizio_salita_corrente = 0;
	int lunghezza_salita_massima = 0;
	int i;
	for (i=1; i<n; i++) {
		if(S[i]<S[i-1]) {
			//la salita si interrompe
			//calcoliamo la lunghezza della salita corrente
			int current_length=i-inizio_salita_corrente;
			//se tale lunghezza è maggiore della lunghezza massima
			if(current_length>lunghezza_salita_massima) {
				//aggiorniamo indice e lunghezza
				inizio_salita_massima = inizio_salita_corrente;
				lunghezza_salita_massima = current_length;
			}
			//la salita si è interrotta, reinizializziamo l'indice
			inizio_salita_corrente=i;
		}
	}

	//dobbiamo controllare se la salita corrente è più lunga della massima trovata finora
	if (i-inizio_salita_corrente>lunghezza_salita_massima)
		return inizio_salita_corrente;
	else return inizio_salita_massima;
}*/

int main() {
	long array[] = {0,1,2,3,0,5,7,2,3,6,6,8,0,1,9,10,11,12,10,13};

	printf("%d\n",fun(array,20));
}
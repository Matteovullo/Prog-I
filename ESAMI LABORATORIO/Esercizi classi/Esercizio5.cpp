/*Scrivere un metodo che prenda come parametri formali una matrice A di stringhe ed uno short w, e restituisca in output un bool che
indichi se esiste una riga di A in cui siano presenti almeno due stringhe in cui i primi w caratteri dell’una siano uguali agli 
ultimi w caratteri dell’altra (nello stesso ordine).*/

#include <iostream>
using namespace std;
#define N 2
#include<stdio.h>
#include<string.h>

#define n 3
#define m 4

bool fun(string A[n][m], short w){
    bool found=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int h=j; h<m-1; h++){
                if(A[i][h].substr(0, w) == A[i][h+1].substr(A[i][h+1].length()-w, w)
                || A[i][h].substr(A[i][h].length()-w, w) == A[i][h+1].substr(0, w)){
                    found=true;
					return found;
                }
            }
        }
    }
    return found;
}

/*int main(){
    string **s=new string*[N];
    for(int i=0; i<N; i++){
        s[i]=new string[N];
        for(int j=0; j<N; j++){
            s[i][j]="abaaaaaaadfff";
        }
    }
    cout << fun(s, 2, 2, 2) << endl;
}*/

bool es5(char A[n][m][255], short w) {
	bool found = false;
	//mettiamo !found nella condizione per 
	//interrompere la ricerca quando abbiamo trovato
	//un riga che soddisfi la condizione
	for (int i=0; i<n && !found; i++) { //scorriamo le righe della matrice
		//ora controlliamo se in questa riga ci sono due stringhe che rispettano la condizione
		//date due stringhe X e Y, dobbiamo controllare che la condizione sia verificata per la
		//coppia <X,Y> o per la coppia <Y,X>
		for (int h=0; h<m; h++) {
			for (int k=0; k<m; k++) { //non parto da k=h+1 perché voglio confrontare sia le coppie <X,Y> che <Y,X>
				if(h!=k) { //mettiamo questo controllo per evitare di controllare le coppie <X,X>
					int l = 0; //scorre i primi w caratteri della stringa A[i][h]
					int e = strlen(A[i][k])-w; //scorre gli ultimi caratteri della stringa A[i][k]
					bool good_pair = true; //indica che la coppia rispetta la condizione
					while(l<w && e<strlen(A[i][k]) && good_pair) {
						//se una coppia di caratteri è diversa
						//good_pair diventa false
						good_pair = A[i][h][l++]==A[i][k][e++];
					}
					//se la coppia verifica la condizione, allora abbiamo finito
					//e restituiamo true
					if(good_pair) return true;
				}				
			}
		}
	}
	
	//Se siamo arrivati fin qui non abbiamo trovato nulla
	return false;
}	


int main() {

	string S[n][m]= {{"ttabr","atraatat","bbaap","ataratar"},
						 {"atta","trr","spqr","atatar"},
                         {"tratr","rrta","aprt","rt"}};


	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%s ",S[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	if(fun(S,2)){
		printf("True!\n");
	} else {
		printf("False!\n");
	}
}


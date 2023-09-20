/*Scrivere un metodo che prenda in input una matrice A di stringhe ed una stringa Str, e restituisca un boolean che indichi se Str 
è sottostringa di tutte le stringhe presenti in una qualche colonna di A.*/

#include <iostream>
using namespace std;
#define N 2
#include<stdio.h>
#include<string.h>

#define n 3
#define m 4

bool fun(string S[n][m],string Str){
    int count=0;
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(S[i][j].find(Str) != string::npos)
                count++;
        }
        if(count == n)
            return true;
        count=0;
    }
    return false;
}

/*int main(){
    string **s=new string*[N];
    for(int i=0; i<N; i++){
        s[i]=new string[N];
        for(int j=0; j<N; j++){
            s[i][j]="ciao";
        }
    }
    cout << fun(s, 2, 2, "p") << endl;
}*/

/*#include<stdio.h>
#include<string.h>

#define n 3
#define m 4

bool es7(char A[n][m][255], const char Str[]) {
	bool found = false;
	int lunghezza_str = strlen(Str);
	for(int j=0; j<m && !found; j++) { //scorro le colonne della martice
		bool column_is_good = true; //indica se la colonna corrente rispetta la condizione
		//assumiamo che sia "buona" fino a prova contraria
		//mettiamo column_is_good in and per uscire quando troviamo una stringa che non soddisfa la condizion
		//mettiamo column_is_good in and per uscire quando troviamo una stringa che non soddisfa la condizionee
		for(int i=0; i<n && column_is_good; i++) { //scorro gli elementi della riga corrente
			//adesso devo controllare se Str è sottostringa di A[i][j]
			int lunghezza_a = strlen(A[i][j]);
			int h = 0, k=0;
			while(h<lunghezza_a && k<lunghezza_str) {
				//se i caratteri sono uguali incrementiamo k
				if(A[i][j][h]==Str[k]) k++;
				//altrimenti ripartiamo da zero:
				//se c'è un match con il primo carattere
				//k=1, altrimenti azzeriamo con k=0 
				else if(A[i][j][h]==Str[0]) k=1; else k=0;

				//incrementiamo sempre h
				h++;
			}

			column_is_good = k==lunghezza_str; //se abbiamo trovato la sottostringa, la colonna è "buona"
		}
		found = column_is_good; //se la colonna corrente è "buona" abbiamo finito
	}

	return found;
}*/

int main() {

	string S[n][m] = {{"ttabr","atraatt","bbaap","ataratat"},
			     {"att","tr","spqr","atatar"},
                             {"ttr","rrtr","aprt","rtatr"}};


	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%s ",S[i][j]);
		}
		printf("\n");
	}

	printf("\n");

        if(fun(S,"tr")) {
		printf("Trovato!\n");
	}

}

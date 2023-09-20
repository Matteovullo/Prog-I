/*Scrivere un metodo che prenda in input una matrice A ed un array B entrambe di float, e restituisca un boolean che indichi 
se esiste in A una coppia di elementi verticali contigui la cui somma è pari alla somma di due elementi qualsiasi in B.
N.B. : Non è possibile utilizzare array ausiliari.*/

#include <iostream>
using namespace std;

#define n 3
#define m 4

bool fun(float A[n][m], float B[4]){
    float somma=0.0;
    bool found=false;
    for(int j=0; j<m; j++){
        for(int i=0; i<n-1; i++){
            somma+=A[i][j]+A[i+1][j];
            for(int l=0; l<4; l++){
                for(int g=0; g<4; g++){
                    if(B[l]+B[g] == somma && l!=g){
                        found=true;
                        return found;
                    } 
                }
            }
            somma=0.0;
        }
    }
    return found;
}

/*int main(){
    float **a=new float*[2];
    for(int i=0; i<2; i++){
        a[i]=new float[2];
        for(int j=0; j<2; j++){
            a[i][j]=2.5;
        }
    }

    float *b=new float[2];
    for(int i=0; i<2; i++){
        b[i]=0.5;
    }
    cout << fun(a, b, 2, 2, 2);
}*/

/*#include<stdio.h>
#include<string.h>

#define n 3
#define m 4

bool es6(float A[n][m], float B[], int lenb) {
	bool found = false;
	for (int j=0; j<m && !found; j++) { //scorriamo le colonne
		for (int i=1; i<n && !found; i++) { //scorriamo gli elementi della colonna a partire dal secondo
			float sum_a = A[i][j]+A[i-1][j]; //sommiamo i due elementi contigui
			for (int k = 0; k<lenb && !found; k++) { //scorriamo tutte le coppie possibili 
				for (int h = k+1; h<lenb && !found; h++) { //in un doppio ciclo for
					float sum_b = B[k]+B[h]; //calcoliamo la somma dei numeri di B
					if (sum_a==sum_b) //se sono uguali, abbiamo finito
						found=true;
				}
			}
		}
	}

	return found;
}*/


int main() {

	float A[n][m] = {{1,1,5,7},{4,7,8,2},{5,5,2,0}};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

	float B[4] = {18,16,6,2};

	if (fun(A,B)) {
		cout << "Trovato" << endl;
	} 
}
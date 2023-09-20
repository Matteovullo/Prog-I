/*Data una matrice quadrata, stampare i valori contenuti in tutte le diagonali parallele alla diagonale secondaria.*/

#include <iostream>
using namespace std;

template<typename T>
void stampa(T **m, int n){
    int k=0;
        for(int i=0; i<n-k; i++){
            for(int j=0; j<n-k-1; j++){
                cout << m[i][j] << " ";
            }
            k++;
        }
    cout << endl;

    int l=0;
        for(int i=n-1; i>0; i--){
            for(int j=n-1; j>l; j--){
                cout << m[i][j] << " ";
            }
            l++;
        }

}

/*int main(){
    int **mat=new int*[3];
    int c=0;
    for(int i=0; i<3; i++){
        mat[i]=new int[3];
        for(int j=0; j<3; j++){
            mat[i][j]=c;
            c++;
        }
    }

    stampa<int>(mat, 3);
}*/

#include<iostream>
#include<math.h> //includiamo math.h per poter utilizzare la funzione ceil

using namespace std;

void es10(int **A, int n) {
	/*Utilizziamo la seguente strategia: data la diagonale secondaria,
	tutte le diagonali parallele si possono ottenere spostandosi in avanti
	o indietro di un certo numero di righe. Possiamo così ottenere due indici h e k
	Le coppie di indici valide sono solo quella in cui gli indici sono maggiori o uguali
	a zero e strettamente minori di m*/
	
	//definisco una "distanza" d dalla diagonale principale. 
	//Questo numero può essere negativo (se ci spostiamo indietro)
	//o positivo (se ci spostiamo in avanti)
	//in una matrice n x n ho 2*n -1 diagonali, quindi procedo dalla
	//-ceil((2*n-1)/2) a ceil((2*n-1)/2) inclusi
	for(int d=-ceil((double)(2*n-1)/2); d<=ceil((double)(2*n-1)/2); d++) {
		for (int i=0; i<n; i++) { //scorro tutte le righe
			//dato che dobbiamo spostarci di "d" posizioni indietro o in avanti
			//definisco un nuovo indice h = i+d.
			int h=i+d;
			int k=n-i-1; //l'indice k lo definisco usando la regola per trovare l'elemento 
			//della diagonale secondaria corrispondente alla riga i-esima
			
			//non tutte le coppie di indici che ottengo sono "buone"
			//Verifichiamo che effettivamente gli indici siano validi
			if (h>=0 && k>=0 && h<n && k<n) {
				cout << A[h][k] << " "; //in tal caso stampo l'elemento corrente
			}
		}
		cout << endl;//fine riga quando termino di stampare gli elementi della diagonale
	}
}

int main() {
	int **A = new int*[3];
	for (int i=0; i<3; i++)
		A[i] = new int[3];
	A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
	A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
	A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;
			
	stampa<int>(A,3);
}
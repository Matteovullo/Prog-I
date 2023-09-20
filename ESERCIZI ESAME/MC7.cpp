/*
7.Scrivere un metodo che prenda in input un
parametro formale matrice A di puntatori ad interi di
dimensione nxm, due double d1 e d2 ed uno short s, e
restituisca il numero di colonne di A nelle quali
esistano almeno s coppie di elementi contigui (ES:
A[1][1] e A[2][1]) tali che il rapporto tra il primo ed il
secondo elemento sia compreso tra d1 e d2. NB: Si
assuma a priori che s<=n-1 e che d1 < d2. Si presti
attenzione ai numeri "mancanti"nella matrice A.
*/

#include <iostream>

using namespace std;
#define n 2
#define m 2

int fun(int* a[n][m],short s, double d1, double d2) {
	int count_colonne;
	int count_contigui;
	double div;

	for(int j=0; j<m; j++) {
		count_contigui=0;
		for(int i=0; i<n-1; i++) {
			if(a[i][j] && a[i][j] && a[i][j] != 0){
			div=(*a[i][j])/(double)(*a[i+1][j]);
				if(div>=d1 && div<=d2) {
				count_contigui++;
				}
			}
		}
		if(count_contigui>=s) {
			count_colonne++;
		}
	}
	return count_colonne;
}

int main() {
	/*int* **a=new int **[n];

	for(int i=0; i<n; i++) {
		*a[i]=new int [n];
	}

	int x=0;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			*a[i][j]=x;
			x++;
		}
	}*/
	
	int* matrice[n][n];
	matrice[0][0] = new int(1);
	matrice[0][1] = new int(2);
	matrice[1][0] = new int(3);
	matrice[1][1] = new int(4);

	cout<<fun(matrice,1,0.4,10.0);

}

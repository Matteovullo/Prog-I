#include<iostream>
#define n 3

using namespace std;

bool es1(short mat[n][n]) {
	//assumiamo che la condizione da soddisfare sia vera
	//fino a prova contrari
	bool diag = true;
	//mettiamo && diag nella condizione
	//per fermarci se la condizione non è più verificata
	for(int i=0; i<n  && diag; i++) { //scorre le righe
		//prendo l'elemento corrente della diagonale principale
		short el1 = mat[i][i];
		//prendo l'elemento corrente della diagonale secondaria
		//devo mettere "n-1" perché gli indici partono da 0
		short el2 = mat[i][n-1-i];

		if(el1!=el2){
			//si tratta della "prova contraria"
			diag = false;
		}
	}
	return diag;
}

int main() {
	//TEST ES1
	short mat1[n][n] = {{1,2,3},
			    {4,5,6},
			    {7,8,9}};

	short mat2[n][n] = {{1,2,1},
			    {4,5,6},
			    {9,8,9}};

    short mat3[n][n] = {{-1,2,1},
			    {4,5,6},
			    {9,8,9}};

	if(es1(mat1)) {
		cout << "Errore!" << endl;
	} else {
		cout << "Corretto." << endl;
	}

	if(!es1(mat2)) {
		cout << "Errore!" << endl;
	} else {
		cout << "Corretto." << endl;
	}

    if(!es1(mat3)) {
		cout << "Errore!" << endl;
	} else {
		cout << "Corretto." << endl;
	}
}
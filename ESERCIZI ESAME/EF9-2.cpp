#include<stdio.h>
#include<string.h>

#define n 3
#define m 4

bool es9(char* A[n][m]) {
	bool found = false;
	for(int j=0; j<m && !found; j++) { //scorro le colonne della martice
		int good_pairs = 0; //tiene conto del numero delle coppie di stringhe che rispettano la condizione
		for (int h=0; h<n; h++) { //scorriamo tutte le coppie
			for (int k=h+1; j<n; k++) {
				char *a = A[h][j]; //puntatore alla prima stringa
				char *b = A[k][j]; //puntatore alla seconda stringa
				if (a!=NULL && b!=NULL) {
					int len_a = strlen(*a); //lunghezza della prima stringa
					int len_b = strlen(*b); //lunghezza della seconda stringa
					
					int min_len = (len_a<len_b)? len_a:len_b;

					int correspondences = 0; //numero di corrispondenze
					for (int q = 0; q<min_len; q++) {
						if (*(a+q)==*(b+q)) correspondences++;
					}
					if (correspondences >= min_len/2) good_pairs++;
				}
			}
		}
		found = good_pairs>=2;
	}	
	
	return found;
}

int main() {

	char *S[n][m] = {{"ttabr","atraatt","bbaap","ataratat"},
			     {"att","tr","spqr","atatar"},
                             {"ttr","rrtr","aprt","rtatr"}};


	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%s ",S[i][j]);
		}
		printf("\n");
	}

	printf("\n");

        if(es9(S)) {
		printf("Trovato!\n");
	}

}
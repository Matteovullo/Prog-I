/*Due stringhe si dicono simili se esse coincidono in almeno p posizioni, dove p è la metà (troncata) della lunghezza della stringa più corta. 
(Es.: Le stringhe “abcdefabcdef ” e “zbcaafacz” sono simili perché coincidono agli indici 1,2,5,6 ed è p=4). Scrivere un metodo che prenda 
in input una matrice A di puntatori a stringhe, e restituisca un boolean che indichi se esiste una colonna di A in cui sono presenti almeno 
due stringhe simili.
N.B.: Attenzione alle eventuali stringhe mancanti in A (con puntatore a null).*/

#include <iostream>
using namespace std;
#define n 3
#define m 4
#define N 2

bool fun(string *A[n][m]){
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(A[i][j]){
                for(int h=i+1; h<m; h++){
                    if(A[h][j]){
                        int p=0;
                        int c=0;
                        if((*A[i][j]).length() < (*A[i][h]).length()){
                            p=(*A[i][j]).length()/2;
                            for(int l=0; l<(*A[i][j]).length(); l++){
                                //for(int p=0; p<(*A[h][j]).length(); p++){
                                    if((*A[i][j])[l] == (*A[i][h])[l]){
                                        c++;
                                    }
                                //}
                            }
                        }else{
                            p=(*A[h][j]).length()/2;
                            for(int l=0; l<(*A[h][j]).length(); l++){
                                //or(int p=0; p<(*A[i][j]).length(); p++){
                                    if((*A[i][j])[l] == (*A[h][j])[l]){
                                        c++;
                                    }
                                //}
                            }
                        }
                        if(c==p){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

/*int main(){
    string ***s=new string**[N];
    for(int i=0; i<N; i++){
        s[i]=new string*[N];
        for(int j=0; j<N; j++){
            s[i][j]=new string("abba");
        }
    }
    cout << fun(s, 2, 2) << endl;
}*/

#include<stdio.h>
#include<string.h>

#define n 3
#define m 4

/*bool es9(char* A[n][m]) {
	bool found = false;
	for(int j=0; j<m && !found; j++) { //scorro le colonne della martice
		int good_pairs = 0; //tiene conto del numero delle coppie dis tringhe che rispettano la condizione
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
}*/

int main() {

	string *S[n][m] = {{new string("ttabr"),new string("atraatt"),new string("bbaap"),new string("ataratat")},
			     {new string("att"),new string("tr"),new string("spqr"),new string("atatar")},
                             {new string("ttr"),new string("rrtr"),new string("aprt"),new string("rtatr")}};


	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%s ",S[i][j]);
		}
		printf("\n");
	}

	printf("\n");
        if(fun(S)) {
		printf("Trovato!\n");
	}

}
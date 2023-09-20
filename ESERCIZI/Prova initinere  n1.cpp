#include <iostream>
using namespace std;
int main(){
	/*Scrivere un metodo che prenda in input un parametro formale matrice A di interi di dimensioni n × n ed
un double w, e restituisca un valore booleano true se esiste almeno una colonna della matrice A per cui il
rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della diagonale principale
di A sia maggiore di w.*/

	int n,m;
	int a[n][n];
	double w;
	bool valore;
	int somma_colonna=0;
	int somma_diagonale=0;
	
	cout<<"inserire n: ";cin>>n;
	cout<<"inserie w:";cin>>w;
	
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"inserisci un valore: ";cin>>a[i][j];
		}
	}
	
	for(int j=0; j<n; j++){
		for(int i=0;i<n; i++){
			somma_colonna+=a[i][j];
			if(i==n-1){
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(i==j){
							somma_diagonale+=a[i][j];
							if(i==n-1){
								if (somma_colonna/somma_diagonale>w) {
									valore=true;
									cout<<valore;
									break;
								}else{
									continue;
								}
							}
						}
					}
				}
			}
		}
	}
}
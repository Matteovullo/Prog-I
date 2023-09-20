/*
31.Scrivere un metodo che prenda in input una 
matrice M di puntatori a double di dimensione n × m e 
due interi a e b e restituisca un array unidimensionale 
di booleani di lunghezza 2m tale che l’elemento 
dell’array di posizione 2i contiene True se e solo se la 
media dei soli elementi della colonna i-esima di M 
compresi tra a e b(estremi inclusi) è maggiore di 
(a+b)/2. Gli elementi dell’array di indice dispari devono 
essere inizializzati a False. NB: Si presti attenzione ai 
numeri mancanti! 
*/

#include <iostream>
#define n 2
#define m 2
using namespace std;


bool* fun(double* f[n][m], int a, int b){
	int count;
	double somma;
	double rapporto;
	
	bool* arr=new bool [2*m];
	for(int l=0; l<2*m; l++){
		for(int j=0; j<m; j++){
			count=0;
			somma=0.0;
			for(int i=0; i<n; i++){
				if(f[i][j]){
					if(*f[i][j]>=a && *f[i][j]<=b){
						somma+=*f[i][j];
						count++;
					}
				}
				rapporto=somma/(double)count;
				if(rapporto > (a+b)/(double)2){
					arr[2*l]=true;
				}else{
					arr[2*l]=false;
				}
			}
		}
	}
	
	for(int v=0; v<2*m; v++){
		if(v%2 != 0){
		arr[v]=false;
		}
	}
	return arr;
}

void stampa(bool *array_stampa)
  {
    for(int i=0; i<2*m; i++)
      {
        cout<<fixed<<array_stampa[i]<<endl;
      }
  }

int main(){
	double* matrice[n][n];
	matrice[0][0] = new double(1.0);
	matrice[0][1] = new double(1.0);
	matrice[1][0] = new double(1.0);
	matrice[1][1] = new double(1.0);
	
	bool *array_1=new bool [n];
    array_1=fun(matrice,0,1);
	stampa(array_1);
}

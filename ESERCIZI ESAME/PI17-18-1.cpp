/*Scrivere un metodo che prenda come parametro formale una matrice quadrata M di n×n interi
positivi e restituisca un array A di n float in cui:
 minimo dei valori nella colonna i-esima di M, se i è pari;
 A[i] = media dei valori divisibili per 3 presenti nella riga i-esima di M, 
 se i è dispari e non divisibile per 3,
 A[i−2]+A[i−1], altrimenti.*/

#include <iostream>
using namespace std;
#define n 3

float* fun(unsigned int **m){
    float *a=new float [n];
    for(int j=0; j<n; j+2){
        int min=m[0][j];
        for(int i=0; i<n; i++){
            if(j%2 == 0){
                if(m[i][j] < min){
                    min= m[i][j];
                }
            }
        }
        a[j]=min;
    }
    
    for(int i=0; i<n; i++){
        int count=0;
        int somma=0;
        for(int j=0; j<n; j++){
            if(i%2 != 0 && i%3 != 0){
                if(m[i][j]%3 == 0){
                    somma+=m[i][j];
                    count++;
                }
            }
        }
        if(somma==0 && count==0){
            a[i]=a[i-2]+a[i-1];
        }else{
            a[i]=somma/(float)count;
        }
    }
    
    return a;
}

void stampa(float *array_stampa)
  {
    for(int i=0; i<n; i++)
      {
        cout<<array_stampa[i]<<endl;
      }
  }

int main(){
	unsigned int **a=new unsigned int *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new unsigned int [n];
        for(int j=0; j<n; j++){
            a[i][j]=1;
        }
	}
	
	
	float *array_1=new float [n];
    array_1=fun(a);
    stampa(array_1);

}
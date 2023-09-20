/*27.Scrivere un metodo che prenda come parametro 
formale una matrice A n×m di puntatori ad intero, e 
restituisca in output un bool che indichi se esistono 
due elementi in A che puntano allo stesso valore intero 
(anche in locazioni differenti).*/

#include <iostream>
using namespace std;
#define n 2
#define m 2

bool fun(int* a[n][m]){
	int count;
	int aux;
	bool valore;
	int k;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			aux=*a[i][j];
			while(k<m){
				k++;
				if(aux==*a[i][k]){
					count++;
					if(k==n-1){
						k=0;
						if(count>=2){
							valore=true;
							break;
						}else{
							valore=false;
							count=0;
							continue;
						}
					}
				}
			}
			if(valore){
				break;
			}
		}
		if(valore){
			break;
		}
	}
	return valore;
}


int main(){
	/*int* **b=new int **[n];
	
	for(int i=0; i<n; i++){
		b[i]=new int [n];
	}
	
	int x=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			*b[i][j]=x;
			x++;
		}
	}*/
	
	int* matrice[n][m];
	
	matrice[0][0] = new int(1);
	matrice[0][1] = new int(1);
	matrice[1][0] = new int(1);
	matrice[1][1] = new int(1);
	
	cout<<fun(matrice);
}
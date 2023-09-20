/*Scrivere un metodo che prenda come parametri 
formali una matrice quadrata A n×n di puntatori ad int 
e restituisca in output un bool che indichi se la somma 
degli elementi puntati dalla diagonale sottostante la 
diagonale secondaria è divisibile per n. */

#include <iostream>
#define n 3
using namespace std;

//1 2 3
//3 4 1
//2 4 1


bool func(int* **a){
	int somma=0;
	int count=0;
    int k=0;
    int j;
    bool valore;
	for(int i=1; i<n-1; i++){
        j=n-1;
        while(k<i){
            somma+=*a[i][j];
			count++;
            k++;
            j--;
        }
		k=0;
    }
	if(somma % count==0){
		valore=true;
	}else{
		valore=false;
	}
	return valore;
}

int main(){
	int* **a=new int **[n];
	
	for(int i=0; i<n; i++){
		a[i]=new int *[n];
		for(int j=0; j<n; j++){
			a[i][j]= new int[n];
            cin>>*a[i][j];
		}
	}
	
	cout<<func(a);

}
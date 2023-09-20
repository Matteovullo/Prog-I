/*27.Scrivere un metodo che prenda come parametro 
formale una matrice A n×m di puntatori ad intero, e 
restituisca in output un bool che indichi se esistono 
due elementi in A che puntano allo stesso valore intero 
(anche in locazioni differenti).*/

#include <iostream>
#define n 3
#define m 2
using namespace std;

bool func(int***A){
	int arr[n*m];
	
	cout<<"Matrice di indirizzi:"<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int k=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			arr[k]=*A[i][j];
			k++;
		}
	}

	for(int i=0; i<k; i++){
		for(int j=i+1; j<k; j++){
			if(arr[i]==arr[j]) return true;
		} 
	}
	return false;
}

int main(){
	
	int***A = new int**[n];
	for(int i=0; i<n; i++){
		A[i] = new int*[m];
		for(int j=0; j<m; j++){
			A[i][j] = new int(1);
//			A[i][j] = nullptr;
		}
	}
	
	bool esito = func (A);
	if(esito)
	cout<<"\nVero";
	if(!esito)
	cout<<"\nFalso";
	
}
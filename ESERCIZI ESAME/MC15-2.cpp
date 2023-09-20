/* 15.Scrivere un metodo che prenda in input tre matrici 
A, B e C di boolean con le stesse dimensioni, e 
restituisca un boolean che indichi se una diagonale in 
A, soprastante la diagonale principale, è presente 
anche in B e C (nella stessa posizione e con la stessa 
sequenza di valori!).*/

#include <iostream>
using namespace std;
#define N 3

bool func(bool**A, bool**B, bool**C){
	
	cout<<"Matrice A : "<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<" "<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Matrice B : "<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<" "<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Matrice C : "<<endl;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout<<" "<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int k=2; k<N; ){
		for(int i=0; i<N-k; i++){
			for(int j=1; j<k-1; j++){
				if(j==i+1){
					if(!(A[i][j]==B[i][j] && A[i][j]==C[i][j])){
						return false;
					}
				}
			}
			k++;
		}
	}
		return true;
	
}

main(){
	
	bool**A = new bool *[N];
	for(int i=0; i<N; i++){
		A[i] = new bool [N];
		for(int j=0; j<N; j++){
			cout<<"Inserisci dei bool nella matrice A: "<<endl;
			cin>>A[i][j];
		}
	}
	cout<<endl;
	bool**B = new bool *[N];
	for(int i=0; i<N; i++){
		B[i] = new bool [N];
		for(int j=0; j<N; j++){
			cout<<"Inserisci dei bool nella matrice B: "<<endl;
			cin>>B[i][j];
		}
	}
	cout<<endl;
	bool**C = new bool *[N];
	for(int i=0; i<N; i++){
		C[i] = new bool [N];
		for(int j=0; j<N; j++){
			cout<<"Inserisci dei bool nella matrice C: "<<endl;
			cin>>C[i][j];
		}
	}
	
	bool esito = func (A, B, C);
	
	if (esito == true){
		cout<<"\nI valori coincidono"<<endl;
	}else{
		cout<<"\nI valori non coincidono"<<endl;
	}
}
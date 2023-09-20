/*15.Scrivere un metodo che prenda in input tre matrici 
A, B e C di boolean con le stesse dimensioni, e 
restituisca un boolean che indichi se una diagonale in 
A, soprastante la diagonale principale, è presente 
anche in B e C (nella stessa posizione e con la stessa 
sequenza di valori!). */

#include <iostream>
#define n 3
using namespace std;

bool func(bool **e, bool **f, bool **g){
	bool valore;
	int count;
	
	for(int i=0; i<n-1; i++){
		if(e[i][i+1]==f[i][i+1] && e[i][i+1]==g[i][i+1]){
			count++;	    
		}
	}
	if(count==n-1){
		valore=true;
	}else{
		valore=false;
	}
	return valore;
}

int main(){
	bool **a=new bool *[n];
	bool **b=new bool *[n];
	bool **c=new bool *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new bool [n];
	}
	
	for(int i=0; i<n; i++){
		b[i]=new bool [n];
	}
	
	for(int i=0; i<n; i++){
		c[i]=new bool [n];
	}
	
	/*for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"inserire un valore: ";
			cin>>a[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"inserire un valore: ";
			cin>>b[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"inserire un valore: ";
			cin>>c[i][j];
		}
	}*/
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			a[i][j]=0;
			b[i][j]=0;
			c[i][j]=0;
		}
	}
	
	cout<<func(a,b,c);
}
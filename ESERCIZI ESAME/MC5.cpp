/*
Scrivere un metodo che prenda come parametri 
formali una matrice A n×m di long ed un long x, e 
restituisca in output l’indice della colonna di A con il 
maggior numero di occorrenze di x.
*/

#include <iostream>

using namespace std;

int fun( int n, int m, long **a, long x){
	int count_x;
	
	int *c=new int [m];
	
	for (int j=0; j<m; j++){
		count_x=0;
		for (int i=0; i<n; i++){
			if(x==a[i][j]){
				count_x++;
			}
	    }
	    c[j]=count_x;
	}
	
	int max=c[0];
	int index;
	
	for(int i=0; i<m; i++){
		if(c[i]>max){
			max=c[i];
			index=i;
		}else{
			max=max;
			index=index;
		}
	}
	//1 2 3
	//4 5 6
	//7 8 9
	//cout<<"colonna con il numero maggiore di occorenze e': "<<index<<endl;
	return index;
	
}

int main(){
	int n=3;
	int m=3;
	long **a=new long *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new long [n];
	}
	
	int x=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			a[i][j]=x;
			x++;
		}
	}
	
	cout<<fun(3,3,a,1);
}
/*Data una matrice quadrata, stampare i valori contenuti in tutte le diagonali 
parallele alla diagonale secondaria.*/

#include <iostream>
#define n 3
using namespace std;

void fun(int **a){
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<a[i][n-i]<<endl;
		}
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<a[i][n-2-i]<<endl;
		}
	}
}

int main(){
    int **b=new int *[n];
    for(int i=0; i<n; i++){
        b[i]=new int [n];
        for(int j=0; j<n; j++){
            b[i][j]=1;
        }
    }

    fun(b);

}
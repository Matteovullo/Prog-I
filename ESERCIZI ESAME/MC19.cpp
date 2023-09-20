/*Scrivere un metodo che prenda in input una
matrice quadrata M di short e restituisca il valore
booleano true se M è una matrice triangolare inferiore
o superiore.*/

/*

a 0 0 // A[i][j] tali che j>i
b c 0
d e f

a b c // A[i][j] tali che j<i
0 d e
0 0 f

*/
#include<iostream>
#define n 3
using namespace std;

bool fun(short **M) {
    bool triangolare_inferiore=true;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(M[i][j]!=0)
                triangolare_inferiore=false;
        }
    }

    if(triangolare_inferiore)
        return true;

    bool triangolare_superiore=true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(M[i][j]!=0)
                triangolare_superiore=false;
        }
    }

    return triangolare_superiore;
}

int main(){
	short **a=new short *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new short [n];
	}
		
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			a[i][j]=0;
		}
	}
	
	cout<<fun(a);
}

#include <iostream>

using namespace std;

/*Si definisca staticamente una matrice 3×3 e la si inizializzi con la matrice identità.*/

int a[2][2];

int main(){
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			if(i==j){
				a[i][j]=1;
			}
		}
	}
	
		for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
				cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;
			}
		}
}



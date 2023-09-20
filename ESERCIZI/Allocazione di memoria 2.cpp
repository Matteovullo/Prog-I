#include <iostream>

using namespace std;

/*Si definisca dinamicamente una matrice 3×3 e la si inizializzi con la matrice identità.*/
int main(){
	int **a= new int*[3];
	for(int i=0; i<3; i++){
		a[i]=new int[3];
		for(int j=0; j<3; j++){
		if(i==j){
			a[i][j]=1;
		}else{
			a[i][j]=0;
		}
		}
	}

	for (int i=0; i<3; i++) {
	for (int j=0; j<3; j++) {
        cout << "s[" << i << "][" << j << "]="<< a[i][j] << endl;
         }
    }
}

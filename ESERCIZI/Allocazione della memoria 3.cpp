#include <iostream>
#include <cmath>
using namespace std;

/*Si definisca staticamente un vettore 2×2×3 e lo si inizializzi in modo che la posizione di indici [i][j][k] contenga il valore ij+k.*/

int v[2][2][3];

int main(){
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<3; k++){
				v[i][j][k]=pow(i,j)+k;
			}
		}
	}
	
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<3; k++){
				cout << "v["<<i<<"]["<<j<<"]["<<k<<"]="<< v[i][j][k] << endl;
			}
		}
	}
}
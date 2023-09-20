/*

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ***(int **a, int n, int m, int a,int b, short k){
	srand(time(0));
	int ***b[n]=new int **[n]
	for(int i=0; i<n; i++) b[i]=new int*[n];
	bool valore;
	
	for(int j=0; j<n; j++){
		int count=1;
		for(int i=0; i<n; i++){
			for(int k=i; k<n; k++){
				if(a[k][j]!= nullptr && a[k+1][j]!=nullptr && a[k][j]<=a[k+1][j]) count++;
				else count=1
			}
			if(count==k) valore=true;
		}
		if(valore){
			for(int l=0; l<n; l++){
				b[l][j]=new int (rand%(b-a+1)+a);
			}
		}else{
			for(int d=0; d<n; d++){
				if(a[d][j]){
					b[d][j]=a[d][j];
				}
			}
		}
	}
}

int main(){
	return 0;
}

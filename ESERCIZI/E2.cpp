/*

*/

#include <iostream>
using namespace std;

int (string ***s, int n, int m, short p){
	char c[32]{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Y','Z'};
	
	int count, count1;
	bool valore;
	
	for(int j=0; j<m; j++){
		count=0;
		for(int i=0; i<n; i++){
			valore=true;
			if(a[i][j]){
				for(int y=0; y<(*s[i][j]).length(); y++){
					char c=(*s[i][j])[c];
					for(int u=0; u<32; u++){
						if(c[u] != c){
							valore=false;
						}
					}
				}
			}else valore=false;
		}
		if(count >= p) count2++;
	}
	
	return count2;
}

int main(){
	return 0;
}

/*

*/

#include <iostream>
using namespace std;
#define n 3

string fun(string ***a, bool **b){
	string str="";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j] && b[i][j] == b[j][i]){
				for(int l=0; l<(*a[i][j]).length(); l+=2){
					str+=(*a[i][j])[l];
				}
			}
		}
	}
	return str;
}

int main(){
	string ***c=new string **[n];
	for(int i=0; i<n; i++){
		c[i]=new string *[n];
		for(int j=0; j<n; j++){
			c[i][j]=new string("ciao");
		}
	}
	
	bool **d=new bool *[n];
	for(int i=0; i<n; i++){
		d[i]=new bool[n];
		for(int j=0; j<n; j++){
			d[i][j]=1;
		}
	}
	
	cout<<fun(c,d);
	
}

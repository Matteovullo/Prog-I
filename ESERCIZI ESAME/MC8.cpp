/*
8.Scrivere un metodo che prenda in input una matrice 
quadrata di puntatori a stringhe Q ed una stringa s. Il 
metodo restituisca il valore booleano true se e solo se 
il numero di stringhe che contengono s, presenti nella 
diagonale principale di Q, e maggiore del numero di 
stringhe che contengono s presenti nella diagonale 
secondaria di Q. 
*/

#include <string>
#include<iostream>
#define n 3
using namespace std;

bool fun (string* q[n][n], string s){
	int count1;
	int count2;
	int j;
	bool valore;
	string str1,str2;
	
	for(int i=0, j=n-1; i<n; i++, j--){
	if(q[i][i]!=nullptr){
		str1=*q[i][i];
		if(str1.find(s)!=string::npos){
			count1++;
		}
	}
	if(q[i][j]!=nullptr){
		str2=*q[i][j];
		if(str2.find(s)!=string::npos){
			count2++;
		}
		}
	}
	if(count1>count2){
		valore=true;
	}else{
		valore=false;
	}
	return valore;
}

int main(){
	/*string***a=new string **[n];
	
	for(int i=0; i<n; i++){
		*a[i]=new string [n];
		for(int j=0; j<n; j++){
			*a[i][j]=new string ("ciao");
		}
	}*/
	
	string* matrice[n][n];
	
	matrice[0][0] = new string("ai");
	matrice[0][1] = new string("ai");
	matrice[0][2] = new string("a");
	matrice[1][0] = new string("ai");
	matrice[1][1] = new string("ai");
	matrice[1][2] = new string("ai");
	matrice[2][0] = new string("a");
	matrice[2][1] = new string("ai");
	matrice[2][2] = new string("ai");

	cout<<fun(matrice,"a");
}

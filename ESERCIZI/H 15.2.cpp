#include <iostream>

using namespace std;

int main(){
	/*Scrivere un programma in C++ nel quale si chiede all’utente di
inserire due numeri N ed M entrambi maggiori di 1.
Successivamente:
• operare i soliti controlli ed eventuali arrotondamenti sui
numeri inseriti dallo utente;
• inizializzare la matrice con numeri a piacere in virgola mobile;
• calcolare e stampare il prodotto di uno scalare scelto a piacere
(es: 3.542) con la matrice;
• definire una ulteriore matrice quadrata avente la dimensione
della pi`u grande matrice quadrata che `e possibile ricavare
dalla matrice esistente. ES: per una matrice 8x9 le dimensioni
della nuova matrice saranno 8x8;
• riempire la nuova matrice con i corrispondnti elementi della
prima matrice.*/

int n,m;

cout<<"ins n: ";cin>>n;
cout<<"ins m: ";cin>>m;

float V[n][m]={1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9};

int i=0,j=0;
if(n>1 && m>1){
while(i<n){
	while(j<n){
		V[i][j]*=3.542;
		j++;
	}
	j=0;
	i++;
}}else{
	cout<<"errore";
}

int a,b;
float W[a][b]={};

if(n>m){
	a=m;
	b=m;
}else{
	a=n;
	b=n;
}

int k=0,l=0,o=0,p=0;
while(k>a && o>n){
	while(l>b && p>n){
		V[k][l]=W[o][p];
		k++;
		o++;
		cout<<W[k][l]<<" ";
	}
	cout<<endl;
	o=0;
	k=0;
	p++;
	l++;
}


}
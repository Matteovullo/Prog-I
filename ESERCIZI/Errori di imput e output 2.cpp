#include <iostream>

using namespace std;
int main(){
	/*Si scriva un programma che chiede di inserire in input $10$ numeri e stampa a schermo la somma di questi numeri.
	Se uno dei valori inseriti non è un numero, terminare il programma con un messaggio di errore.*/
	
	int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
	
	cin>>n1;cin>>n2;cin>>n3;cin>>n4;cin>>n5;cin>>n6;cin>>n7;cin>>n8;cin>>n9;cin>>n10;
	
	if(cin.fail()){
		cerr<<"errore!";
	}else{
		cout<<n1+n2+n3+n4+n5+n6+n7+n8+n9+n10;
	}
}
#include <iostream>

using namespace std;
int main(){
	/*Si scriva un programma che chiede di inserire in input dei numeri (l’inserimento termina con il carattere eof) 
	e stampa a schermo la somma di questi numeri. Se si ha un errore di input, ripetere la possibilità di inserire un numero.*/
	
	int x,y,z;
	
	cin>>x;cin>>y;cin>>z;
	
	if(cin.fail()){
		cout<<"ins. nuovamente";
		cin>>x;cin>>y;cin>>z;
		if (!cin.fail()){
			cout<<x+y+z;
		}
	}else{
		cout<<x+y+z;
	}
}
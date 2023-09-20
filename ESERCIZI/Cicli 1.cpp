#include <iostream>

using namespace std;

int main(){
	/*Si scriva un programma che prenda in input 10 numeri dall’utente e una stringa e stampi a schermo:

La somma dei valori, se la stringa inserita è uguale a “sum”;

Il prodotto dei valori, se la stringa inserita è uguale a “prod”;

La somma dei valori pari inseriti, se la stringa inserita è uguale a “sumeven”;

La lista dei numeri in tutti gli altri casi (suggerimento: si usi uno stringstream per stampare la lista dei numeri inseriti).*/

int n[10];
string stringa;
int somma=0,sommapari=0;
float prodotto=1;
for(int i=0; i<10; i++){
	cout<<"inserisci numero"<<endl;
	cin>>n[i];
}

cout<<"ins. stringa";
cin>>stringa;

if(stringa=="sum"){
	for(int i=0; i<10; i++){
	somma+=n[i];
	if(i==9) cout<<somma<<endl;
}
}

if(stringa=="prod"){
	for(int i=0; i<10; i++){
	prodotto*=n[i];
	if(i==9) cout<<prodotto<<endl;

}
}

if(stringa=="sumever"){
	for(int i=0; i<10; i++){
		if(n[i]%2==0) sommapari+=n[i];
			if(i==9) cout<<sommapari<<endl;
		
	}	
}



}
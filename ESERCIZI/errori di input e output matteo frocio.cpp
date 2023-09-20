#include <iostream>
#include<limits>

using namespace std;

int main(){
/*Si scriva un programma che chieda all’utente di inserire due numeri in virgola mobile che rappresentano 
la base e l’altezza di un triangolo e che stampi a schermo la sua area. Il programma deve gestire correttamente gli errori
 e ripetere la lettura da standard input di ciascun numero in input per al massimo 5 volte in caso di errori. 
Se un numero è stato inserito incorrettamente per più di 5 volte, terminare il programma restituendo un messaggio di errore.*/
	float base,altezza;
	int i=0;
	
	cout<<"INSERISCI BASE E ALTEZZA"<<endl;
	
	
	while(i<5){
		cin>>base>>altezza;
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'n');
		}
		i++;
	}
}
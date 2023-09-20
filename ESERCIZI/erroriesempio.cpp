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
	bool valore1=false;
	bool valore2=false;
	cout<<"INSERISCI BASE E ALTEZZA"<<endl;
	
	
	do{
		if( valore1== false){
				cin>>base;
			if(cin.fail()){
				i++;
				if(i==5) break;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}else
				valore1=true;
	}
		if( valore2==false){
		cin>>altezza;
			if(cin.fail()){
				i++;
				if(i==5) break;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}else
				valore2=true;			
	}
	}while((valore1==false)||(valore2==false));
}
#include <iostream>

using namespace std;

int main(){
/*Si scriva un programma che chieda all’utente di inserire due numeri in virgola mobile che rappresentano 
la base e l’altezza di un triangolo e che stampi a schermo la sua area. Il programma deve gestire correttamente gli errori
 e ripetere la lettura da standard input di ciascun numero in input per al massimo 5 volte in caso di errori. 
Se un numero è stato inserito incorrettamente per più di 5 volte, terminare il programma restituendo un messaggio di errore.*/

float base,altezza,area;

cout<<"ins. base:" ; cin>>base;
cout<<"ins. altezza: " ; cin>>altezza;

if(cin.fail()){
	cin>>base;
	cin>>altezza;
	if(cin.fail()){
		cin>>base;
		cin>>altezza;
	     	}if(cin.fail()){
	 		cin>>base;
	   		cin>>altezza;
	     	}
	 	        if(cin.fail()){
		  	    cin>>base;
		    	cin>>altezza;
	        	} 
			         if(cin.fail()){
		         	cin>>base;
		            cin>>altezza;
		            cerr<<"errore!";
	             	}
	}else{
	area=(base*altezza)/2;
	}
	
	
}
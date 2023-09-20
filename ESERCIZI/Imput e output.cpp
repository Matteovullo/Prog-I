#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	//Si scriva un programma che calcoli l’area di un triangolo. Il programma deve:
    //Usare lo standard input per chiedere all’utente i valori di base e altezza del triangolo;
    //Definire una variabile float e assegnarle il valore dell’area;
    //Stampare a schermo il risultato con una precisione di tre cifre decimali dopo la virgola.
    //float base,altezza,area;
    //cout<<"base: "; cin>>base;
    //cout<<"altezza: "; cin>>altezza;
    //area=(base*altezza)/2;
    //cout<<"area:"<<scientific<<setprecision(3)<<fixed<<area<<endl;
    
    //Si scriva un programma che:
    //Chiede all’utente di inserire tramite terminale un valore numerico in virgola mobile; 
    //Dichiara una variabile double e le assegna il valore della diagonale del quadrato di lato pari al valore indicato dall’utente;
    //Stampi a schermo il valore della diagonale in notazione scientifica.
    double valore;
	cout<<"valore in virgola mobile: "; cin>>valore;
	double diagonale;
	diagonale=1.414*valore;
	cout<<scientific<<diagonale<<endl;
	
}
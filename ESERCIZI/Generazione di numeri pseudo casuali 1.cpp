#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*Scrivere un programma in C++ che permetta di simulare una sequenza di N lanci di una coppia di dadi, dove N è un numero scelto dall’utente.
 Il programma dovrà stampare le sequenze dei due numeri (output primo dado e output secondo dado) in due colonne separate. ES:
1 6
3 4
1 2
6 3*/

int main(){
	int n;
	int a=1;
	int b=6;
	
	cout<<"inserire numero di lanci: ";cin>>n;
	
	srand(time(0));
	
	if(cin.fail()) {
        cerr << "Errore, numero non valido!";
        return EXIT_FAILURE;
    }
	
	for(int i=0; i<n; i++){
			int lancio1=rand()%(b-a+1)+a;
			int lancio2=rand()%(b-a+1)+a;
			cout<<lancio1<<" "<<lancio2<<endl;
	}
	
}
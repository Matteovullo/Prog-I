#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	/*Scrivere un programma in C++ che permetta di simulare
una sequenza di N lanci di una coppia di dadi, dove N `e un
numero scelto dall’utente oppure una costante scelta a tempo
di compilazione. Il programma dovr`a stampare le sequenze
dei due numeri (output primo dado e output secondo dado)
in due colonne separate. ES:
1 6
3 4
1 2
6 3*/

int n;

cout<<"ins n: ";cin>>n;
srand (time(0));

for(int i=0; i<=n; i++){
	int r=rand()%(6-1);
	cout<<"r \t";
}


}
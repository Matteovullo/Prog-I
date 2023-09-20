#include <iostream>

using namespace std;

int main(){
	
	//Sulla base degli esempi precedenti, codificare un
	//ciclo while in linguaggio C++ nel quale:
	//• il loop si ferma quando il capitale o montante
	//raggiunge o supera la cifra target definita in una
	//costante T;
	//• tuttavia il periodo di accumulo di interessi sul
	//montante non deve in ogni caso superare il
	//numero di anni definito in una costante N.
	
	const int N = 5 ;
	double capitale =1000.0;
	const double TASSO_INTERESSE = 0.1 ;
	const double t=50000.0;
	int anno=0;
	
	while (capitale<=t && anno<N){
		capitale+=capitale*TASSO_INTERESSE ;
		anno++;
	}
	cout<<capitale;
}
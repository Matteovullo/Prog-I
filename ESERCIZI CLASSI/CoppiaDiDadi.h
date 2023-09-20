/*
Progettare e implementare una classe CoppiaDiDadi composta da due oggetti Dado a sei facce. 
Creare un file main.cpp che implementi una funzione main che tiri più volte 
l’oggetto CoppiaDiDadi contando il numero di doppi sei realizzati.
*/

#include "Dado.cpp"

#include <cstdlib>
#include <ctime>

class CoppiaDiDadi{
	private:
		Dado d1;
		Dado d2;
		short valore1;
		short valore2;
	public:
		CoppiaDiDadi();
		CoppiaDiDadi(time_t seed);
		short getValore1();
		short getValore2();	
		void lancia1();
		void lancia2();
		void lancia2D();
};
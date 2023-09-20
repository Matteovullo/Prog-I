/*
Si costruisca una classe Fibonacci con un metodo statico get che restituisca i numeri della successione di 
Fibonacci.
Ogni volta che si chiama get, l’oggetto deve restituire un numero successivo. 
(Ad esempio se si richiama 5 volte get 
verranno restituiti i primi 5 numeri della successione).
*/

#include <iostream>
using namespace std;

class Fibonacci{
	static int num;
	public:
		Fibonacci();
		static int get(){
			num++;
			return num;
		}
};

int Fibonacci::num = 0;

int main(){
	Fibonacci o;
	o.get();
}
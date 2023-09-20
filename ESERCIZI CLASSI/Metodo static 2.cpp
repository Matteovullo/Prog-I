/*
Si modifichi l’esercizio precedente rendendo get non statico e facendo si che il costruttore di Fibonacci prenda 
in input un intero n. Il metodo get restituirà dunque il numero corrente della successione elevato a n. 
Si crei un programma che costruisca due oggetti di tipo Fibonacci (con n=2 e n=3) e li si utilizzino per ottenere i numeri della successione.
Nota: get deve sempre restituire il numero successivo della successione, anche se chiamato da diverse istanze. Esempio:
*/

#include <iostream>
using namespace std;

class Fibonacci{
	static int num;
	int x;
	public:
		Fibonacci(int x){
			this->x=x;
		};
		int getnum(){
			num=x;
			num*=num;
			return num;
		}
};

int Fibonacci::num=0;

int main(){
	Fibonacci f1(2);
	Fibonacci f2(3);
	cout<<f1.getnum()<<endl;
	cout<<f2.getnum()<<endl;
}
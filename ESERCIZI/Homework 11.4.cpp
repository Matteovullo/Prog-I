#include <iostream>

using namespace std;

int main(){
	//Codificare in linguaggio C++ un algoritmo che produca la somma dei numeri interi dispari da 1 a 99, facendo uso del 
	//costrutto for. Dalla somma vanno esclusi i numeri divisibili per tre.
	for (int num=0; num<100; num++)
	{
		if(num%2 != 0 && num%3 != 0)
		{
		cout<<num<<endl;	
		}	
	}
	
}
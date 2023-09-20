#include <iostream>
#define N 20000
using namespace std;
int main(){
	
/*Si scriva un programma che sommi i numeri naturali a partire dal numero 1 finché la somma ottenuta non diventi superiore a 17653.
Si stampi il risultato della somma a schermo.*/
 
int sum=0;

while(sum++ < N ){
	if(sum== 17635){
		cout<< sum<<endl;
		break;
	}
}


}
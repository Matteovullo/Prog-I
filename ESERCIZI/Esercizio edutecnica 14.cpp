#include <iostream>

using namespace std;

int main(){
	/*Scrivi un algoritmo che inserito un numero intero da tastiera dica se tale numero è primo o no*/
	
	int n;
	
	cout<<"ins. n: ";cin>>n;
	
	if(n%1==0 && n%n==0 && n>1){
		cout<<"il numero e' primo"<<endl;
	}else{
		cout<<"il numero non e' primo"<<endl;
	}
}
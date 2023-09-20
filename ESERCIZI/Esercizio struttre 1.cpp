#include <iostream>

using namespace std;

int main(){
	int n;
	bool primo;
	
	cout<<"inserirsci un numero: ";cin>>n;
	
	
	if (n>1){
		if(n%2==0 || n%3==0 || n%5==0 || n&7==0 || n%11==0){
		bool primo=false;
		cout<<primo;
		}else{
			bool primo=true;
			cout<<primo;
		}
	}
}
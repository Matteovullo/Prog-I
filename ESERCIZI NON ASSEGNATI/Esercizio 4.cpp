#include <iostream>
using namespace std;
main(){
	int x,y,p,i;
	cout<< "ins. x:" ; cin>> x;
	cout<< "ins. y:" ; cin>> y;
	p=0;
	i=0;
	do{
		p+=x;
		i++;
	}while (i<y);
	cout<<p;
}
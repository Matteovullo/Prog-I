#include <iostream>

using namespace std;

int main(){
	
	 /*Codificare in linguaggio C++ un algoritmo che stampi a ritroso i numeri pari minori o uguali a mille; Il loop deve comunque
     terminare se la somma dei numeri precedentemente stampati `e maggiore o uguale a centomila*/
     
     int somma=0;
     for(int i=1000;i>0;i--)
	 {
	    if(somma>=10000)
        {
     	cout<<"valore superato"<<endl;
     	break;
	    }
	    else
	    {
	     	if(i%2==0)
	 	    {
	 		cout<<i<<endl;
	 		somma+=i;
		    }
	    }
     }
}


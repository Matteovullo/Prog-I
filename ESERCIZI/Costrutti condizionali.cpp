#include <iostream>

using namespace std;

int main(){
	
	//Si scriva un programma che prenda in input dall’utente un valore x e stampi a schermo i seguenti valori:
    //1, se x>55;
    //0, altrimenti.
    //int x;
    //cout<<"ins x: "; cin>>x;
    //if(x>55)
    {
    //	cout<<"1"<<endl;
	}
	//else
	{
	//	cout<<"0"<<endl;
	}
	
	//Si scriva un programma che prenda in input dall’utente due valori x e y e stampi a schermo i seguenti valori:
    //0, se (x>y−5)∧(x<y+5)
    //altrimenti:
    //1 se x è dispari;
   //0 se x è pari.
   int x,y;
   cout<<"ins x: " ;cin>>x;
   cout<<"ins y: "; cin>>y;
   if(x>y-5 && x>y+5)
   {
   	cout<<"0"<<endl;
   }
   else
   {
   	
	   if (x%2 != 0)
   	   {
   	cout<<"1"<<endl;
       }
	    else
		{
   	    cout<<"0"<<endl;
		}
   }   
}
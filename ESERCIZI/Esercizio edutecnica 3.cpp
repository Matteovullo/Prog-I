#include <iostream>

using namespace std;

int main(){
	/*Dati tre numeri interi, inseriti da tastiera, restituirli, indicando il minimo, il massimo ed il medio.*/
	
	int a,b,c,max,med,min;
	
	cout<<"ins. a: "; cin>>a;
	cout<<"ins. b: "; cin>>b;
	cout<<"ins. c: "; cin>>c;
	
	if (a>b && a>c)
	{
		max=a;
		if (b>c)
		{
			med=b;
			min=c;
		}
		else
		{
			med=c;
			min=b;
		}
		cout<<max<<endl<<med<<endl<<min<<endl;
	}
	
	if(b>a && b>c)
	{
		max=b;
		if (a>c)
		{
			med=a;
			min=c;
		}
		else
		{
			med=c;
			min=a;
		}
		cout<<max<<endl<<med<<endl<<min<<endl;
	}
	
	if (c>a && c>b)
	{
		max=c;
		if (a>b)
		{
			med=a;
			min=b;
		}
		else
		{
			med=b;
			min=a;
		}
		cout<<max<<endl<<med<<endl<<min<<endl;
	}
	
}
	
	
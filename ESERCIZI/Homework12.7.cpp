#include <iostream>

using namespace std;

int main(){
	int t1,t2,t3,t4,t5,acqua,minuti;
	
	cout<<"ins tubo: " ; cin>>t1;
	cout<<"ins tubo: " ; cin>>t2;
	cout<<"ins tubo: " ; cin>>t3;
	cout<<"ins tubo: " ; cin>>t4;
	cout<<"ins tubo: " ; cin>>t5;
	
	if (t1!=t2 && t1!=t3 && t1!=t4 && t1!=t5 && t2!=t3 && t2!=t4 && t2!=t5 && t3!=t4 && t3!=t5 && t4!=t5)
	{
		cout<<"ins minuti: " ; cin>>minuti;
		if(minuti>0)
		{
			if(t1%2==0)
			{
			acqua=60*minuti;
			cout<<"acqua raccolta: "<<acqua<<endl;
			}
			else
			{
				acqua=120*minuti;
				cout<<"acqua raccolta: "<<acqua<<endl;
			}
			
			if(t2%2==0)
			{
			acqua=60*minuti;
			cout<<"acqua raccolta: "<<acqua<<endl;
			}
			else
			{
				acqua=120*minuti;
				cout<<"acqua raccolta: "<<acqua<<endl;
			}
			
			if(t3%2==0)
			{
			acqua=60*minuti;
			cout<<"acqua raccolta: "<<acqua<<endl;
			}
			else
			{
				acqua=120*minuti;
				cout<<"acqua raccolta: "<<acqua<<endl;
			}
			
			if(t4%2==0)
			{
			acqua=60*minuti,
			cout<<"acqua raccolta: "<<acqua<<endl;
			}
			else
			{
				acqua=120*minuti;
				cout<<"acqua raccolta: "<<acqua<<endl;
			}
			
			if(t5%2==0)
			{
			acqua=60*minuti;
			cout<<"acqua raccolta: "<<acqua<<endl;
			}
			else
			{
				acqua=120*minuti;
				cout<<"acqua raccolta: "<<acqua<<endl;
			}
		}
	}
	else
	{
		cout<<"valori non validi, riprovare"<<endl;
	}
}
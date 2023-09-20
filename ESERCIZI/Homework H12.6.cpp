#include <iostream>
using namespace std;
int main (){
	
	double persone,diabete,uova,farina,zucchero,fruttosio,uova_medio,fruttosio_medio,uova_base,farina_medio,zucchero_base,farina_base,zucchero_medio,yes;
	cout << "numero di persone che mangieranno il dolce?"; cin >> persone;
	cout << "ci sono persone diabetiche? se si quante?"; cin >> diabete;
	
	uova_base=4;
	farina_base=0.3;
	zucchero_base=0.1;
	uova_medio=4*2.5;
	farina_medio=0.3*2.5;
	zucchero_medio=1.5*0.1;
	fruttosio_medio=2/3*(zucchero_medio);
		
	if (persone>=2 && persone<=4 && diabete!=0)
	{
		uova=4;
		farina=0.3;
		zucchero=0.1;
	    cout <<"uova: "<<uova << endl;
        cout <<"farina: "<<farina << endl;
    	cout <<"zucchero: " <<zucchero << endl;
	}
	else (diabete>0);
	{
		uova=4;
		farina=0.3;
		fruttosio=2/3*(0.1);
		cout << "uova: "<<uova << endl;
    	cout <<"farina: "<<farina << endl;
        cout <<"fruttosio: "<< fruttosio << endl;
    }

	if (persone>=5 && persone<=8 && diabete!=0)
	{
		cout << "uova: "<<uova_medio<<endl;
		cout <<  "farina: "<<farina_medio<<endl;
		cout << "zucchero: "<<zucchero_medio<<endl;
	}
	
	else (diabete>0);
	{
		cout << "uova: "<<uova_medio<<endl;
		cout << "farina: "<< farina_medio<<endl;
		cout <<"fruttiosio: "<< fruttosio_medio<< endl;
	}
	
	
	if (persone>=9 && persone<=12 && diabete!=0)
	{
		uova=uova_base+uova_medio;
	    farina=farina_base+farina_medio;
	    zucchero=zucchero_base+zucchero_medio;
	    cout << "uova: "<<uova <<endl;
		cout << "farina: "<<farina << endl;
		cout << "zucchero"<<zucchero << endl;
	}
	else (diabete>0);
	{
		uova=uova_base+uova_medio;
	    farina=farina_base+farina_medio;
		fruttosio=2/3*(zucchero_base+zucchero_medio);
		cout << "uova: "<<uova <<endl;
		cout << "farina: "<<farina << endl;
		cout <<"fruttosio: "<<fruttosio << endl;
	}
		
}
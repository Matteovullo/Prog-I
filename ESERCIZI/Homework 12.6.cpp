#include <iostream>

using namespace std;

int main(){
	
	/*INPUT: NPERSONE= DA 2 A 16
	DIABETICI= SI/NO
	CALCOLA DOSAGGI NEL SEGUENTE MODO:
	TRA 2 E 4 INCL: DOSAGGIO BASE= 0.3KG FARINA, 4 UOVA, 0.1KG ZUCCHERO
	TRA 5 E 8 INCL: DOS MEDIO= 2,5 FARINA BASE, 2,5 UOVA BASE, 1,5 ZUCCHERO BASE
	TRA 9 E 16 INCL:DOS ESTESO= SOMMA TRA MEDIO E BASE
	SE CI SONO DIABETICI USARE IL FRUTTOSIO AL POSTO DELLO ZUCCHERO: 
	FRUTTOSIO= 2/3 ZUCCHERO
	*/
	
	int persone,uova;
	bool diabetici;
	float farina,zucchero,fruttosio;
	
	cout<<"numero di persone che mangeranno la torta: " ; cin>>persone;
	cout<<"Ci sono diabetici? inserire solo 1 o 0 (1=si 0=no)" ; cin>>diabetici;
	
	if (persone >=2 && persone <=4)
	{
		if (diabetici==false)
		{
			farina=0.3;
			zucchero=0.1;
			uova=4;
			cout<<"Dosaggio base: "<<farina<<endl<<zucchero<<endl<<uova<<endl;
		}
		else
		{
			farina=0.3;
			uova=4;
			fruttosio=2/3*0.1;
			cout<<"Dosaggio base: "<<farina<<endl<<fruttosio<<endl<<uova<<endl;
		}
	}
	
	if (persone >=5 && persone <=8)
	{
		if (diabetici==false)
		{
			farina=2.5*0.3;
			zucchero=1.5*0.1;
			uova=2.5*4;
			cout<<"Dosaggio medio: "<<farina<<endl<<zucchero<<endl<<uova<<endl;
		}
		else
		{
			farina=2.5*0.3;
			uova=1.5*4;
			fruttosio=2/3*(2.5*0.1);
			cout<<"Dosaggio medio: "<<farina<<endl<<fruttosio<<endl<<uova<<endl;
		}
	}
	
	if (persone >=9 && persone <=12)
	{
		if (diabetici==false)
		{
			farina=0.3+(2.5*0.3);
			zucchero=0.1+(1.5*0.1);
			uova=4+(2.5*4);
			cout<<"Dosaggio esteso: "<<farina<<endl<<zucchero<<endl<<uova<<endl;
		}
		else
		{
			farina=0.3+(2.5*0.3);
			fruttosio=2/3*(0.1+(1.5*0.1));
			uova=4+(2.5*4);
			cout<<"Dosaggio esteso: "<<farina<<endl<<fruttosio<<endl<<uova<<endl;
		}
	}

}
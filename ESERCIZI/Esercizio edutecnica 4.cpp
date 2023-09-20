#include <iostream>

using namespace std;

int main(){
	/*Realizza un programma per il calcolo delle provvigioni di un agente di commercio che vende the e caffè.
	Se l'agente vende più di 5000€ di caffè ha diritto ad una provvigione del 10% altrimenti del 5%.
	Sul the la provvigione è del 4% ma se vende più di 10.000€ è del 16%. Se il totale venduto supera
	i 20.000€ vie è un ulteriore premio pari al 12% sul totale.*/
	   
	int caffe,the,extra_c,extra_t,proviggione_t,proviggione_c,proviggione_f;
	
	cout<<"quanto hai guadangato dalla vendita del caffe? " ; cin>>caffe;
	cout<<"quanto hai guadangato dalla vendita del the? " ; cin>>the;
	
	if(caffe>5000)
	{
		extra_c=caffe*0.1;
		proviggione_c=caffe+extra_c;
	}
	else
	{
		extra_c=caffe*0.05;
		proviggione_c=caffe+extra_c;
	}
	
	if(the>10000)
	{
		extra_t=caffe*0.16;
		proviggione_t=caffe+extra_t;
	}
	else
	{
		extra_t=caffe*0.04;
		proviggione_t=caffe+extra_t;
	}
	
	if(proviggione_t+proviggione_c>20000)
	{
		proviggione_f=(proviggione_t+proviggione_c)*0.12;
		cout<<proviggione_f<<endl;
	}
	else
	{
		cout<<proviggione_c<<endl<<proviggione_t;
	}
	
	

}
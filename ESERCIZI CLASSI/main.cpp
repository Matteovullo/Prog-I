#include "CoppiaDiDadi.cpp"
#include <iostream>
int main(){
	CoppiaDiDadi d;
	int count;
	for(int i=0; i<1000; i++){
		d.lancia1();
		d.lancia2();
		if((d.getValore1()==6) && (d.getValore2()==6)){
			count++;
		}
	}
	cout<<count;
}

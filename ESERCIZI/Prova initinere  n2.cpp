#include <iostream>
#include <string>
using namespace std;
int main(){
	/*Scrivere un metodo che prenda in input una matrice V di stringhe contenente verbi italiani
all’infinito, e restituisca la percentuale dei verbi della prima coniugazione. */

	int n;
	int count_are=0;
	
	cout<<"isnerire n: ";
	cin>>n;
	string v[n];
	for(int i=0; i<n; i++){
		cout<<"inserire un verbo all'infinito': ";cin>>v[i];
	}
	
	for(int i=0; i<n; i++){
		if(v[i].substr(v[i].length()-3,3)=="are"){
			count_are++;
		}
	}
	
	float percentuale=((float)count_are/n)*100;
	cout<<percentuale;
}
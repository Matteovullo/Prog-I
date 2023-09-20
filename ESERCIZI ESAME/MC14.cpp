/*14.Scrivere un metodo che prenda come parametri 
formali una matrice A di stringhe ed un intero k, e 
restituisca in output una copia di A in cui tutte le 
stringhe della colonna k-esima siano state epurate 
dalle lettere non italiane.*/

#include <iostream>
#define n 2
using namespace std;

string **func(string **c,int k){
	string l;
    char vet[24];
	string** a=new string *[n];
	
	for(int i=0; i<n; i++){
		a[i]=new string[n];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
            if(j==k){
                l= c[i][j]; 
                for(int z=0; z< l.length(); z++){
                    if(l[z]=='k' ||l[z] =='j' ||l[z]  =='w'){
                        vet[z]=' ';
                    }else
                        vet[z]=l[z];
                }
                a[i][j]=vet;
            }
            else{
                a[i][j]= c[i][j];
            }
        }
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"A"<<"["<<a[i][j]<<"]"<<endl;
		}
	}
	return a;
}

int main(){
	string **c=new string *[n];
	
	for(int i=0; i<n; i++){
		c[i]=new string [n];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<"inserire una stringa: ";cin>>c[i][j];
		}
	}
	
	cout<<func(c,1);
}


#include <iostream>

using namespace std;

/*Si definisca una funzione stats che prenda in input 5 puntatori a interi in1, in2, out_min, out_max, out_mean. 
La funzione deve calcolare il minimo, massimo e la media dei due valori in input e inserire i risultati nei due parametri di output.
Utilizzare il modificatore const per specificare chiaramente quali parametri verranno utilizzati solo in lettura e quali anche in scrittura.
Si noti che è possibile utilizzare il modificatore const in maniera simile quando si passano dei parametri per riferimento. Ad esempio:
void sum(int const &x, int const &y, int &out) {
    out = x+y;
    x++; //questa istruzione produce un errore di compilazione. x è di sola lettura!
}*/

int func(const int &in1,const int &in2, int &out_min, int &out_max, int &out_mean){
	if(in1>in2){
		out_max=in1;
		out_min=in2;
	}else{
		out_max=in2;
		out_min=in1;
	}
	out_mean=(in1+in2)/2;
	
	return out_max, out_min, out_mean;
}

int main(){
	cout<<func(5,6)
}
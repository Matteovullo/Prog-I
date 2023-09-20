#include <iostream>
#include <cmath>
using namespace std;
int main (){
	float raggio,pi_greca,circonferenza,area;
	pi_greca=3.14;
	cout << "inserire raggio: " ; cin>> raggio;
	circonferenza=2*pi_greca*raggio;
	area=pow(raggio,2)*pi_greca;
	cout << "l'area e':" << area<< endl;
	cout << "la circonferenza e'':" << circonferenza;
}
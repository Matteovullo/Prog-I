#include <iostream>
#include <string>

using namespace std;
int main (){
	string s1="Hello word";
	string s2="Pippo";
	
	//stampare i caratteri della stringa il che siano contenuti in s2 nell' ordine in cui appaiono in s1
	// oo
	
	for (int i=0; i<s1.length(); i++){
		for (int j=0; j<s2.length(); j++){
			if(s1[i]==s2[j]){
				cout<< s1[i];
				continue;
			}
		}
	}
}
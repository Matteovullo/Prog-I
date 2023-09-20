#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*Si scriva una funzione che prenda in input due stringhe (string object) e restituisca una terza stringa (string object) 
che contenga i caratteri della prima stringa. Se il carattere è anche contenuto nella seconda stringa, questo verrà visualizzato in maiuscolo.*/

char *  func(string s1,string s2){
    int n=s1.length();
	char * s3= new char[n];
	bool valore=false;                                
	for(int i=0; i<s1.length(); i++){
		for(int j=0; j<s2.length(); j++){
			if(s1[i]==s2[j]){
				valore=true;
				break;
			}
		}
		if(valore==true){
			s3[i]= toupper(s1[i]);
		}else{
			s3[i]=s1[i];
		}
		valore=false;
	}
    return s3;
}

int main(){
	string s1=func("pippo","topolino");
	cout<<s1;
}
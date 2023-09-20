#include <iostream>
#include <cstring>
using namespace std;

/*Si scriva una funzione che prenda in input due stringhe (c-like string) 
e restituisca una terza stringa (c-like string) che contenga i caratteri in comune tra la prima e la seconda stringa.*/

char func(string s1,string s2){
	char *s3=strstr(s1,s2);
	return s3;
}

int main(){
	string s1=func("pippo","paperino");
	cout<<s1;
}
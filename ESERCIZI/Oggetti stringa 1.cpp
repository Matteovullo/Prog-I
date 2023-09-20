#include <iostream>
#include <string>
using namespace std;

/*Si scriva una funzione che prenda in input due stringhe (string object)
 e restituisca una terza stringa (string object) che contenga i caratteri in comune tra la prima e la seconda stringa.*/
 
 int main(){
 	string s1,s2,s3;

 	cout<<"inserire una stringa: ";cin>>s1;
 	cout<<"inserire una stringa: ";cin>>s2;

 	for(int i=0; i<s1.length(); i++){
 		if(s1.at(i)==s2.at(i)){
 			s3+=s1[i];
		 }
	}
	cout<<s3<<endl;
}
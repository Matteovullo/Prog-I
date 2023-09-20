/*

*/

#include <iostream>
using namespace std;

int main(){
	char a[]="pippo";
	char b[]="p";
	
	char *c=strstr(a,b);
	cout<<c;
	return 0;
}

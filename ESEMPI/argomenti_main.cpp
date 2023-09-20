#include <iostream>
#include <sstream>
using namespace std;


int main(int arg, char *argv[]){
	for(int i=0; i<arg; i++){
		cout << argv[i] << endl;
	}
}
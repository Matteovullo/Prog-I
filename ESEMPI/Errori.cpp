/*

*/

#include <iostream>
#include <limits>
using namespace std;



int main(){
	/*int i;
	cout << "Inserire un numero" << endl;
	cin >> i;
	if(cin.fail()){
		cerr << "Sbagliato" << endl;
	}*/
	
	bool finito=false;
	/*while(!finito){
		int j;
		cout << "Inserire un numero" << endl;
		cin >> j;
		if(cin.eof())
			finito=true;
	}*/


	do{
		int h;
		cout << "inserire un numero" << endl;
		cin >> h;
	if(cin.fail()){
		cerr << "errore" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}else{
		finito=true;
	}
	}while(!finito);
	return 0;
}

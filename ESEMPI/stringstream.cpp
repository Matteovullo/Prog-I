/*

*/

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;



int main(){
	stringstream ss;
	string s;
	int x=5;
	ss << 5;
	ss >> s;
	cout << s << endl;
	
	stringstream y;
	int q;
	string l="3333";
	y << l;
	y >> q;
	cout << q << endl;
	
	/*stringstream u;
	u << "ciao";
	string h=u.str();
	cout << h << endl;*/
	
	string j="gbrstgstrb";
	stringstream d=stringstream(j);
	cout << d.str() << endl;
	
	cout << sizeof(string) << endl;
	cout << sizeof(int) << endl;

	std::string k = "Hello";
	std::cout << sizeof(k) << endl;

	ifstream file("testo.txt");
	string h;
	if(file.is_open()){
		file >> h;
		cout << h << endl;
	}
	file.close();

	ofstream myf("testo.txt");
	myf << "sucunaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
	myf << "contro sucuna" << endl;
	myf.close();

	fstream myfile("testo.txt", ifstream::out | ofstream::in);
	string p;
	myfile << "a" << endl;
	myfile << "trrr" << endl;
	myfile << "ffffff" << endl;
	myfile << "vrvwergerg" << endl;
	getline(myfile, p);

	int **x=new int*[2];
	for(int i=0; i<2; i++) ;
	//cout << *x << endl;
	cout << x << endl;
	return 0;
}

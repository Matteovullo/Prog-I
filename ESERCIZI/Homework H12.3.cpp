#include <iostream>

#include <string>

using namespace std;

int main(){
	string name;
	string surname;
	cout << "your name is:"; cin>> name;
	cout << "your surname is:"; cin >> surname;
	cout <<name.substr(0,1);
	cout <<surname.substr(3,5);
	if (name.substr(0,1) == surname.substr(0,1))
	{
		cout <<" la prima lettera del nome e' uguale all' ultima lettera del cognome"<<endl;
	}
	else
	{
		cout << "la prima lettera del nome non e' uguale all' ultima lettera del cognome"<<endl;
	}
	
	if (name.length() == surname.length())
	{
		cout << "il numero di caratteri del cognome e' uguale al numero do caratteri del cognome"<<endl;
	}
	
	else
	{
		cout << "il numero di caratteri del cognome non e' uguale al numero do caratteri del cognome"<<endl;
	}

}
#include <iostream>
#include <fstream>
using namespace std;

/*int main(){
    string s;
    ifstream file("testo.txt");
    if(file.is_open()){
        while(getline(file, s)){
            cout << s << endl;
        }
    }
    file.close();
}*/

int main(){
    ofstream file("testo.txt");
    file << "C++ mette a disposizione le seguenti classi che permettono di gestire l’input/output su file: " << endl;
    file.close();
}
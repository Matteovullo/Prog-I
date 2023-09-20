/*6.Scrivere un metodo che prenda come parametro 
formale un cubo (array tridimensionale) C di stringhe, 
e restituisca in output una stringa contenente tutte le 
desinenze di due caratteri delle stringhe sulla faccia 
superiore del cubo C. */
#include <string>
#include <iostream>
using namespace std;

string fun(string ***c,int n){
    string s="";
    for(int k=0; k<n; k++){
        for(int j=0; j<n; j++){
            if(c[0][j][k].length() >= 2 && c[0][j][k].empty() != 0){
                string k = c[0][j][k].substr(c[0][j][k].length()-2, 2);
                s+=k;
            }
        }
    }
    return s;
}

int main(){
    int n=3;
    string ***a=new string **[n];
    for(int i=0; i<n; i++){
        a[i]=new string *[n];
        for(int j=0; j<n; j++){
            a[i][j]=new string [n];
            for(int k=0; k<n; k++){
                a[i][j][k]="ciao";
            }
        }
    }
    
    cout<<fun(a,3);
}
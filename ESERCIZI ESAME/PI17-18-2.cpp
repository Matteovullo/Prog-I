/*Scrivere un metodo che prenda in input una matrice V di stringhe contenente verbi italiani
all’infinito, e restituisca la percentuale dei verbi della prima coniugazione. */

#include <string>
#include <iostream>
#define n 3
#define m 3
using namespace std;

double fun(string **v){
    string str="are";
    int count;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j].substr(v[i][j].length()-3,3) == str)
                count++;
        }
    }
    int k=n*m;
    double percentuale=((double)count/k)*100.00;
    return percentuale;
}

int main(){
    string **d=new string *[n];
    for(int i=0; i<n; i++){
        d[i]=new string [m];
        for(int j=0; j<m; j++){
            d[i][j]="mangiare";
        }
    }

    cout<<fun(d);

}

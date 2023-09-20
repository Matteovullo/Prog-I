/*Data una matrice 8×8 riempirla con numeri casuali compresi tra zero e uno, 
e verificare se in ogni riga c’è un numero di uni pari a quello della riga precedente.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));
    double a[8][8]={};
    int b[8];
    for(int i=0; i<8; i++){
        cout<< "riga " << i << endl;
        for(int j=0; j<8; j++){
            a[i][j]=rand()/(double)RAND_MAX;
            cout<< a[i][j] << endl;
        }
    }
    for(int i=0; i<8; i++){
        int c=0;
        for(int j=0; j<8; j++){
            if(a[i][j]==1.0){
                c++;
            }
        }
        cout << c << endl;
        b[8]=c;
    }
    for(int i=0; i<8; i++){
        for(int j=i+1; j<8; j++){
            if(b[i]==b[j] && b[i]!=0){
                cout<<"la riga "<<i<<" ha un numero di 1 pari alla riga "<<j<<endl;
            } 
        }
    }
}
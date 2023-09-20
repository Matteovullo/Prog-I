/*Es 5. Data una matrice 4×4 di interi trovare la riga o la colonna con somma più alta.*/

#include <iostream>

using namespace std;

int main(){
    int a[4][4];

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            a[i][j]=0;
        }
    }

    int b[8];

    for(int i=0; i<4; i++){
        int somma1=0;
        for(int j=0; j<4; j++){
            somma1+=a[i][j];
        }
        b[i]=somma1;
    }

    for(int j=0; j<4; j++){
        int somma2=0;
        for(int i=0; i<4; i++){
            somma2+=a[i][j];
        }
        b[j]=somma2;
    }

    int max=b[0];

    for(int i=0; i<8; i++){
        if(max>b[i])
            max=b[i];
    }

    cout << max << endl;
}
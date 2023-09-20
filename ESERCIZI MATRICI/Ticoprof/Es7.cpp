/*Verificare se una matrice 8×8 di interi è una “scacchiera” ovvero se vi sono presenti 
solo 0 e 1 alternati tra loro.*/

#include <iostream>

using namespace std;

int main(){
    int a[8][8];
    bool valore=true;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(valore){
                a[i][j]=0;
                valore=false;
            }else{
                a[i][j]=1;
                valore=true;
            }
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(j%2 != 0){
                if(a[i][j] != 1){
                    cout << "la matrice non è una scacchiera !" << endl;
                    break;
                }
            }
            if(j%2 == 0){
                if(a[i][j] != 0){
                    cout << "la matrice non è una scacchiera !" << endl;
                    break;
                }
            }
        }
    }

    cout<< "la matrice è una scacchiera !" << endl;
}

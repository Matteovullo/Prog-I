/*Memorizzare in una matrice 8×8 delle cornici una di zeri e di uni 
alternate tra loro, usando al massimo due for, alla fine stampare la matrice.*/

#include <iostream>

using namespace std;

/*int main(){
    int a[8][8];

    for(int i=0; i<8; i++){
        if(i%2 == 0){
        for(int j=i; j<8-i; j++){
            a[i][j]=0;
            a[j][i]=0;
        }
        //for(int k=i; k<8-i; k++){
        //    a[k][i]=0;
        //}
        for(int p=7-i; p>=0+i; p--){
            a[i][p]=0;
        }
        for(int h=i; h<8-i; h++){
            a[7-i][h]=0;
        }
        }
        else{
           for(int j=i; j<8-i; j++){
            a[i][j]=1;
            a[j][i]=1;
        }
        //for(int k=i; k<8-i; k++){
        //   	a[k][i]=1;
        //}
        for(int p=7-i; p>=0+i; p--){
            a[i][p]=1;
        }
        for(int h=i; h<8-i; h++){
            a[7-i][h]=1;
        } 
        }
    }
    
    a[2][6]=1;
    a[3][6]=1;
    a[4][6]=1;
    a[5][6]=1;

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
*/

int main(){
    int a[8][8];
    int val = 0;

    for(int i=0; i<8; i++){
        if(i%2 == 0){
            for(int j=i; j<8-i; j++){
                a[i][j]=0;
                a[j][i]=0;
                a[j][8-i-1] = 0;
                a[8-i-1][j] = 0;
            }
        }
        else {
            for(int j=i; j<8-i; j++){
                a[i][j]=1;
                a[j][i]=1;
                a[j][8-i-1] = 1;
                a[8-i-1][j] = 1;
            }
        }
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
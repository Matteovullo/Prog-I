/*Scrivere un metodo che prenda in input una matrice A ed un array B entrambe di float, 
e restituisca un boolean che indichi se esiste in A una coppia di elementi verticali 
contigui la cui somma è pari alla somma di due elementi qualsiasi in B.

N.B. : Non è possibile utilizzare array ausiliari.*/

#include <iostream>
#define n 3
#define m 3
using namespace std;

bool fun(float **a, float *b){
    float somma1, somma2;

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            somma1=a[i][j]+a[i+1][j];
            for(int o=0; o<n; o++){
                float aux=b[o];
                for(int h=o; h<n; h++){
                    if(h != o)
                    somma2=b[h]+aux;
                    if(somma1==somma2){
                        return true;
                    }
                }
            }
        }
    }
    return false;

}

int main(){
    float **d=new float *[n];
    for(int i=0; i<n; i++){
        d[i]=new float [m];
        for(int j=0; j<m; j++){
            d[i][j]=1.0;
        }
    }

    float *p=new float [n];
    for(int i=0; i<n; i++){
        p[i]=5.0;
    }

    cout<<fun(d,p);

} 
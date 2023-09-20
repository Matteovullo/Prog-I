/*5.Scrivere un metodo che prenda come parametri 
formali una matrice A n×m di long ed un long x, e 
restituisca in output l’indice della colonna di A con il 
maggior numero di occorrenze di x.*/
#include <iostream>
using namespace std;

int fun(long **a,int n, int m, long x){
    int b[m];
    for(int j=0; j<m; j++){
        int count=0;
        for(int i=0; i<n; i++){
            if(a[i][j] == x) count++;
        }
        b[j]=count;
    }
    int count2=0;
    for(int i=0; i<m; i++){
        if(b[i]==0) count2++;
    }

    if(count2==m) return -1;

    int max=b[0];
    int index=0;
    for(int i=0; i<m-1; i++){
        if(b[i] > max){
            max=b[i];
            index=i;
        }
    }

    return index;
}

int main(){
    int n=2;
    int m=4;
    long **a=new long *[n];
    for(int i=0; i<n; i++) a[i]=new long [n];
    a[0][0]=1;
    a[1][0]=1;
    a[0][1]=1;
    a[1][1]=0;
    a[0][2]=0;
    a[1][2]=0;
    a[0][3]=1;
    a[1][3]=1;

    cout<<fun(a,2,3,1);
}
#include <iostream>
using namespace std;

int fun(double ***A, int m, int n, short k, double q){
    int seq=0;
    double media=0;
    int c=0;

    for(int y=0; y<=m-n; y++){
        for(int i=0; i<n; i++){
            media=0;
            seq=0;
            for(int h=i; h<n; h++){
                if(A[h+y][h]){
                    media+=*A[h+y][h];
                }
                seq++;
                //cout << seq << endl;
                if(seq == k){
                    if(media/seq > q){
                        //cout << media/c << endl;
                        c++;
                        //cout << c << endl;
                    }
                    break;
                }
            }
        }
    }

    return c;
}

int main(){
    int m=4, n=3;
    double ***A=new double **[m];
    for(int i=0; i<m; i++){
        A[i]=new double *[n];
        for(int j=0; j<n; j++){
            A[i][j]=new double(1);
        }
    }

    cout << fun(A, 4, 3, 2, 0);
}
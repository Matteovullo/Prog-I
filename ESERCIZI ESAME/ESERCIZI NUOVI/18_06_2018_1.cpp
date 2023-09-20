#include <iostream>

using namespace std;

int *fun(int **A, int n, int *B){
    int *C=new int [n];
    int c=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int l=A[i][j];
            for(int h=0; h<n; h++){
                if(l == B[h]){
                    int sup=l;
                    for(int y=0; y<n; y++){
                        if(sup != C[y]){
                            c++;
                        }
                    }
                    //cout << c << endl;
                    if(c == n){
                        C[j]=sup;
                    }
                    c=0;
                }
            }
        }
    }

    for(int i=0; i<2; i++){
        cout << C[i] << " ";
    }

}

int main(){
    int **A=new int*[2];
    int c=0;
    for(int i=0; i<2; i++){
        A[i]=new int [2];
        for(int j=0; j<2; j++){
            A[i][j]=c;
            c++;
        }
    }

    int *B=new int [2];
    B[0]=1;
    B[1]=2;

    fun(A, 2, B);
}
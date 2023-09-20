#include <iostream>
#include <cmath>

using namespace std;

int **matrice_trasposta(int **A, int n, int m){
    int **B;
    if(n == m){
        int **B=new int *[n];
        for(int i=0; i<n; i++){
            B[i]=new int [m];
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                B[j][i]=A[i][j];
                cout << B[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        int **B=new int *[m];
        for(int i=0; i<m; i++){
            B[i]=new int [n];
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                B[i][j]=A[j][i];
                cout << B[i][j] << " ";
            }
            cout << endl;
        }
    }

    cout << endl;

    return B;

}

int complementi_algebrici(int **A,int n, int in, int jn){
    int complemento;
    int **B=new int *[n-1];
    for(int i=0; i<n-1; i++){
        B[i]=new int [n-1];
        for(int j=0; j<n-1; j++){
            if(i != in && j != jn){
                B[i][j]=A[i][j];
            }
        }
    }
    int c=in+jn;
    if(c%2 == 0){
        complemento=determinante(B, n-1); 
    }else{
        complemento=determinante(B, n-1)*(pow(-1, c));
    }
    
    return complemento;
}

int determinante(int **A, int n){
    int determinante;
    if(n == 2){
        determinante=((A[1][1]*A[2][2])-(A[1][2]*A[2][1]));
    }
    if( n == 3){
        determinante=(((A[1][1]*A[2][2]*A[3][3])+(A[1][2]*A[2][3]*A[3][1])+(A[1][3]*A[2][1]*A[3][2]))-((A[1][3]*A[2][2]*A[3][1])+(A[1][1]*A[2][3]*A[3][2])+(A[1][2]*A[2][1]*A[2][3])));
    }
    if (n >= 4){
        for(int i=0; i<n; i++){
        int complemento;
        int **B=new int *[n-1];
        for(int i=0; i<n-1; i++){
            B[i]=new int [n-1];
            for(int j=0; j<n-1; j++){
            if(i != i && j != 1){
                B[i][j]=A[i][j];
            }
        }
    }
    int c=i+1;
    if(c%2 == 0){
        complemento=determinante(B, n-1); 
    }else{
        complemento=(determinante(B, n-1))*(pow(-1, c));
    }
        determinante+=((A[i][0])*complemento);
        }
    }
    return determinante;
}

int rango(int **A, int n, int m){
    if(determinante(A)==0 && n == m){
        return n;
    }


}


int **matrice_aggiunta(int **A, int n){
    int **B=matrice_trasposta(A, n, n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            B[i][j]=complementi_algebrici(A, n, i, j);
        }
    }

    return B;

}

int **matrice_inversa(int **A, int n){
    if(determinante(A, n) == 0)
        return;
    
    int **B=matrice_trasposta(A, n, n);
    B=matrice_aggiunta(B, n);
    int **inversa=new int *[n];
    for(int i=0; i<n; i++){
        inversa[i]=new int [n];
        for(int j=0; j<n; j++){
            inversa[i][j]=(1/determinante(A, n))*B[i][j];
        }
    }

    return inversa;
}

void print(int **A,int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



int main(){
    int **A=new int *[3];
    int c=0;

    for(int i=0; i<3; i++){
        A[i]=new int[3];
        for(int j=0; j<3; j++){
            A[i][j]=c;
            cout << A[i][j] << " ";
            c++;
        }
        cout << endl;
    }

    cout << endl;

    int **B=matrice_inversa(A, 3);
    print(B, 3);

    
}
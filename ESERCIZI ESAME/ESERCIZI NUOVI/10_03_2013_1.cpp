/*Scrivere un metodo che prenda in input una matrice A di int, e restituisca un boolean che indichi se
esiste una riga in A tutta costituita da elementi ognuno multiplo di un qualche elemento della riga
contigua successiva. (Ad es. [21, 6, 32, 16] e [8, 5, 9, 3] sono due righe siffatte.)*/

#include <iostream>

using namespace std;

bool fun(int **A, int n, int m){

    for(int i=0; i<n-1; i++){
        int c=0;
        cout << "i" << endl;
        for(int j=0; j<m; j++){
            int l=A[i][j];
            cout << "l" << endl;
            for(int k=0; k<m; k++){
                if(l%A[i+1][k] == 0){
                    c++;
                    cout << c << endl;
                    break;
                }
            }
        }
        if(c == m)
            return true;
    }

    cout << endl;

    return false;

}

int main(){
    int **B=new int*[2];
    for(int i=0; i<2; i++){
        B[i]=new int[3];
        for(int j=0; j<2; j++){
            //B[i][j]=10;
            //cout << B[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl;

    B[0][0]=13;
    B[1][0]=17;
    B[0][1]=19;
    B[1][1]=23;

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << fun(B,2,2);
}
#include <iostream>

using namespace std;

void fun(int **A, int n, int m){

    for(int j=0; j<n; j++){
        if(j%2 == 0){
            for(int i=0; i<n; i++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        if(j%2 != 0){
            for(int i=n-1; i>=0; i--){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    int **A=new int*[3];
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

    fun(A, 3, 3);
}
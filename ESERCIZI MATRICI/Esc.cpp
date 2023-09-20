#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int A[10][15];
    int c=0;

    for(int i=0; i<10; i++){
        for(int j=0; j<15; j++){
            A[i][j]=c;
            cout << A[i][j] << " ";
            c++;
        }
        cout << endl;
    }
    int max=A[0][0];
    int min=A[0][0];
    for(int i=0; i<10; i++){
        for(int j=0; j<15; j++){
            if(A[i][j] > max)
                max=A[i][j];
            if(A[i][j] < min)
                min=A[i][j];
        }
    }
    cout << endl;
    int p=0;
    for(int i=0; i<10*15; i++){
        if(pow(2,p) >= min && pow(2,p) <= max)
            cout << pow(2,p) << endl;
        
        p++;
    }
}
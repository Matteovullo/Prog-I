#include <iostream>

using namespace std;

void fun(int **A){

    int somma1;
    int somma2;

    for(int i=0; i<7; i++){
        for(int j=0; j<6; j++){
            somma1+=A[i][j];
        }
        double media=somma1/6;
        cout << "Media prova " << i+1 << " è: " << media << endl; 
    }

    for(int j=0; j<6; j++){
        for(int i=0; i<7; i++){
            somma2+=A[i][j];
        }
        double media=somma2/7;
        cout << "Media studente " << j+1 << " è: " << media << endl; 
    }



}

int main(){
    int **A=new int*[7];

    int c=0;

    for(int i=0; i<7; i++){
        A[i]=new int[6];
        for(int j=0; j<6; j++){
            A[i][j]=c;
            c++;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    fun(A);
}
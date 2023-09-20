/*Si scriva un programma che chiede all’utente di riempire
una matrice NxN (con N costante globale predefinita), un
intero len (che deve essere un intero positivo maggiore di
1) e stampa OK se in m è presente almeno una sequenza
orizzontale, verticale o diagonale, di lunghezza len, di
elementi che crescono o diminuiscono linearmente (cioè in
cui la differenza tra due elementi successivi è costante). */

#include <iostream>

using namespace std;

bool fun(int **A, int len, int n){

    //orizontale
    if(len > n)
        return -1;
    else{
        for(int i=0; i<n; i++){
            int c=1;
            int scarto;
            for(int j=0; j<n; j++){
                scarto=A[i+1][j]-A[i][j];
                for(int k=j+1; k<len; k++){
                    if(A[k][j]- A[i][k-1] == scarto){
                        c++;
                    }
                    else{
                        break;
                    }
                }
                if(c == len){
                    cout << "ok" << endl;
                    return true;
                }
            }
        }
    }
    //verticale
    if(len > n)
        return -1;
    else{
        for(int j=0; j<n; j++){
            int c=1;
            int scarto;
            for(int i=0; i<n; i++){
                scarto=A[i+1][j]-A[i][j];
                for(int k=i+1; k<len; k++){
                    if(A[j][k]- A[k-1][j] == scarto){
                        c++;
                    }
                    else{
                        break;
                    }
                }
                if(c == len){
                    cout << "ok" << endl;
                    return true;
                }
            }
        }
    }
    //diagonale sup
    if(len > n)
        return -1;
    else{
        for(int i=0; i<n-2; i++){
            int c=1;
            int scarto;
            for(int j=i+1; j<n; j++){
                scarto=A[j-i+1][j-i+2]-A[j-i][j+i+1];
                for(int k=j+1; k<len; k++){
                    if(A[k+1][k+2]- A[k][k+1] == scarto){
                        c++;
                    }
                    else{
                        break;
                    }
                }
                if(c == len){
                    cout << "ok" << endl;
                    return true;
                }
            }
        }
    }

    //diagonale principale
    if(len > n)
        return -1;
    else{
        for(int i=0; i<n; i++){
            int c=1;
            int scarto;
            scarto=A[i+1][i+1]-A[i][i];
            for(int k=i+1; k<len; k++){
                if(A[k][k]- A[k-1][k-1] == scarto){
                        c++;
                }
                else{
                    break;
                }
            }
            if(c == len){
                cout << "ok" << endl;
                return true;
            }
        }
    }

    //diagonale inf
    if(len > n)
        return -1;
    else{
        for(int j=0; j<n-2; j++){
            int c=1;
            int scarto;
            for(int i=j+1; i<n; i++){
                scarto=A[i-j+1][i-j]-A[i-j][i-j+1];
                for(int k=i+1; k<len; k++){
                    if(A[k+1][k+2]- A[k][k+1] == scarto){
                        c++;
                    }
                    else{
                        break;
                    }
                }
                if(c == len){
                    cout << "ok" << endl;
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){
    int **A=new int *[3];
    int c=1;
    for(int i=0; i<3; i++){
        A[i]=new int [3];
        for(int j=0; j<3; j++){
            A[i][j]=c;
            c++;
        }
    }
}
/*[Esercizio 2] Scrivere un metodo che prenda in input un parametro formale matrice M di dimensioni n × m 
di puntatori
a stringhe, e che restituisca true se esiste almeno una colonna in M che abbia un egual numero di 
stringhe palindrome di una
delle righe di M.*/

#include <iostream>
#include <string>
#define n 3
#define m 3
using namespace std;

bool fun(string ***k){
    short arr1[m];
    short arr2[n];

    for(int j=0; j<m; j++){
        int count1=0;
        for(int i=0; i<n; i++){
            int low=0;
            int high=((*k[i][j]).length())-1;
            while(((*k[i][j])[low]==(*k[i][j])[high]) && (low<=high)){
                low++;
                high--;
            }
            if((*k[i][j])[low]==(*k[i][j])[high]){
                count1++;
            }
        }
        arr1[j]=count;
    }

    for(int i=0; i<n; i++){
        int count2=0;
        for(int j=0; j<m; j++){
            int low=0;
            int high=((*k[i][j]).length())-1;
            while(((*k[i][j])[low]==(*k[i][j])[high]) && (low<=high)){
                low++;
                high--;
            }
            if((*k[i][j])[low]==(*k[i][j])[high]){
                count2++;
            }
        }
        arr2[i]=count;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){ 
            if (arr1[i]==arr2[j]) return true;
        }
    }
    return false;

}

int main(){
    string ***l=new string **[n];

    for(int i=0; i<n; i++){
        l[i]=new string *[m];
        for(int j=0; j<m; j++){
            l[i][j]=new string("abba");
        }
    }

    cout<<fun(l);
}

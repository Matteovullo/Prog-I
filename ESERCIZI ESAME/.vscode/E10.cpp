/*[Esercizio 10] Scrivere un metodo che prenda in input un parametro formale matrice di stringhe A 
di dimensioni n × m,
una matrice di caratteri C di dimensioni k × z, uno short w e restituisca true se esiste almeno una 
riga o una colonna di A che
contiene almeno una sequenza contigua di w o piu’ caratteri che si trovano in una riga o in una colonna di C.*/

#include <iostream>
using namespace std;
#define n 3
#define m 3
#define k 3
#define z 3

bool fun(string **a, char **c, short w){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int l=0; l<m; l++){
                for(int g=0; g<a[i][j].length(); g++){
                    char o=a[i][j][g];
                    if(o==c[i][j]){
                        
                    }
                }
            }
        }
    }
}
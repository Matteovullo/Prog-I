/*13.Scrivere un metodo che prenda come parametri 
formali una matrice quadrata A n×n di puntatori a char 
e restituisca in output un bool che indichi se esiste una 
colonna in A identica alla diagonale principale di A. */

bool fun(char ***a,int n){

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(a[i][j] == a[i][i]) count++
        }
        if(count == n){
            valore=true;    
            break;
        }
    }
    return valore;
    
}
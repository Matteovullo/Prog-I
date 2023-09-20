/*21.Scrivere un metodo che prenda in input una 
matrice di double D ed un intero a, e restituisca il 
valore booleano true se esiste almeno una colonna in 
D nella quale la somma di una qualsiasi coppia di 
elementi adiacenti, approssimata all'intero piu vicino, 
sia uguale ad a. */

bool (double** a, int a){
    bool valore=false;
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(round(a[i][j]+a[i+1][j]) == a){
                valore=true;
                break;
            }
        }
        if(valore) break;
    }
    return valore;
}
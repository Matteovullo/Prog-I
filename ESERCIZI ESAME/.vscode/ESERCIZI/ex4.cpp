/*Esercizio 4] Scrivere un metodo che prenda in input due parametri formali: 
una matrice A di dimensioni n × m ed una
matrice B di dimensioni k × n entrambe di interi positivi. Il metodo restituisca un array 
C di double di dimensione n nel quale
lo i-esimo elemento dello array C sia uguale al rapporto tra la somma degli elementi della 
riga i-esima di A e il prodotto degli
elementi della colonna i-esima di B.*/

double fun(int **a, int n, int m, int k, int *b){
    double *c=new double [n];

    for(int i=0; i<n; i++){
        int somma=0;
        int prodotto=1;
        for(int j=0; j<n; j++){
            somma+=a[i][j]        
        }
        for(int y=0; y<k; y++){
            prodotto*=b[i][k];
        }
        c[i]=somma/(double)prodotto;
    }
    return c;
}
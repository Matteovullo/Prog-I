/*[Esercizio 13] Scrivere un metodo che preveda due parametri formali matrici di interi,
 A e B di dimensioni k × n ed
n × k rispettivamente, e restituisca uno array monodimensionale di k elementi double 
in cui lo i-esimo elemento sia uguale alla
differenza tra la media aritmetica degli elementi della riga i-esima di A ed il minimo 
valore degli elementi della colonna i-esima
di B.*/

double *fun(int **a, int **b, int n,int m, int k){
    double *c=new double [k];

    for(int i=0; i<k; i++){
        int somma=0;
        min=b[i][0];
        for(int j=0; j<n; j++){
            somma+=a[i][j];
            if(b[i][j] < min) min=b[i][j];
        }
        double media=somma/(double)n;
        c[i]=media-min;
    }
    return c;

}
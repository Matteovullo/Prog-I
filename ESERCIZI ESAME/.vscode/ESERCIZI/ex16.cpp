/*Esercizio 16]
Scrivere un metodo che prenda in input una matrice S di puntatori a stringhe di dimensione 
n × m ed un array B di short
di dimensione m e che restituisca uno short che rappresenti l’indice della riga 
in S con il maggior numero di stringhe aventi
lunghezza minore o uguale del corrispondente numero nello array B 
(NB: in pratica la lunghezza della stringa di indici (i,j) va
confrontata con il numero di indice j in B)*/

short fun(string ***s, int n, int m, short *b){
    int c[m];

    for(int i=0; i<n; i++){
        int count=0;
        for(int j=0; j<m; j++){
            if(s[i][j].length() <= b[j]) count++;
        }
        c[j]=count;
    }
    int count2=0;
    for(int i=o; i<n; i++){
        if( c[j]== 0) count2++;
    }
    if(count2 == m) return -1;
    
    int max=c[0];
    int index=0;
    for(int i=0; i<m; i++){
        if(c[i] > max){
            max=c[i];
            index=i;
        }
    }
    return index;

}
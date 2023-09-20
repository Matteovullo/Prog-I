/*Scrivere un metodo che prenda in input un parametro formale matrice di stringhe A 
di dimensioni n × m,
una matrice di caratteri C di dimensioni k × z, uno short w e restituisca true se 
esiste almeno una riga o una colonna di A che
contiene almeno una sequenza contigua di w o piu’ caratteri che si trovano in una riga o 
in una colonna di C*/

bool fun(string **A, char **C, int n, int m, int k, int z, short w){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int a=0; a<k; a++){
                for(int b=0; b<z; b++){
                    int count=0;
                    int h=0;
                    for(int y=b; y<z && h<A[i][j].length(); y++){
                        if(A[i][j][h] == C[a][y]) count ++;
                        else count = 0;
                        h++;
                        if(count>=w) return true;
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int b=0; b<z; b++){
                for(int a=0; a<k; a++){
                    int count=0;
                    int h=0;
                    for(int y=a; y<n && h<A[i][j].length(); y++){
                        if(A[i][j][h] == C[y][b]) count ++;
                        else count = 0;
                        h++;
                        if(count>=w) return true;
                    }
                }
            }
        }
    }

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            for(int a=0; a<k; a++){
                for(int b=0; b<z; b++){
                    int count=0;
                    int h=0;
                    for(int y=b; y<z && h<A[i][j].length(); y++){
                        if(A[i][j][h] == C[a][y]) count ++;
                        else count = 0;
                        h++;
                        if(count>=w) return true;
                    }
                }
            }
        }
    }

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            for(int b=0; b<z; b++){
                for(int a=0; a<k; a++){
                    int count=0;
                    int h=0;
                    for(int y=a; y<k && h<A[i][j].length(); y++){
                        if(A[i][j][h] == C[y][b]) count ++;
                        else count = 0;
                        h++;
                        if(count>=w) return true;
                    }
                }
            }
        }
    }
    return false;

}
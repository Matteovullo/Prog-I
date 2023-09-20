/*Scrivere un metodo che prenda in input un parametro formale matrice di stringhe A 
di dimensioni n × m,
una matrice di caratteri C di dimensioni k × z, uno short w e restituisca true se 
esiste almeno una riga o una colonna di A che
contiene almeno una sequenza contigua di w o piu’ caratteri che si trovano in una riga o 
in una colonna di C*/

bool fun(string **A, char **C, int n, int m, int k, int z, short w){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int a=0; a<n; k++){
                for(int b=0; b<z; z++){
                    int count=0;
                    int h=0;
                    for(int y=b; y<z && h<a[i][j].length(); y++){
                        if(a[i][j][h] == c[a][y]) count ++;
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
                for(int a=0; a<n; a++){
                    int count=0;
                    int h=0;
                    for(int y=a; y<n h<a[i][j].length(); y++){
                        if(a[i][j][h] == c[a][y]) count ++;
                        else count = 0;
                        h++;
                        if(count>=w) return true;
                    }
                }
            }
        }
    }

    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            for(int a=0; a<n; a++){
                for(int b=0; b<z; a++){
                    int count=0;
                    int h=0;
                    for(int y=b; y<z && h<a[i][j].length(); y++){
                        if(a[i][j][h] == c[a][y]) count ++;
                        else count = 0;
                        h++;
                        if(count>=w) return true;
                    }
                }
            }
        }
    }

    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            for(int b=0; b<z; b++){
                for(int a=0; a<n; a++){
                    int count=0;
                    int h=0;
                    for(int y=a; y<n && h<a[i][j].length(); y++){
                        if(a[i][j][h] == c[a][y]) count ++;
                        else count = 0;
                        h++;
                        if(count>=w) return true;
                    }
                }
            }
        }
    }

}
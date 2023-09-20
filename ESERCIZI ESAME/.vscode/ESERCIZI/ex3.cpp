/*[Esercizio 3] Scrivere un metodo che prenda in input tre parametri formali: 
una matrice di stringhe S di dimensioni n×m,
un array di caratteri C che contiene elementi distinti, ed un float w. Il metodo 
restituisca true se esiste almeno una riga o una
colonna della matrice tale che la percentuale di caratteri di C presenti in essa `e maggiore di w*/

bool fun(string s, int n, int m, char* c, float w){
    bool valore1=false;
    bool valore2=false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int count1=0;
            int count2=0;
            for(int k=0; k<a[i][j].length(); k++){
                char t=a[i][j][k];
                count1++;
                for(int y=0; y<r; y++){
                    if(t==c[y]) count2++;
                }
            }
        }
        if(count2/(double)count1 > w){
            valore=true;
            break;
        }
    }

    if(valore) return true;

    for(int j=0; j<m; j++){
        int count1=0;
        int count2=0;
        for(int i=0; i<n; i++){
            for(int k=0; k<a[i][j].length(); k++){
                char t=a[i][j][k];
                count1++;
                for(int y=0; y<r; y++){
                    if(t==c[y]) count2++;
                }
            }
        }
        if(count2/(double)count1 > w){
            valore2=true;
            break;
        }
    }

    if(valore2) return true;
    else return false;

}
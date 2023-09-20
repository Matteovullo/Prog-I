/*[Esercizio 7] Scrivere un metodo che prenda in input un parametro formale matrice S di 
puntatori a carattere di dimensione
n × m, uno short w ed uno short k, e restituisca il valore booleano true se in S sono 
presenti almeno una riga ed almeno una
colonna che presentano ciascuna almeno w stringhe di lunghezza minore di k.*/

bool fun (char ***S, int n, int m, short w, short k){
    bool valore=true;
    for(int i=0; i<n; i++){
        int count2=0;
        for(int j=0; j<m; j++){
            if(S[i][j]){
                int count1=0;
                while(S[i][j][count1] != '/0'){
                    count1++;
                }
            }
            if(count < k) count2++;
        }
        if( count2 >= w){
            valore=true;
            break;
        }
    }

    if(valore) return valore;

    for(int j=0; j<m; j++){
        int count2=0;
        for(int i=0; i<n; i++){
            int count1=0;
            if(S[i][j]){
                while(S[i][j][count1] != '/0'){
                    count++
                }
            }
            if(count < k) count2++;
        }
        if( count2 >= w){
            valore=true;
            break;
        }
    }

    return valore;
}
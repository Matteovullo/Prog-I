/*8.Scrivere un metodo che prenda in input una matrice 
quadrata di puntatori a stringhe Q ed una stringa s. Il 
metodo restituisca il valore booleano true se e solo se 
il numero di stringhe che contengono s, presenti nella 
diagonale principale di Q, e maggiore del numero di 
stringhe che contengono s presenti nella diagonale 
secondaria di Q.*/

bool fun(string ***a, string s){
    int c1=0;
    int c2=0;
    for(int i=0, j=n-1; i<n; i++,j--){
        if((*a[i][i]).find(s) != string::npos) c1++;
        if((*a[i][j]).find(s) != string::npos) c2++;
    }
    if(c1 > c2) return true;
    else return false;
}
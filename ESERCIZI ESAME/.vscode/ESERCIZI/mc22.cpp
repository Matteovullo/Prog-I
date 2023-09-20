/*22.Scrivere un metodo che prenda in input una 
matrice quadrata Q di stringhe e restituisca il valore 
booleano true se la stringa piu lunga della diagonale 
principale di Q contiene un numero di vocali minore 
della stringa piu corta della diagonale stessa. NB: Si 
assuma che le stringhe della diagonale principale 
abbiano lunghezze differenti e sempre maggiori di 
zero. */

bool fun(string** q){
    int count1=0;
    int count2=0;
    int max=a[0][0];
    string stringmax=a[0][0];
    int min=a[0][0];
    string stringmin=a[0][0];

    for(int i=0; i<n; i++){
        if(a[i][j].length() > max){
            max=a[i][i];
            stringmax=a[i][i];
        }
    }
    for(int i=0; i<n; i++){
        if(a[i][j].length() < min){
            min=a[i][i];
            stringmin=a[i][i];
        }
    }
    for(int i=0; i<stringmax.length(); i++){
        char c=stringmax[i];
        if(c='a' || c='e' || c='i' || c='o' || c='u' || c='A' || c='E' || c='I' || c='O' || c='U')
            count1++;
    }
    for(int i=0; i<stringmin.length(); i++){
        char c=stringmin[i];
        if(c='a' || c='e' || c='i' || c='o' || c='u' || c='A' || c='E' || c='I' || c='O' || c='U')
            count2++;
    }
    if(count1 < count2) return true;
    else return false;

}

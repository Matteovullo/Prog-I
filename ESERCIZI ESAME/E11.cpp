/*[Esercizio 11] Scrivere un metodo che preveda un parametro formale 
matrice di char di dimensione n × m ed un ulteriore
parametro intero a, e restituisca il valore booleano true se esiste 
almeno una riga o una colonna che contiene almeno a caratteri
che siano tutti minuscoli o tutti maiuscoli e che abbiano posizioni adiacenti. 

NB: Si assuma che la matrice contenga solo caratteri
corrispondenti alle lettere dell’alfabeto.*/

#define n 2
#define m 3

/*
 * a b c
 * D e F
 * g H i
*/

bool es11(char M[n][m], int a) {
    bool riga_trovata = false;
    for(int i=0; i<n && !riga_trovata; i++) { //scorro le righe
        for(int j=0; j<m && !riga_trovata; j++) {//scorro le colonne
            // mi dice qual è il case del primo carattere della sequenza che parte da j
            // se è upeercase upper sarà true, altrimenti false
            bool upper = isupper(M[i][j]);
            // inizializza la lunghezza della sequenza corrente (quella che parte da j)
            int len=0;
            // misuro la lunghezza della sequenza che parte da j
            for(int k=j; k<m; k++) {
                if(isupper(M[i][k])==upper) //ha lo stesso case del primo elemento?
                    len++; //incrementa la lunghezza
                else
                    break; //termina il for di misura
            }

            if(len>=a)
                riga_trovata = true;
        }
    }

    bool colonna_trovata = false;
    for(int j=0; j<m && !colonna_trovata; j++) { //scorro le colonne
        for(int i=0; i<n && !colonna_trovata; i++) {//scorro le righe
            bool upper = isupper(M[i][j]);
            int len=0;
            for(int k=i; k<n; k++) {
                if(isupper(M[k][j])==upper) //ha lo stesso case del primo elemento?
                    len++; //incrementa la lunghezza
                else
                    break; //termina il for di misura
            }

            if(len>=a)
                colonna_trovata=true;
        }
    }

    //almeno una riga e una colonna
    //return riga_trovata && colonna_trovata;
    //almeno una riga o una colonna
    return riga_trovata || colonna_trovata;


}
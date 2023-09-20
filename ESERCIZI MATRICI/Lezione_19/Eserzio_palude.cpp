/*Consideriamo una matrice int palude[R][C] riempita di 0 o 1
Cerchiamo un cammino ‘da sinistra a destra’ cioè dalla colonna 0 alla
colonna C-1
Assumiamo che siano possibili solo movimenti in avanti, cioè partendo dalla posizione <riga, colonna> ci si può spostare in
– <riga-1, colonna+1> (solo se la riga non è la prima)
– <riga, colonna+1>
– <riga+1, colonna+1> (solo se la riga non è l’ultima)
Memorizziamo il cammino costruito in un array int cammino[C] che
contiene gli indici delle righe corrispondenti ad ogni pezzo del
percorso.
Es, nel caso in figura il cammino sarà 1 2 3 3 3 2*/

#include <iostream>

using namespace std;

int *fun(int **palude, int n, int m){
    int *cammino=new int[m];
    int direzione1;
    int direzione2;

    for(int i=0; i<m; i++){
        cout << "Inserire direzione1: ";
        cin >> direzione1;
        cout << "Inserire direzione2: ";
        cin >> direzione2;

        if(palude[direzione1][direzione2] == 1)
            riga++;
            colonna++;

    }

}
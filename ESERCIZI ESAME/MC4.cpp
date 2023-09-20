/*
4.
Scrivere un metodo che prenda in input una matrice 
di puntatori a stringhe P di dimensioni nm, due short a 
e b, ed una stringa s. Il metodo restituisca il valore 
booleano true se esiste almeno una colonna in P tale 
che la stringa s sia sottostringa di un numero 
compreso tra a e b (inclusi) di stringhe della colonna 
stessa. PS: Si assuma 0 < a  b < n
*/

#include <iostream>
#include <string>

#define N 2
#define M 3

using namespace std;

bool func(string *M[][M], int, int, short, short, string);

int main()
{

    string *P[N][M],m;
    int x, y;

    cout << "La stringa Q ha " << N << " righe e " << M << " colonne" << endl;

    cout << "Riempi la matrice con stringhe:" << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> *P[i][j];
    }

    cout << "Inserisci una stringa: ";
    cin >> m;

    cout << "Inserisci i valori di x e y: ";
    cin >> x;
    cout << "\t";
    cin >> y;

    cout << func(P, N, M, x, y, m);
}

bool func(string *M[N][M], int r, int c, short a, short b, string s)
{
    int counter = 0;

    for (int j = 0; j < c; j++) //scorro colonne
    {

        for (int i = 0; i < r; i++) //scorro righe
        {
            if (s.find(M[j][i])) //find per ricerca/estrazione di sottostringhe
                counter++;
        }
        if ((counter > a )&& (counter < b))
            return true;
        counter=0;
    }
    return false;
}

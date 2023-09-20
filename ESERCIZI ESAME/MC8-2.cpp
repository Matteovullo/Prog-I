/*8.Scrivere un metodo che prenda in input una matrice
quadrata di puntatori a stringhe Q ed una stringa s. Il
metodo restituisca il valore booleano true se e solo se
il numero di stringhe che contengono s, presenti nella
diagonale principale di Q, e maggiore del numero di
stringhe che contengono s presenti nella diagonale
secondaria di Q*/

#include<iostream>
#include <string>
#define n 2
using namespace std;

string caricamento()
{
    string str_1=new string [n];
    for(int i=0; i<n; i++)
    {
        str_1[i]=new string *[n];
        for(int j=0; j<n; j++)
        {
            str_1[i][j]=new string [n];
        }
    }
    return str_1;
}
string *caricamento_cin(string Q_q)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>Q_q[i][j];
        }
    }
    return Q_q;
}
bool funzione_esercizio_9(string *Q, string s)
{
    int contatore=0;
    int contatore2=0;
    bool variabile_1=false;

    string s_prova;
    string s1_prova;
    for(int i=0; i<n; i++)
    {
        s_prova=Q[i][i];
        if(s_prova.find(s)==string::npos)
            contatore++;
    }
    for(int i=0; i<n; i++)
    {
        s1_prova=Q[i][n-i-1];
        if(s1_prova.find(s)==0)
            contatore2++;
    }
    if(contatore>contatore2)
        variabile_1=true;


    return variabile_1;

}

int main()
{
    string ***s_S=caricamento();
    caricamento_cin(s_S);
    cout<<funzione_esercizio_9(s_S,"ciao");

    return 0;
}
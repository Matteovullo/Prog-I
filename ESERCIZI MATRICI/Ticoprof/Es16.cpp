/*Data una matrice 5×5 verificare se la somma delle celle 
sopra la diagonale principale è maggiore della somma delle celle sotto la diagonale principale.*/

#include <iostream>

using namespace std;

int main(){
    int a[5][5];
    int c=0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = c;
            c++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int somma1=0, somma2=0;

    for(int i=0; i<5-1; i++){
        for(int j=i+1; j<5; j++){
            somma1+=a[i][j];
        }
    }

    for(int j=0; j<5-1; j++){
        for(int i=j+1; i<5; i++){
            somma2+=a[i][j];
        }
    }

    cout << "somma superiore: " << somma1 << endl;
    cout << "somma inferiore: " << somma2 << endl;
    
    if(somma1 > somma2)
        cout << "La somma delle celle sopra la diagonale principale è maggiore della somma delle celle sotto la diagonale principale" << endl;
    else
        cout << "La somma delle celle sopra la diagonale principale non è maggiore della somma delle celle sotto la diagonale principale" << endl;
}
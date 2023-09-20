/*Esercizio 1:
Scrivere un metodo che prenda in input due array A e B di long ed un array bidimensionale C di
long, e restituisca un boolean che indichi se esiste un elemento comune in A, B e C.*/

#include <iostream>

using namespace std;

bool fun(long *A, long *B, long **C, int n, int m, int k, int z)
{

    for (int i = 0; i < n; i++)
    {
        int l = A[i];
        for (int j = 0; j < m; j++)
        {
            if (l == B[i])
            {
                int g = B[i];
                for (int p = 0; p < k; p++)
                {
                    for (int h = 0; h < z; h++)
                    {
                        if (l == C[i][j] && g == C[i][j])
                            return true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    long *a = new long[3];
    for (int i = 0; i < 3; i++)
    {
        a[i] = 1;
    }

    long *b = new long[3];
    for (int i = 0; i < 3; i++)
    {
        b[i] = 1;
    }

    long **c = new long *[5];
    for (int i = 0; i < 3; i++)
    {
        c[i] = new long[4];
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = 1;
        }
    }

    cout << fun(a, b, c, 3, 3, 5, 4) << endl;
}
#include <iostream>

using namespace std;

bool esercizio17(int **A, int n, int m, double w, double v) {
    for(int j = 0; j < m; j++) {
        double somma = 0;
        for(int i = 0; i < n; i++) {
            somma += A[i][j];
        }
        somma /= n;
        if(somma >= w && somma <= v) return true;
    }
    return false;
}

int main() {

}
/*Si modifichi l’esercizio precedente rendendo get 
non statico e facendo si che il costruttore di Fibonacci 
prenda in input un intero n. Il metodo get restituirà dunque 
il numero corrente della successione elevato a n. 
Si crei un programma che costruisca due oggetti di tipo 
Fibonacci (con n=2 e n=3) e li si utilizzino per ottenere 
i numeri della successione.
Nota: get deve sempre restituire il numero successivo della 
successione, anche se chiamato da diverse istanze. Esempio:
Fibonacci f2(2);
Fibonacci f3(3);
f2.get(); //primo numero della successione elevato a 2
f3.get(); //secondo numero della successione elevato a 3*/

#include <iostream>
#include <cmath>
using namespace std;

class Fibonacci{
    private:
        static int c;
        static int f;
        int n;

    public:
        Fibonacci(int n){
            this->n=n;
        }
        void getF(){
            f=c+(c-1);
            c++;
        }
        int getC(){
            return pow(f, n);
        }
};

int Fibonacci::c=1;
int Fibonacci::f=0;

int main(){
    Fibonacci f2(2);
    Fibonacci f3(3);
    f2.getF();
    cout << f2.getC() << endl; //primo numero della successione elevato a 2
    f3.getF();
    cout << f3.getC() << endl; //secondo numero della successione elevato a 3
}


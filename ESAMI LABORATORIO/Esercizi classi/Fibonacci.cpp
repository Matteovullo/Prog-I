/*Si costruisca una classe Fibonacci con un metodo statico 
get che restituisca i numeri della successione di Fibonacci. 
Ogni volta che si chiama get, l’oggetto deve restituire un 
numero successivo. (Ad esempio se si richiama 5 volte get 
verranno restituiti i primi 5 numeri della successione).*/

#include <iostream>
using namespace std;

class Fibonacci{
    private:
        static int c;
        static int f;

    public:
        Fibonacci(){}
        static void getF(){
            f=c+(c-1);
            c++;
        }
        static int getC(){
            return f;
        }
};

int Fibonacci::c=1;
int Fibonacci::f=1;

int main(){
    Fibonacci f;
    f.getF();
    f.getF();
    f.getF();
    f.getF();
    f.getF();
    cout << f.getC() << endl;
}


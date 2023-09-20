#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

class Batteria{
    protected:
        int carica;
        int capacita;

    public:
        Batteria(int capacita){
            this->capacita=capacita;
            carica=100;
        }
        int getCarica(){
            return carica;
        }
        int getCapacita(){
            return capacita;
        }
        void uso(){
            carica--;
        }
        void uso(int i){
            carica=carica-i;
        }
};

class Cellulare{
    private:
        Batteria b;
 
    public:
        Cellulare(int capacita) : b(capacita){}
        void sms(){
            b.uso();
        }
        void chiamata(int i){
            int consumo=round(i/(double)5);
            b.uso(consumo);
        }
        int getCaricax(){
            return b.getCarica();
        }
};

int main(){
    Cellulare c(3000);
    c.sms();
    c.chiamata(20);
    cout << c.getCaricax();
}
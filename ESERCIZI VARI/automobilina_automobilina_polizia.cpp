#include <iostream>

using namespace std;

class Automobilina{
    protected:
        int carica;

    public:
        Automobilina(){
            carica=100;
        }
        void move(){
            carica--;
        }
};

class AutomobilinaPolizia : public Automobilina{
    public:
        AutomobilinaPolizia() : Automobilina(){}
        void sirena(){
            carica=carica-2;
        }
};
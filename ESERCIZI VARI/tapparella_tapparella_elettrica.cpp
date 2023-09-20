#include <iostream>

using namespace std;

class Tapparella{
    protected:
        int dimensione;
        int altezza;

    public:
        Tapparella(int i){
            dimensione=i;
            dimensione=100;
        }
        void su(int i){
            altezza=altezza-i;
        }
        void giu(int i){
            altezza=altezza+i;
        }
};

class TapparellaElettrica : public Tapparella{
    public:
        TapparellaElettrica(int i) : Tapparella(i){}
        void su(){
            altezza=0;
        }
        void giu(){
            altezza=100;
        }
};
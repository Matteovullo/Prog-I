#include <iostream>

using namespace std;

class Lampadina{
    private:
        int potenza;
        bool on_off;
        int luce=1;
    
    public:
        Lampadina(){
            on_off=false;
            luce=0;
        }
        void get(bool b){
            if(b)
                on_off=true;
            else
                on_off=true;
        }
        void regola(int i){
            if(i<=10)
                luce=i;
            else
                "Attenzione valore troppo alto";
        }
};

class LampadinaRegolabile : public Lampadina{
    private:
        int rosso;
        int verde;
        int blu;

    public:
        LampadinaRegolabile() : Lampadina(){}
        void regola_rosso(int i){
            if(i<=10)
                rosso=i;
        }
        void regola_verde(int i){
            if(i<=10)
                rosso=i;
        }
        void regola_blu(int i){
            if(i<=10)
                rosso=i;
        }
};
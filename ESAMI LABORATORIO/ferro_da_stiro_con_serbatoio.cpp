#include <iostream>

using namespace std;

class Serbatoio{
    private:
        int capienza;
        int capienza_max;

    public:
        Serbatoio(){
            capienza=0;
            capienza_max=100;
        }
        void riempi(){
            capienza=100;
        }
        void riempi(int i){
            capienza=capienza+i;
            if(capienza > capienza_max){
                int scarto=capienza-capienza_max;
                capienza=capienza-scarto;
            }
        }
        void estrarre(int i){
            capienza=capienza-i;
        }
        int getCapienza(){
            return capienza;
        }
};

class FerroDaStiro{
    private:
        int potenza;
        Serbatoio s;
        int ghiera;
        bool led1;
        bool led2;

    public:
        FerroDaStiro(int potenza) : s(){
            this->potenza=potenza;
            ghiera=0;
            led1=false;
            led2=false;
        }
        void getto(int i){
            ghiera=i;
            int consumo=(potenza/100)*ghiera;
            s.estrarre(consumo);
            ghiera=0;
            if(s.getCapienza() < 10 && s.getCapienza() != 0){
                led1=true;
            }
            if(led1==true){
                cout << "Attenzione liquido quasi terminato" << endl;
                led1=false;
            }
            if(s.getCapienza() == 0){
                led2=true;
            }
            if(led2==true){
                cout << "Attenzione liquido terminato" << endl;
                led2=false;
            }
        }
        int getPotenza(){
            return potenza;
        }
        void riempi(){
            s.riempi();
        }

};

int main(){
    FerroDaStiro f(10);
    f.getto(1);
    f.riempi();
    f.getto(5);
    f.getto(5);
    f.getto(5);
}
#include <iostream>

using namespace std;

class Portamonete{
    private:
        int cent_50;
        int euro_1;
        int euro_2;

    public:
        Portamonete(){
            cent_50=0;
            euro_1=0;
            euro_2=0;
        }
        Portamonete(int i1, int i2, int i3){
            cent_50=i1;
            euro_1=i2;
            euro_2=i3;
        }
        void inserisci(double valore){
            if(valore == 0.5)
                cent_50++;
            if(valore == 1)
                euro_1++;
            if(valore == 2)
                euro_2++;
        }
        void inserisci(double valore, int n){
            if(valore == 0.5)
                cent_50=cent_50+n;
            if(valore == 1)
                euro_1=euro_1+n;
            if(valore == 2)
                euro_2+=euro_2+n;
        }
        double denaro(){
            double d1=cent_50*0.5;
            double d2=euro_1*1;
            double d3=euro_2*2;
            return d1+d2+d3;
        }
};

class Portafoglio : public Portamonete{
    private:
        int euro_5, euro_10, euro_20;

    public:
        Portafoglio() : Portamonete(){
            euro_5=0;
            euro_10=0;
            euro_20=0;
        }
        Portafoglio(int i1, int i2, int i3){
            euro_5=i1;
            euro_10=i2;
            euro_20=i3;
        }
        void inserisci(double valore){
            if(valore == 5)
                euro_5++;
            if(valore == 10)
                euro_10++;
            if(valore == 20)
                euro_20++;
        }
        void inserisci(double valore, int n){
            if(valore == 5)
                euro_5=euro_5+n;
            if(valore == 10)
                euro_10=euro_10+n;
            if(valore == 20)
                euro_20+=euro_20+n;
        }
        double denaro(){
            double d1=euro_5*5;
            double d2=euro_10*10;
            double d3=euro_20*20;
            return d1+d2+d3;
        }
        void banconote(int i){
            if(i==5)
                cout << "Questa banconota vale 5 euro" << endl;
            if(i==10)
                cout << "Questa banconota vale 10 euro" << endl;
            if(i==20)
                cout << "Questa banconota vale 20 euro" << endl;
        }
};

int main(){
    return 0;
}
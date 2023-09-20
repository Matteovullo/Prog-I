#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

class Stereo{
    protected:
        int minutaggio;
        bool acceso_spento;
        bool riproduzione;

    public:
        Stereo(bool b1, bool b2){
            acceso_spento=b1;
            riproduzione=b2;
            minutaggio=0;
        }
        int getMinutaggio(){
            return minutaggio;
        }
        bool getAccesso_spento(){
            return acceso_spento;
        }
        bool getRiproduzione(){
            return riproduzione;
        }
        void on(){
            acceso_spento=true;
        }
        void start(bool b1, int i){
            if(b1){
                riproduzione=true;
                minutaggio+=i;
            }
        }
        void start(bool b1){
            if(b1){
                riproduzione=true;
            }
        }
        void skip(int i){
            minutaggio+=i;
        }
        void stampa(){
            cout << "Stereo ";
            if(acceso_spento){
                cout << "acceso" << "brano in riproduzione al minutaggio: " << minutaggio;
            }else{
                cout << "spento";
            }
        }
};

class StereoCD : public Stereo{
    private:
        string modalita;

    public:
        StereoCD(bool b1, bool b2, string modalita) : Stereo(b1, b2){
            this->modalita=modalita;
        }
        string mod(){
            return modalita;
        }
        void stampa(){
            cout << "StereoCD ";
            if(acceso_spento){
                cout << "acceso, brano in riproduzione al minutaggio: " << minutaggio << ", in modalità" << modalita;
            }else{
                cout << "spento";
            }
        }
};

int main(){
    StereoCD s(false, true, "cd");
    s.start(true);
    s.on();
    cout << s.getMinutaggio() << endl;
    cout << s.getAccesso_spento() << endl;
}
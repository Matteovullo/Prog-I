#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

class Carta{
    private:
        int numero;
        string seme;

    public:
        Carta(){
            numero=rand()%(10-1+1)+1;
            int r=rand()%(4-1+1)+1;
            if(r==1){
                seme="Oro";
            }
            if(r==2){
                seme="Coppe";
            }
            if(r==3){
                seme="Bastoni";
            }
            if(r==4){
                seme="Spade";
            }
        }
        int getCarte(){
            return numero;
        }
        string getSeme(){
            return seme;
        }
        void changen(int i){
            numero=i;
        }
        void changes(int i){
            int r=rand()%(4-1+1)+1;
            if(r==1){
                seme="Oro";
            }
            if(r==2){
                seme="Coppe";
            }
            if(r==3){
                seme="Bastoni";
            }
            if(r==4){
                seme="Spade";
            }
        }
        void stampa(){
            cout << "Numero: " << numero << ", seme: " << seme << endl;
        }
};

int main(){
    Carta array[5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(i!=j && array[i].getCarte() == array[j].getCarte() && array[i].getSeme() == array[j].getSeme()){
                array[i].changen(rand()%(10-1+1)+1);
                array[i].changes(rand()%(4-1+1)+1);
            }
        }
    }
    for(int i=0; i<5; i++){
        array[i].stampa();
    }
}
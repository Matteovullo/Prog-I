#include <iostream>

using namespace std;

class Giocatore{
    private:
        int gol_fatti;
        int numero_di_maglia;

    public:
        Giocatore(int numero_di_maglia){
            this->numero_di_maglia=numero_di_maglia;
            gol_fatti=0;
        }
        void gol(){
            gol_fatti++;
        }
        int getGol(){
            return gol_fatti;
        }
        int getNumero_di_maglia(){
            return numero_di_maglia;
        }
};

int main(){
    Giocatore array1[5]={1,2,3,4,5};
    Giocatore array2[5]={1,2,3,4,5};

    for(int i=0; i<10; i++){
        int r=rand()&(5-0+1)+0;
        int ra=rand()%(2-1+1)+1;
        if(ra==1)
            array1[r].gol();
        if(ra==2)
            array2[r].gol();
    }

    int max=0;
    int numMax=0;
    for(int i=0; i<5; i++){
        if(array1[i].getGol() > max){
            max=array1[i].getGol();
            numMax=array1[i].getNumero_di_maglia();
        }
    }

    for(int i=0; i<5; i++){
        if(array1[i].getGol() > max){
            max=array1[i].getGol();
            numMax=array1[i].getNumero_di_maglia();
        }
    }

    cout << "Max= " << max << ", numero maglia:" << numMax << endl;
}
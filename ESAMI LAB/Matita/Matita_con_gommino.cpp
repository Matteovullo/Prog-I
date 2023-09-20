#include <iostream>

using namespace std;

class Matita{
    private:
        int lunghezza;

    public:
        Matita(int lunghezza){
            this->lunghezza=lunghezza;
        }
        int GetLunghezza(){
            return lunghezza;
        }
        virtual void cancella()=0;
};

class MatitaConGommino : public Matita{
    private:
        int cancellature=10;

    public:
        MatitaConGommino(int lughezza) : Matita(lughezza){}
        int NumeroCancellature(){
            return cancellature;
        }
        void cancella(){
            if(cancellature > 0)
                cancellature--;
            else
                cout << "Cancellature finite";
        }

};

int main(){
    MatitaConGommino m2(15);
    m2.GetLunghezza();
    for(int i=0; i<11; i++)
        m2.cancella();
}
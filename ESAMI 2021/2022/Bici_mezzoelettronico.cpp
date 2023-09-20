#include <iostream>

using namespace std;

class MezzoElettronico{
    protected:
        double carica;
        double batteria_max;
        double consumo_chilometro;
        double chilometri_percorsi;

    public:
        MezzoElettronico(double batteria_max, double consumo_chilometro){
            this->batteria_max=batteria_max;
            this->consumo_chilometro=consumo_chilometro;
            carica=batteria_max;
            chilometri_percorsi=0;
        }
        double Batteria(){
            return carica;
        }
        double Chilometri(){
            return chilometri_percorsi;
        }
        virtual void uso(int i){
            carica=carica-(i*consumo_chilometro);
            chilometri_percorsi=chilometri_percorsi+i;
        }
};

class Bici : public MezzoElettronico{
    private:
        int dimenzione_ruote;
        int marcia;

    public:
        Bici(double batteria_max, double consumo_chilometro, int dimenzione_ruote) : MezzoElettronico(batteria_max, consumo_chilometro){}
        void uso(int i){

        }
        int numero_giri(int i){
            return i*100;
        }
        int getMarcia(){
            return marcia;
        }
};

class Ebike : public Bici{
    private:
        double chilometri_elettronici;
        double chilometri_tradizionale;

    public:
        Ebike(double batteria_max, double consumo_chilometro, int dimenzione_ruote) : Bici(batteria_max, consumo_chilometro, dimenzione_ruote){}
        double chilometri_e(){
            return chilometri_elettronici;
        }
        double chilometri_t(){
            return chilometri_tradizionale;
        }
        void uso(int i, string modalità){
            if(modalità == "Tradizionale"){
                chilometri_percorsi=chilometri_percorsi+i;
            }else if(modalità == "Elettrico"){
                carica=carica-(i*consumo_chilometro);
                chilometri_percorsi=chilometri_percorsi+i;
            }else{
                cout << "Modalità sbagliata, riprovare" << endl;
                /*do{
                    cout << "Inserire modalità: " << endl;
                    cin >> modalità;
                }while(modalità != "Tradizionale" || modalità != "Elettrica");*/
            }
        }
};

int main(){
    Ebike b1(100.00, 5, 3);
    cout << b1.Batteria() << endl;
}
#include <iostreaM>

using namespace std;

class Etichetta{
    protected:
        string tipo;
        int calorie;

    public:
        Etichetta(string tipo){
            this->tipo=tipo;
            if(tipo == "pera"){
                calorie=100;
            }
            if(tipo == "mela"){
                calorie=80;
            }
            if(tipo == "mirtillo"){
                calorie=50;
            }
        }
        int getCalorie(){
            return calorie;
        }
        string getTipo(){
            return tipo;
        }
};

class Bottiglia{
    private:
        Etichetta e;
        int capacita;
        int kc;

    public:
        Bottiglia(string s, int capacita) : e(s){
            this->capacita=capacita;
            kc=e.getCalorie()*capacita;
        }
        void stampa(){
            cout << "Bottiglia di succo di" << e.getTipo() << ", calorie:" << kc;
        }
};
 
int main(){
    Bottiglia b("pera", 2);
    b.stampa();
    return 0;
}
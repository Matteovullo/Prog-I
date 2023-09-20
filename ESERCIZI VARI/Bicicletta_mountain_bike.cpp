#include <iostream>

using namespace std;

class Bicicletta{
    private:
        int telaio;
        int velocita;

    public:
        Bicicletta(int telaio, int velocita){
            this->telaio=telaio;
            this->velocita=velocita;
        }
        void stampaStato(){
            cout << "Velocita " << telaio << "km/h";
        }
        int getVelocita(){
            return velocita;
        }
};

class MountainBike : public Bicicletta{
    private:
        int marcia1,marica2, marcie_max;

    public:
        MountainBike(int telaio, int velocita, int marcie_max) : Bicicletta(telaio, velocita){
            this->marcie_max=marcie_max;
        }
        void stampaStato(){
            cout << "velocita: " << getVelocita() << "km/h" << "-marce selettore 1" << marcie_max << "marcie selettore 2" << endl;
        }
};

int main(){
    return 0;
}
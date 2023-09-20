#include <iostream>

using namespace std;

class Barattolo{
    protected:
        int volume;
        int capienza;

    public:
        Barattolo(int volume){
            this->volume=volume;
            capienza=100;
        }
};

class Saliera : public Barattolo{
    private:
        int buchini;

    public:
        Saliera(int v, int buchini) : Barattolo(v){
            this->buchini=buchini;
        }
        void uso(){
            capienza=capienza-buchini;
        }
};
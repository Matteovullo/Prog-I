#include <iostream>

using namespace std;

class Arma{
    private:
        char tipo;
        int danno;

    public:
        Arma(char tipo, int danno){
            this->tipo=tipo;
            this->danno=danno;
        }
        int getDanno(){
            return danno;
        }
        void setTipo(char tipo){
            this->tipo=tipo;
        }
        void setDanno(int danno){
            this->danno=danno;
        }
};

class Personaggio{
    private:
        int ferita;
        int forza;
        Arma a;
        bool armato;

    public:
        Personaggio() : a(' ', 0){
            this->ferita=rand()%(50-20+1)+20;
            int somma=0;
            for(int i=0; i<3; i++){
                int r=rand()%(6-1+1)+1;
                somma+=r;
            }
            forza=somma;
            armato=false;
        }
        void armamento(Arma &a){
            this->a=a;
            armato=true;
        }
        void abbandona(){
            armato=false;
        }
        int puntiCombattimento(){
            return forza+a.getDanno();
        }
        int getDannol(){
            return a.getDanno();
        }
        void combattimento(Personaggio &p){
            if(puntiCombattimento() < p.puntiCombattimento()){
                int perdita=puntiCombattimento()-p.puntiCombattimento();
                if(perdita < a.getDanno())
                ferita=ferita-perdita;
            }else{
                int perdita=p.puntiCombattimento()-puntiCombattimento();
                if(perdita < p.getDannol())
                p.ferita=ferita-perdita;
            }
        }
};

int main(){
    Personaggio p1();
    Personaggio p2(p1);
    Personaggio p3();

    Arma a('a', 10);
    Arma b('b', 20);

    p1.armamento(a);
    p2.armamento(b);
    p3.armamento(a);



}
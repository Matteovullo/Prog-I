#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <climits>

#define DIM 15

using namespace std;

class Wheel{
        int value;
        int default_value;
        int num_faces;

    public:
        Wheel(int initial_value, int num_faces){
            this->value=initial_value;
            this->default_value=initial_value;
            this->num_faces=num_faces;
        }
        void rotate(int turns){
            value=value+turns;
            if(value > num_faces){
                value=value-num_faces;
            }
        }
        int getValue(){
            return value;
        }
        void reset(){
            this->value=default_value;
        }
};

class AbstractSlotMachine{
    protected:
        Wheel **wheels;
        int num_wheels;
        int prize;
        int num_spins;
        int num_wins;

    public:
        AbstractSlotMachine(int num_wheels, int num_faces){
            this->prize=0;
            this->num_spins=0;
            this->num_wins=0;
            this->num_wheels=num_wheels;
            this->wheels=new Wheel*[this->num_wheels];
            for(int i=0; i<num_wheels; i++){
                wheels[i]=new Wheel(rand()%(num_faces-1-0+1)+0, num_faces);
            }
        }
        virtual int spin()=0;
        int getPrize(){
            return prize;
        }
        double getWinRate(){
            return num_wins/(double)num_spins;
        }
        void reset(){
            for(int i=0; i<num_wheels; i++){
                wheels[i]->reset();
            }
        }

        virtual ostream &put(ostream &os){
            os << typeid(*this).name(); //...

            return os;
        }
};

ostream &operator<<(ostream &os, AbstractSlotMachine &obj){
    return obj.put(os);
}

class ThreeWheelsSlotMachine : public AbstractSlotMachine{
    private:
        int num_max;

    public:
        ThreeWheelsSlotMachine(): AbstractSlotMachine::AbstractSlotMachine(3, 6){
            this->num_max=0;
        }
        int spin(){
            for(int i=0; i<AbstractSlotMachine::num_wheels; i++){
                int c=0;
                AbstractSlotMachine::num_spins++;
                wheels[i]->Wheel::rotate(rand()%(10-3+1)+3);
                AbstractSlotMachine::prize+=wheels[i]->Wheel::getValue();
                if(AbstractSlotMachine::wheels[i] && AbstractSlotMachine::wheels[i+1]){
                    if(AbstractSlotMachine::wheels[i]->getValue() == AbstractSlotMachine::wheels[i+1]->getValue()){
                        AbstractSlotMachine::num_wins++;
                        return AbstractSlotMachine::prize;
                        AbstractSlotMachine::prize=0;
                    }
                    else if(AbstractSlotMachine::wheels[i]->getValue() != AbstractSlotMachine::wheels[i+1]->getValue()){
                        return 0;
                    }
                    else if(AbstractSlotMachine::wheels[i]->getValue()==6 && AbstractSlotMachine::wheels[i+1]->getValue()==10){
                        AbstractSlotMachine::prize*=2;
                        num_max++;
                        return AbstractSlotMachine::prize;
                    }
                }
            }
        }
        int getNumMax(){
            return num_max;
        }

        ostream &put(ostream &os){
            AbstractSlotMachine::put(os);
            os << ", num_wheels=" << AbstractSlotMachine::num_wheels << ", prize=" << prize << ", num_spins=" << num_spins << ", num_wins=" << num_wins << ", winrate=" << getWinRate() << ", num_max=" << num_max;
            return os;
        }
};

class TenWheelsSlotMachine : public AbstractSlotMachine{
    public:
        TenWheelsSlotMachine(): AbstractSlotMachine::AbstractSlotMachine(5, 10){}
        int spin(){
            for(int i=0; i<AbstractSlotMachine::num_wheels; i++){
                int somma=0;
                AbstractSlotMachine::num_spins++;
                wheels[i]->Wheel::rotate(rand()%(10-3+1)+3);
                if(i==0){
                    somma+=round((AbstractSlotMachine::num_spins/(double)3));
                    AbstractSlotMachine::prize+=somma;
                }
                else{
                    somma=somma+round((AbstractSlotMachine::num_spins/(double)3));
                    AbstractSlotMachine::prize+=wheels[i]->Wheel::getValue();
                    AbstractSlotMachine::prize=0;
                }
                if(AbstractSlotMachine::wheels[i] && AbstractSlotMachine::wheels[i+1]){
                    if(AbstractSlotMachine::wheels[i]->getValue() != AbstractSlotMachine::wheels[i+1]->getValue()){
                        AbstractSlotMachine::num_wins++;
                        return AbstractSlotMachine::prize;
                        AbstractSlotMachine::prize=0;
                    }else{
                        return 0;
                    }
                }
            }            
        }

        ostream &put(ostream &os){
            AbstractSlotMachine::put(os);
            os << ", num_wheels=" << AbstractSlotMachine::num_wheels << ", prize=" << prize << ", num_spins=" << num_spins << ", num_wins=" << num_wins << ", winrate=" << AbstractSlotMachine::getWinRate();
            return os;
        }
};

int main(){
    srand(424242);

    AbstractSlotMachine* vec[DIM];

    for (int i = 0; i < DIM; i++)
    {
        if (rand() % 2)
        {
            vec[i] = new ThreeWheelsSlotMachine();
        }
        else
        {
            vec[i] = new TenWheelsSlotMachine();
        }
    }

for(int i=0; i<DIM*100; i++) {
        vec[rand()%DIM]->spin();
        if(rand()%5==0)
        vec[rand()%DIM]->reset();
}

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vec[i] << endl;
    }

    //PUNTO 2
    cout << "PUNTO 2" << endl;
    double max=vec[0]->getWinRate();
    for(int i=0; i<DIM; i++){
        if(vec[i]->getWinRate() > max){
            max = vec[i]->getWinRate();
        }
    }
    cout << "Max=" << max << endl;

    //PUNTO 3
    cout << "PUNTO 3" << endl;
    int somma=0, c=0;
    for(int i=0; i<DIM; i++){
        if(typeid(vec[i]) == typeid(ThreeWheelsSlotMachine)){
            somma+=(dynamic_cast<ThreeWheelsSlotMachine*>(vec[i]))->getNumMax();
            c++;
        }
    }
    cout << "media=" << somma/(double)c;

}
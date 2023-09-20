#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 15

using namespace std;

class Wheel{
    private:
        int value;
        int default_value;
        int num_faces;

    public:
        Wheel(int initial_values, int num_faces){
            value=initial_values;
            default_value=initial_values;
            this->num_faces=num_faces;
        }
        /*void rotate(int turns){
            value=value+turns;
            if(value > num_faces){
                value=value-num_faces;
            }
        }*/
        void rotate(int turns) {
            value = (value + turns) % num_faces;
        }
        int getValue(){
            return value;
        }
        void reset(){
            value=default_value;
        }
};

class AbstractSlotMachine{
    protected:
        Wheel** wheels;
        int num_wheels;
        int prize;
        int num_spins;
        int num_wins;

    public:
        AbstractSlotMachine(int num_wheels, int num_faces){
            prize=0;
            num_spins=0;
            num_wins=0;
            this->num_wheels=num_wheels;
            wheels=new Wheel*[num_wheels];
            for(int i=0; i<num_wheels; i++){
                wheels[i]=new Wheel(rand()%(num_faces), num_faces);
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
                if(wheels[i]){
                    wheels[i]->reset();
                }
            }
        }
        virtual ostream &put(ostream &os){
        os << typeid(*this).name() << ", num_wheels=" << num_wheels << ", prize=" << prize << ", num_spins=" << num_spins << ", num_wins=" << num_wins << ", winrate=" << getWinRate();
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
        ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6){
            num_max=0;
        }
        /*int spin(){
            num_spins++;
            int somma=0;
            for(int i=0; i<num_wheels; i++){
                wheels[i]->rotate(rand()%(10-3+1)+3);
                somma+wheels[i]->getValue();
            }
            prize+=somma;
            if(wheels[0]->getValue()==wheels[1]->getValue() && 
                wheels[0]->getValue()==wheels[2]->getValue()){  
                if(wheels[0]->getValue()==5) {
                    prize *= 2;
                    num_max++;
                }
                num_wins++;
                int ret_prize = prize;
                prize = 0;
                return ret_prize;
            } else
                return 0;
        }*/
        int spin() {
            num_spins++;
            int vals[3];
            for(int i = 0; i < num_wheels; i++) {
                wheels[i]->rotate(rand()%8+3); // 3-10
                vals[i] = wheels[i]->getValue();
                prize += vals[i];
            }
            if (vals[0]==vals[1] && vals[0]==vals[2]) {
                if(vals[0]==5) {
                    prize *= 2;
                    num_max++;
                }
                num_wins++;
                int ret_prize = prize;
                prize = 0;
                return ret_prize;
            } else
                return 0;
        }
        int getNumMax(){
            return num_max;
        }
        ostream &put(ostream &os){
        AbstractSlotMachine::put(os);
        os << ", num_max=" << num_max;
        return os;
        }
};

class TenWheelsSlotMachine : public AbstractSlotMachine{
    public:
        TenWheelsSlotMachine() : AbstractSlotMachine(5 , 10){}
        /*int spin(){
            num_spins++;
            int aux=0;
            int somma=0;
            for(int i=0; i<num_wheels; i++){
                int num_turns=(rand()%(10-3+1)+3)+round(aux/3);
                wheels[i]->rotate((rand()%(10-3+1)+3)+round(aux/3));
                aux=num_turns;
                somma+=wheels[i]->getValue();
            }
            prize=prize+somma;
            bool duplicates=false;
            for(int i=0; i<num_wheels; i++){
                int aux=wheels[i]->getValue();
                for(int j=0; j<num_wheels; j++){
                    if(aux == wheels[j]->getValue() && i!=j){
                        duplicates=true;
                    }
                }
            }
            if (duplicates) {
                return 0;
            } else {
                num_wins++;
                int ret_prize = prize;
                prize = 0;
                return ret_prize;
            }
        }*/
        int spin() {
            num_spins++;
            int vals[10];
            int last_turns = 0;
            for(int i = 0; i < num_wheels; i++) {
                int num_turns = rand()%8+3 + round(last_turns/3);
                last_turns = num_turns;
                wheels[i]->rotate(num_turns);
                vals[i] = wheels[i]->getValue();
                prize += vals[i];
            }
            bool duplicates=false;
            for(int i=0; i<num_wheels; i++) {
                for(int j=i+1; j<num_wheels; j++) {
                    if(vals[i]==vals[j])
                        duplicates=true;
                }
            }
            if (duplicates) {
                return 0;
            } else {
                num_wins++;
                int ret_prize = prize;
                prize = 0;
                return ret_prize;
            }
        }
        ostream &put(ostream &os){
        AbstractSlotMachine::put(os);
        return os;
        }
};

int main(){
    AbstractSlotMachine **vec = new AbstractSlotMachine*[DIM];

    srand(424242);

    for(int i=0; i<DIM; i++) {
        if(rand()%2){
            vec[i] = new ThreeWheelsSlotMachine();
        } else {
            vec[i] = new TenWheelsSlotMachine();
        }
    }

    for(int i=0; i<DIM*100; i++) {
         vec[rand()%DIM]->spin();
         if(rand()%5==0)
            vec[rand()%DIM]->reset();
    }

    // PUNTO 1
    for (int i=0; i<DIM; i++) {
        cout << i+1 << ")" << *vec[i] << endl;
    }

    double max=vec[0]->getWinRate();
    int media=0;
    int c=0;
    for(int i=0; i<DIM; i++){
        if(vec[i]->getWinRate() > max){
            max = vec[i]->getWinRate();
        }
        if(typeid(*vec[i]) == typeid(TenWheelsSlotMachine)){
            media+=dynamic_cast<ThreeWheelsSlotMachine*>(vec[i])->getNumMax();
            c++;
        }
    }
    cout << "max win rate=" << max << endl;
    cout << "mean num max=" << media/(double)c;

    return 0;
}
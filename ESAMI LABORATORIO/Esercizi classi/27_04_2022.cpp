#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>
using namespace std;
#define DIM 15

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
        void rotate(int turns){
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
        Wheel **wheels;
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
                wheels[i]=new Wheel(rand()%num_faces, num_faces);
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
        virtual ostream& put(ostream& os){
            os << "Class=" << typeid(*this).name() << ", num_wheels=" << num_wheels << ", prize=" << prize << ", num_spins=" << num_spins << ", num_wins=" << num_wins << ", winrate=" << getWinRate();
            return os;
        }
}; 

ostream& operator<<(ostream& os, AbstractSlotMachine& obj){
    return obj.put(os);
}

class ThreeWheelsSlotMachine : public AbstractSlotMachine{
    private:
        int num_max;

    public:
        ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6){
            num_max=0;
        }
        int spin(){
            num_spins++;
            int val[3];
            for(int i=0; i<num_wheels; i++){
                wheels[i]->rotate(rand()%(10-3+1)+3);
                prize+=wheels[i]->getValue();
                val[i]=wheels[i]->getValue();
            }
            if(val[0] == val[1] && val[0] == val[2]){
                if(val[0]=5){
                    prize*=2;
                    num_max++;
                }
                num_wins++;
                int prizel=prize;
                prize=0;
                return prizel;
            }else{
                return 0;
            }
        }
        int getNumMax(){
            return num_max;
        }
        ostream& put(ostream& os){
            AbstractSlotMachine::put(os);
            os << ", num_max=" << num_max;
            return os;
        }
};

class TenWheelsSlotMachine : public AbstractSlotMachine{
    public:
        TenWheelsSlotMachine() : AbstractSlotMachine(5, 10){}
        int spin(){
            num_spins++;
            int valore=0;
            int val[10];
            for(int i=0; i<num_wheels; i++){
                valore+=rand()%(10-3+1)+3;
                wheels[i]->rotate(valore);
                prize+=wheels[i]->getValue();
                valore=round(valore/(3));
                val[i]=wheels[i]->getValue();
            }
            bool duplicati=false;
            for(int i=0; i<num_wheels; i++){
                for(int j=i+1; j<num_wheels; j++){
                    if(val[i] == val[j])
                        duplicati=true;
                }
            }
            if(duplicati){
                return 0;
            }else{
                num_wins++;
                int prizel=prize;
                prize=0;
                return prize;
            }
        }
        ostream& put(ostream& os){
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

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vec[i] << endl; 
    }

    cout << "PUNTO 2" << endl;
    double max=vec[0]->getWinRate();
    int media=0;
    int c=0;
    for(int i=0; i<DIM; i++){
        if(vec[i]->getWinRate() > max){
            max=vec[i]->getWinRate();
        }
        if(typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine)){
            media+=dynamic_cast<ThreeWheelsSlotMachine*>(vec[i])->getNumMax();
            c++;
        }
    }

    cout << "max win rate=" << max << endl; 
    cout << "PUNTO 3" << endl;
    cout << "mean num max=" << media/(double)c << endl;
    
}
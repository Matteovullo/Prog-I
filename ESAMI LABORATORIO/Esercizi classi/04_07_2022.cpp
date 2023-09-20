#include <iostream>
using namespace std;
#define DIM 7

int imput_dice[6]={1, 2, 3, 4, 5, 6};
string imput_coin[2]={"H","T"};

template<class T>
class AbstractRandomGenerator{
    protected:
        int num_values;
        int tossed;
        T accumulated_values;
        T value;
        T* values;

    public:
        AbstractRandomGenerator(T value, int num_values, T* imput_values){
            this->num_values=num_values;
            this->value=value;
            values=new T[num_values];
            for(int i=0; i<num_values; i++){
                values[i]=imput_values[i];
            }
            accumulated_values=value;
            tossed=0;
        }
        virtual T toss(){
            value=values[rand()%num_values];
            tossed++;
            accumulated_values+=value;
            return value;
        }
        T getValue(){
            return value;
        }
        int getTossed(){
            return tossed;
        }
        virtual void nudge()=0;
        virtual ostream& put(ostream& os){
            os << "Class" << typeid(*this).name() << ", values={";
            for(int i=0; i<num_values; i++){
                os << values[i] << " ";
            } 
            os << "}" << ", value=" << value << ", accumulated_value=" << accumulated_values << ", tossed=" << tossed;
            return os;
        }
};

template<class T>
ostream& operator<<(ostream& os, AbstractRandomGenerator<T>& obj){
    return obj.put(os);
}

class Dice : public AbstractRandomGenerator<int>{
    private:
        int doubles;

    public:
        Dice() : AbstractRandomGenerator(1, 6, new int[6]{1, 2, 3, 4, 5, 6}){
            doubles=0;
        }
        void nudge(){
            value=rand()%3-1;
            if(value > 6){
                value=6;
            }
            if(value < 1){
                value=1;
            }
        }
        double getDoubleRate(){
            return doubles/(double)tossed;
        }
        int toss(){
            int valuel=value;
            if(valuel == AbstractRandomGenerator<int>::toss()){
                doubles++;
            }
            return value;
        }
        ostream& put(ostream& os){
            AbstractRandomGenerator<int>::put(os);
            return os;
        }
};

class Coin : public AbstractRandomGenerator<string>{
    private:
        int nudge_prob;

    public:
        Coin(int nudge_prob) : AbstractRandomGenerator("H", 2, imput_coin){
            this->nudge_prob=nudge_prob;
        }
        void nudge(){
            int r=rand()%nudge_prob;
            if(r == 0){
                if(value == "H"){
                    value="T";
                }else{
                    value="H";
                }
            }
        }
        ostream& put(ostream& os){
            AbstractRandomGenerator<string>::put(os);
            return os;
        }
};

int main(){
    srand(424242);

    AbstractRandomGenerator<int>** vec1=new AbstractRandomGenerator<int>*[DIM];
    AbstractRandomGenerator<string>** vec2=new AbstractRandomGenerator<string>*[DIM];
 
	for(int i=0; i<DIM; i++) {
		vec1[i] = new Dice();
		vec2[i] = new Coin(rand()%10+1);
	}
 
    for(int i=0; i<100; i++) {
         vec1[rand()%DIM]->toss();
		 vec2[rand()%DIM]->toss();
         if(rand()%5==0) {
            vec1[rand()%DIM]->nudge();
			vec2[rand()%DIM]->nudge();
		 }
    }

    cout << "Punto 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i+1 << ")" << *vec1[i] << endl;
        cout << i+1 << ")" << *vec2[i] << endl;
     }

    cout << "Punto 2"  << endl;
    int min=vec2[0]->getTossed();
    double max=dynamic_cast<Dice*>(vec1[0])->getDoubleRate();
    for(int i=0; i<DIM; i++){
        if(vec2[i]->getTossed() < min){
            min=vec2[i]->getTossed();
        }
        if( dynamic_cast<Dice*>(vec1[i])->getDoubleRate() > max){
            max=dynamic_cast<Dice*>(vec1[i])->getDoubleRate();
        }
    }

    cout << "min tossed=" << min << endl;
    cout << "Punto 3" << endl;
    cout << "max double rate=" << max << endl;
}

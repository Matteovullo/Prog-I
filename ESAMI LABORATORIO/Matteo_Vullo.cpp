#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 7

using namespace std;

template<class T>
class AbstractRandomGenerator{
    protected:
        int num_values;
        int tossed;
        T accumulated_value;
        T value;
        T* values;

    public:
        AbstractRandomGenerator(T value, int num_values, T* input_values) {
            this->value=value;
            this->num_values=num_values;
            values=new T[num_values];
            for(int i=0; i<num_values; i++){
                values[i]=input_values[i];
            }
            accumulated_value=value;
            tossed=0;
        }
        virtual T toss(){
            value=values[rand()%num_values];
            tossed++;
            value+=accumulated_value;
            return value;
        }
        T getValue(){
            return value;
        }
        int getTossed(){
            return tossed;
        }
        virtual void nudge()=0;
        virtual ostream &put(ostream &os){
            os << typeid(*this).name() << ", values={";
            for(int i=0; i<num_values; i++){
                os << values[i] << " ";
            }
            os << "}" << ", value=" << value << ", accumulated_value=" << accumulated_value << ", tossed=" << tossed;
            return os;
        }
};

template<class T>
ostream &operator<<(ostream &os, AbstractRandomGenerator<T> &obj){
    return obj.put(os);
}

class Dice : public AbstractRandomGenerator<int>{
    private:
        int doubles;

    public:
        Dice(): AbstractRandomGenerator<int>(1, 6, new int[6]{1,2,3,4,5,6}){
            doubles=0;
        }
        void nudge(){
            AbstractRandomGenerator::value+=rand()%(3-1);
            int max=AbstractRandomGenerator::values[0];
            int min=AbstractRandomGenerator::values[0];
            for(int i=0; i<AbstractRandomGenerator::num_values; i++){
                if(AbstractRandomGenerator::values[i] > max){
                    max =AbstractRandomGenerator::values[i];
                }
                if(AbstractRandomGenerator::values[i] < min){
                    min =AbstractRandomGenerator::values[i];
                }
            }
            if(AbstractRandomGenerator::value > max){
                AbstractRandomGenerator::value=max;
            }
            if(AbstractRandomGenerator::value < min){
                AbstractRandomGenerator::value=min;
            }
        }
        int toss(){
            int i=AbstractRandomGenerator::toss();
            if(i == AbstractRandomGenerator::getValue()){
                doubles++;
            }
            return AbstractRandomGenerator::getValue();
        }
        double getDoubleRate(){
            return (double)doubles/AbstractRandomGenerator::tossed;
        }
        ostream &put(ostream &os){
            AbstractRandomGenerator::put(os);
            return os;
        }
};

class Coin : public AbstractRandomGenerator<string>{
    private:
        int nudge_prob;

    public:
        Coin(int nudge_prob) : AbstractRandomGenerator::AbstractRandomGenerator("H", 2, new string[2]{"H", "T"}){
            this->nudge_prob=nudge_prob;
        }
        void nudge(){
            int r=rand()%nudge_prob;
            if(r == 0){
                if(AbstractRandomGenerator::value == "H"){
                    AbstractRandomGenerator::value="T";
                }else{
                    AbstractRandomGenerator::value="H";
                }
            }
        }
        ostream &put(ostream &os){
            AbstractRandomGenerator::put(os);
            return os;
        }
};

int main(){
    srand(424242);
    AbstractRandomGenerator<int>* vec1[DIM];
    AbstractRandomGenerator<string>* vec2[DIM];
 
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


    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vec1[i] << endl;
        cout << i << ")" << *vec2[i] << endl;
    }
}
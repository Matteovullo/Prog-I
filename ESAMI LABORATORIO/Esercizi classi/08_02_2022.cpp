#include <iostream>
#include <typeinfo>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;
#define DIM 10

class AbstractRandomVec{
    protected:
        int* vec;
        int num;

    public:
        AbstractRandomVec(int n, int min, int max){
            num=n;
            vec=new int[num];
            for(int i=0; i<num; i++){
                vec[i]=rand()%(max-min+1)+min;
            }
        }
        int* get(int i){
            if(i < num-1)
                return &vec[i];
            else 
                return nullptr;
        }
        int numel(){
            return num;
        }
        float mean(){
            float somma=0.0;
            for(int i=0; i<num; i++){
                somma+=vec[i];
            }
            return somma/num;
        }
        virtual int count()=0;
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", num=" << num << ", vec=[";
            for(int i=0; i<num; i++){
                os << vec[i] << " ";
            }
            os << "]";
            return os;
        }
};

ostream& operator<<(ostream& os, AbstractRandomVec& obj){
    return obj.put(os);
}

class TernaryVec : public AbstractRandomVec{
    public:
        TernaryVec(int n) : AbstractRandomVec(n, 0, 2){}
        int count(){
            int c=0;
            for(int i=0; i<num; i++){
                if(vec[i]>0)
                    c++;
            }
            return c;
        }
        ostream& put(ostream& os){
            AbstractRandomVec::put(os);
            return os;
        }
};

class MultVec : public AbstractRandomVec{
    private:
        double midpoint;

    public:
        MultVec(int n, int min, int max, int mul) : AbstractRandomVec(n, min, max){
            midpoint=(min+max)/(double)2;
            for(int i=0; i<num; i++){
                int r=0;
                do{
                    r=rand()%(max-min+1)+min;
                }while(r%mul!=0);
                vec[i]=r;
            }
            /*int i = 0;
            do {
                int gen = rand() % (max - min + 1) + min;
                if (gen % mul == 0) {
                    vec[i++] = gen;
                }
            } while(i < num);*/
        }
        int count(){
            int c=0;
            for(int i=0; i<num; i++){
                if(vec[i] > midpoint)
                    c++;
            }
            return c;
        }
        int countEven(){
            int c=0;
            for(int i=0; i<num; i++){
                if(vec[i]%2==0)
                    c++;
            }
            return c;
        }
        ostream& put(ostream& os){
            AbstractRandomVec::put(os);
            os << ", midpoint=" << midpoint;
            return os;
        }
};

int main(){
    srand(424242);

    AbstractRandomVec* vett[DIM];

    for (int i = 0; i < DIM; i++){
        int n = 5 + rand() % 5;
        int m = 5 + rand() % 5;
        int min = rand() % 10 + 5;
        int max = min + rand() % 20;

        switch (rand() % 2){
        case 0:
            vett[i] = new TernaryVec(n);
            break;
        case 1:
            vett[i] = new MultVec(n, min, max, m);
        }
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vett[i] << endl;
    }

    cout << "PUNTO 2" << endl;
    int max=vett[0]->count();
    int media=0;
    int c=0;
    for(int i=0; i<DIM; i++){
        if(vett[i]->count() > max){
            max = vett[i]->count();
        }
        if(typeid(*vett[i]) == typeid(MultVec)){
            media+=dynamic_cast<MultVec*>(vett[i])->countEven();
            c++;
        }
    }
    cout << "max count(): " << max << endl;
    cout << "PUNTO 3" << endl;
    cout << "mean countEven():" << media/(double)c << endl;
}
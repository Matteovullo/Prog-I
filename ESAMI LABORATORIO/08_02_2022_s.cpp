#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

class AbstractRandomVec{
    protected:
        int* vec;
        int num;

    public:
        AbstractRandomVec(int n, int min, int max){
            vec=new int[n];
            for(int i=0; i<n; i++){
                vec[i]=rand()%(max-min+1)+min;
            }
            this->num=n;
        }
        virtual int count()=0;
        int* get(int i){
            if(i < num){
                int *ptr;
                *ptr=vec[i];
                return ptr;
            }else{
                return nullptr;
            }
        }
        int numel(){
            return num;
        }
        float mean(){
            float media=0.0;
            for(int i=0; i<num; i++){
                media+=vec[i];
            }
            return media/num;
        }
        virtual ostream &put(ostream &os){
        os << typeid(*this).name() << ", num=" << num << ", vec=[";
        for(int i=0; i<num; i++){
            os << vec[i] << " ";
        }
        os << "]";
        return os;
        }
};

ostream &operator<<(ostream &os, AbstractRandomVec &obj){
    return obj.put(os);
}

class TernaryVec : public AbstractRandomVec{
    public:
        TernaryVec(int n) : AbstractRandomVec(n, 0, 2){}
        int count(){
            int c=0;
            for(int i=0; i<num; i++){
                if(vec[i]>0){
                    c++;
                }
            }
            return c;
        }
        ostream &put(ostream &os){
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
            for(int i=0; i<n; i++){
                int r=0;
                do{
                    r=rand()%(max-min+1)+min;
                }while(r%mul!=0);
                vec[i]=r;
            }
            num=n;
        }
        int count(){
            int c=0;
            for(int i=0; i<num; i++){
                if(vec[i]>midpoint){
                    c++;
                }
            }
            return c;
        }
        int countEven(){
            int c=0;
            for(int i=0; i<num; i++){
                if(vec[i]%2 == 0){
                    c++;
                }
            }
            return c;
        }
        ostream &put(ostream &os){
        AbstractRandomVec::put(os);
        os << ", midpoint=" << midpoint;
        return os;
        }
};

int main(){
    srand(424242);
    const int DIM = 10;

    AbstractRandomVec* vett[DIM];

    for(int i=0; i<DIM; i++) {
        int n=5+rand()%5;
        int m=5+rand()%5;
        int min = rand()%10 + 5;
        int max = min + rand()%20;

        switch(rand()%2) {
            case 0: {
                vett[i]= new TernaryVec(n);
                break;
            }
            case 1: {
                vett[i]= new MultVec(n, min, max, m);
            }
        }
    }
    
    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vett[i]<< endl;
    }
     
    int max = INT_MIN;
    for(int i = 0; i < DIM; i++) {
        if(typeid(*vett[i]) == typeid(TernaryVec)) {
            if(max < ((TernaryVec*)vett[i])->count()) {
                max = ((TernaryVec*)vett[i])->count();
            }
        }
        else {
            if(max < ((MultVec*)vett[i])->count()) {
                max = ((MultVec*)vett[i])->count();
            }
        }
    }
    
    //int max=INT_MIN;
    int media=0;
    int c=0;
    for(int i=0; i<DIM; i++){
        /*if(vett[i]->count() > max){
            max = vett[i]->count();
        }*/
        if(typeid(*vett[i]) == typeid(MultVec)){
            media+=dynamic_cast<MultVec*>(vett[i])->countEven();
            c++;
        }
    }

    cout << "PUNTO 2" << endl;
    cout << "Max count()=" << max << endl; 
    cout << "PUNTO 3" << endl;
    cout << "Avg(countEven())=" << media/(double)c << endl;
    return 0;
}

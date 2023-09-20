#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 10

using namespace std;

template<class T>
class AbstractVec{
    private:
        T** data;

    protected:
        int max_size;
        int read_index;
        int write_index;
        T* get(int index){
            return data[index];
        }
        bool exists(int index){
            if(data[index])
                return true;
            else
                return false;
        }
        void set(int i, T x){
            if(data[i])
                *data[i]=x;
            else
                data[i]=new T(x);
        }

    public:
        AbstractVec(int max_size){
            this->max_size=max_size;
            write_index=0;
            read_index=0;
            data=new T*[max_size];
            for(int i=0; i<max_size; i++){
                data[i]=nullptr;
            }
        }
        virtual T* next()=0;
        virtual bool insert(T x)=0;
        int len(){
            int c=0;
            for(int i=0; i<max_size; i++){
                if(data[i])
                    c++;
            }
            return c;
        }
        /*void shuffle(){
            for(int i=0; i<max_size; i++){
                T tmp;
                if(data[i]){
                    tmp=*data[i];
                    int index=-1;
                    while(i==index && data[index]){
                        index=rand()%(max_size - 0 + 1)+1;
                    }
                *data[i]=*data[index];
                *data[index]=tmp;
                }
            }
        }*/
        void shuffle() {
            for(int i = 0; i < max_size; i++) {
                if(data[i]) {
                    T* tmp = nullptr;
                    int index = 0;
                    while(tmp == nullptr || tmp == data[i]) {
                        index = rand() % max_size;
                        tmp = data[index];
                    }
                    data[index] = data[i];
                    data[i] = tmp;
                }
            }
        }
        double mean(){
            int c=0;
            int media=0;
            for(int i=0; i<max_size; i++){
                if(data[i]){
                    c++;
                    media+=*data[i];
                }
            }
            return media/(double)c;
        }
        virtual ostream &put(ostream &os){
            os << typeid(*this).name() << ", max_size=" << max_size << ", vec=[";
            for(int i=0; i<max_size; i++){
                if(data[i])
                    os << *data[i] << " ";
            }
            os << "]" << "len()=" << len() << ", mean()=" << mean();
        return os;
        }
};

template<class T>
ostream &operator<<(ostream &os, AbstractVec<T> &obj){
    return obj.put(os);
}

template<class T>
class PlainVec : public AbstractVec<T>{
    public:
        PlainVec(int max_size) : AbstractVec<T>::AbstractVec(max_size){}
        T* next(){
            if(AbstractVec<T>::read_index <= AbstractVec<T>::max_size-1)
                return AbstractVec<T>::get(AbstractVec<T>::read_index++);
            else
                return nullptr;
        }
        bool insert(T x){
            if(AbstractVec<T>::write_index <= AbstractVec<T>::max_size-1){
                AbstractVec<T>::set(AbstractVec<T>::write_index, x);
                AbstractVec<T>::write_index++;
                return true;
            }else{
                return false;
            }
        }
        ostream &put(ostream &os){
            AbstractVec<T>::put(os);
            return os;
        }
};

template<class T>
class CircularVec : public AbstractVec<T>{
    private:
        int cycles;

    public:
        CircularVec(int max_size) : AbstractVec<T>::AbstractVec(max_size){
            cycles=0;
        }
        T* next(){
            int tmp=AbstractVec<T>::read_index;
            AbstractVec<T>::read_index++;
            if(AbstractVec<T>::read_index == AbstractVec<T>::max_size){
                AbstractVec<T>::read_index=0;
                cycles++;
            }
            return AbstractVec<T>::get(AbstractVec<T>::read_index);
        }
        bool insert(T x){
            AbstractVec<T>::set(AbstractVec<T>::write_index, x);
            AbstractVec<T>::write_index++;
            if(AbstractVec<T>::write_index == AbstractVec<T>::max_size){
                AbstractVec<T>::read_index=0;
                cycles++;
            }
            return true;
        }
        int getCycles(){
            return cycles;
        }
        ostream &put(ostream &os){
            AbstractVec<T>::put(os);
            os << ", cycles=" << cycles;
            return os;
        }
};

int main(){
    srand(424242);

    AbstractVec<int>* vec[DIM];

    for(int i=0; i<DIM; i++) {
        int size = rand()%16+5;
        if(rand()%2){
            vec[i] = new PlainVec<int>(size);
        } else {
            vec[i] = new CircularVec<int>(size);
        }
    }

    for(int i=0; i<DIM*5; i++) {
        int x = rand()%100;
        vec[x%DIM]->insert(x);
    }

    for(int i=0; i<DIM; i++)
        vec[i]->shuffle();
    
    for(int i = 0; i < DIM; i++) {
        cout << *vec[i] << endl;
    }

    int min=INT_MAX;
    double max=INT_MIN;
    for(int i=0; i<DIM; i++){
        if(vec[i]->len() < min)
            min = vec[i]->len();
        if(typeid(*vec[i]) == typeid(PlainVec<int>)){
            if(dynamic_cast<PlainVec<int>*>(vec[i])->mean() > max){
                max = dynamic_cast<PlainVec<int>*>(vec[i])->mean();
            }
        }
    }

    cout << "min_len=" << min << endl;
    cout << "max_mean_plainVec=" << max << endl;
}
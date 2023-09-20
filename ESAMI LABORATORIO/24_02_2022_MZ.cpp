#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>
#include <cmath>
#include <typeinfo>
#define DIM 10

using namespace std;

template <class T>
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
        bool exists(index int){
            if(data[index]){
                return true;
            }
        }
        void set(int i, T x){
            if(data[i])
                *data[i]=x;
            else
                data[i]=new T(x);

        }

    public:
        AbstractVec(int max_size){
            data=new T*[max_size];
            for(int i=0; i<max_size; i++){
                data[i]=nullptr;
            }
            this->max_size=max_size;
            read_index=0;
            write_index=0;
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
        void shuffle(){
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
        double mean() {
            double somma = 0;
            int count = 0;
            for(int i = 0; i < max_size; i++) {
                if(data[i]) {
                    somma += *data[i];
                    count++;
                }
            }
            return somma / count;
        }


        virtual ostream& put(ostream& os) {
        os << "Class=" << typeid(*this).name() << ", max_size=" << max_size << ", vec=[";
            for(int i = 0; i < len; i++){
                if(data[i])
                    os << *data[i] << " ";
                else
                    os << "* "
            }
            os << "], len()=" << len() << ", mean=" << mean();
            return os;
        }

};

template <class T>
class PlainVec: public AbstractVec{
    public:
        PlainVec(int max_size): AbstractVec::AbstractVec(max_size){}
        T* next(){
            if(AbstractVec<T>::read_index <= AbstractVec<T>::max_size-1){
                return AbstractVec<T>::get(AbstractVec<T>::read_index++);
            }
            return nullptr;
        }
        bool insert(T x){
            if(AbstractVec<T>::write_index <= AbstractVec<T>::max_size-1){
                AbstractVec<T>::set(AbstractVec<T>::write_index++, x)
                return true;
            }
            return false;
        }
        double mean() {
            double somma = 0;
            int count = 0;
            for(int i = 0; i < max_size; i++) {
                if(data[i]) {
                    somma += *data[i];
                    count++;
                }
            }
            return somma / count;
        }
        ostream& put(ostream& os) {
            AbstractVec<T>::put(os);
            return os;
        }
};

template <class T>
class CircularVec: public AbstractVec{
    private:
        int cycles;

    public:
        CircularVec(int max_size): AbstractVec::AbstractVec(max_size){
            cycles=0;
        }
        T* next(){
            T* tmp = AbstractVec<T>::get(AbstractVec<T>::read_index++);
            if(AbstractVec<T>::read_index == AbstractVec<T>::max_size) {
                AbstractVec<T>::read_index = 0;
                cycles++;
            }
            return tmp;
        }
        bool insert(T x){
            AbstractVec<T>::set(AbstractVec<T>::write_index++, x);
            if(AbstractVec<T>::write_index==AbstractVec::len()){
                AbstractVec<T>::write_index=0;
                cycles++;
            }
            return true;
        }
        int getCycles(){
            return cycles;
        }
        ostream& put(ostream& os) {
            AbstractVec<T>::put(os);
            os << ", cycles=" << cycles;
            return os;
        }
};

template<class T>
ostream& operator<<(ostream& os, AbstractVec<T>& obj) {
    return obj.put(os);
}

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

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vec[i] << endl;
    }

    cout << "PUNTO 2" << endl;
    int min=vec[0]->len();
    for(int i=0; i<DIM; i++){
        if(vec[i]->len() < min) min=vec[i]->len();
    }

    cout << "Min=" << min << endl;

    cout << "PUNTO 3" << endl;
    int max=INT_MIN;
    for(int i=0; i<DIM; i++){
    if(typeid(PlainVec<int>) == typeid(*vec[i])) {
        double m = ((PlainVec<int>*)(vec[i]))->mean();
        if(max < m) max = m;
    }
    
    cout << "min_len=" << min << endl;
    cout << "max_mean_plainVec=" << max << endl;
}
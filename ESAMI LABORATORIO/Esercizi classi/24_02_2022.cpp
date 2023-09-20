#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <climits>
#include <cmath>
using namespace std;
#define DIM 10

template<class T>
class AbstractVec{
    private:
        T **data;

    protected:
        int max_size;
        int read_index;
        int write_index;
        T* get(int index){
            if(index < max_size)
                return data[index];
            else
                return nullptr;        
        }
        bool exists(int index){
            if(index < max_size-1 && data[index])
                return true;
            else
                return false;
        }
        void set(int i, T x){
            if(i < max_size && data[i]){
                *data[i]=x;
            }else{
                data[i]=new T(x);
            }
        }

    public:
        AbstractVec(int max_size){
            this->max_size=max_size;
            read_index=0;
            write_index=0;
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
        void shuffle(){
            for(int i=0; i<max_size; i++){
                if(data[i]){
                    T* aux=data[i];
                    int r;
                    do{
                        r=rand()%max_size;
                    }while(data[r]);
                    data[i]=data[r];
                    data[r]=aux;
                }
            }
        }
        double mean(){
            int c=0;
            double somma=0.0;
            for(int i=0; i<max_size; i++){
                if(data[i]){
                    c++;
                    somma+=*data[i];
                }
            }
            return somma/c;
        }
        virtual ostream& put(ostream& os){
            os << "Class=" << typeid(*this).name() << ", max_size=" << max_size << ", vec=[";
            for(int i=0; i<max_size; i++){
                if(data[i])
                    os << *data[i] << " "; 
            }
            os << "], len()=" << len() << ", mean()=" << mean();
            return os;
        }
};

template<class T>
ostream& operator<<(ostream& os, AbstractVec<T>& obj){
    return obj.put(os);
}

template<class T>
class PlainVec : public AbstractVec<T>{
    public:
        PlainVec(int max_size) : AbstractVec<T>(max_size){}
        T* next(){
            if(AbstractVec<T>::read_index < AbstractVec<T>::max_size){
                int read=AbstractVec<T>::read_index;
                AbstractVec<T>::read_index++;
                return AbstractVec<T>::get(read);
            }else{
                return nullptr;
            }
        }
        bool insert(T x){
            if(AbstractVec<T>::write_index < AbstractVec<T>::max_size){
                AbstractVec<T>::set(AbstractVec<T>::write_index, x);
                AbstractVec<T>::write_index++;
                return true;
            }else{
                return false;
            }
        }
        ostream& put(ostream& os){
            AbstractVec<T>::put(os);
            return os;
        }
};

template<typename T>
class CircularVec : public AbstractVec<T>{
    private:
        int cycles;

    public:
        CircularVec(int max_size) : AbstractVec<T>(max_size){
            cycles=0;
        }
        T* next(){
            int read=AbstractVec<T>::read_index;
            AbstractVec<T>::read_index++;
            if(AbstractVec<T>::read_index == AbstractVec<T>::max_size){
                cycles++;
                AbstractVec<T>::read_index=0;
            }
            return AbstractVec<T>::get(read);
        }
        bool insert(T x){
            AbstractVec<T>::set(AbstractVec<T>::write_index, x);
            AbstractVec<T>::write_index++;
            if(AbstractVec<T>::write_index == AbstractVec<T>::max_size){
                AbstractVec<T>::write_index=0;
                cycles++;
            }
            return true;
        }
        int getCycles(){
            return cycles;
        }
        ostream& put(ostream& os){
            AbstractVec<T>::put(os);
            os << ", cycles=" << cycles;
            return os;
        }
};

int main(){
    srand(424242);

    AbstractVec<int>* vec[DIM];
    
    for (int i = 0; i < DIM; i++){
        int size = rand() % 16 + 5;
        if (rand() % 2){
            vec[i] = new PlainVec<int>(size);
        }else{
            vec[i] = new CircularVec<int>(size);
        }
    }

    for (int i = 0; i < DIM * 5; i++){
        int x = rand() % 100;
        vec[x % DIM]->insert(x);
    }

    for (int i = 0; i < DIM; i++)
        vec[i]->shuffle();

    cout << "Punto 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vec[i] << endl;
    }

    cout << "Punto 2" << endl;
    int min=vec[0]->len();
    double max=vec[1]->mean();
    for(int i=0; i<DIM; i++){
        if(vec[i]->len() < min){
            min = vec[i]->len();
        }
        if(typeid(*vec[i]) == typeid(PlainVec<int>)){
            if(dynamic_cast<PlainVec<int>*>(vec[i])->mean() > max){
                max = dynamic_cast<PlainVec<int>*>(vec[i])->mean();
            }
        }
    }

    cout << "Minimo len():" << min << endl;
    cout << "Punto 3" << endl;
    cout << "Massimo mean():" << max << endl;
}
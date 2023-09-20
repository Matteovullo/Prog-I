#include <iostream>
#include <typeinfo>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;
#define DIM 50

class A{
    private:
        short *arr;
        short len;
    
    public:
        A(short m){
            len=m;
            arr=new short[len];
            for(int i=0; i<len; i++){
                arr[i]=rand()% 10 + 1;
            }
        }
        virtual double f(short k)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os)=0;

    protected:
        short get(short i){
            return arr[i%len];
        }
};

ostream operator<<(,A& obj){
    return obj.put(os);
}

template <class T>
class B: public A{
    private:
        T x;

    public:
        B(short m, char c) : A::A(m){
            if(typeid(x)==typeid(char))
                x=c;
            else{
                string tmp="";
                for(int i=0; i<m; i++){
                    tmp+=c;
                }
                x=tmp;
            }
        }
        double f(short a){
            int count=0;
            double media=0;
            for(int i=a%A::getLen(); i<A::getLen(); i++){
                media+=A::get(i);
                count++;
            }
            return media/(double)count;
        }

        double foo(short s){
            return log(s)+sin(f(s));
        }

        ostream& put(ostream& os){
            if(typename(x)==typename(char))
                cout << "B<char> ";
            
            os << typenid(*this).name() << " arr[";
            for(int i=0; i<A::getLen(); i++){
                os << A::get(i) << " ";
            }
            os << "], x=" << x << ", f(3)" << f(3);
            return os;
        }

        /*void test(){
            cout << x << endl;
            for(int i=0; i<A::getLen(); i++){
                cout << A::get(i) << " ";
            }
            cout << endl;
            cout << f(0) << endl;
            cout << foo(0) << endl;
        }*/
};

class C: public A{
    private:
        int y;

    public:
        C(short n, int k): A::A(n){
            y=k;
        }
        double f(short a){
            short r=get(rand()%A::getLen());
            return (a+y)/(double)r;
        }
        short g(short w){
            return sin(w+y);
        }
        ostream& put(ostream& os){
            os << "C arr[";
            for(int i=0; i<A::getLen(); i++){
                os << A::get(i) << " ";
            }
            os << "], y=" << y << ", f(3)" << f(3);
            return os;
        }

        int operator++(){
            ++y;
            return this;
        }
};

int main(){
    //A* obj = new B<string>(5, 'c');
    //((B<string> *)obj)->test();

    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new C(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new B<string>(n, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 2:
            vett[i] = new B<char>(n, rand() % ('z' - 'a' + 1) + 'a');
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << vett[i] << endl;
    }

    //PUNTO 2
    cout << "PUNTO 2" << endl;
    int media;
    double max=INT_MAX;
    for(int i=0; i<DIM; i++){
        if(max < vett[i]->f(3)){
            max=vett[i]->f(3);
        }
        if(typeid(C)==typeid(*vett[i])){
            media+=(dynamic_cast<C*>(vett[i]))->g(5);
        }
    }
    cout << media/DIM << endl;

    //PUNTO 3 
    cout << "PUNTO 3" << endl;
    cout << *vett[48] << endl; 
    cout << *(++(*dynamic_cast<*C>)(vett(48)) << endl;



}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#define DIM 50

using namespace std;

class A{
    private:
        double *vec;
        short len;

    public:
        A(short w, double a, double b){
            vec=new double [w];
            for(int i=0; i<w; i++){
                vec[i]=rand()/(double)(b-a+1)+a;
            }
            len=w;
        }

        virtual bool test(short a)=0;

        protected:
            double selected(double x){
                int somma=0, c=0;
                for(int i=0; i<len; i++){
                    if(vec[i] <= x){
                        somma+=vec[i];
                        c++;
                    }
                }
                return somma/(double)c;
            }
};

class B:public A{
    private:
        short p;

    public:
        B(short m, short a, short b): A(m, a, b){
            p=rand()%(b-a+1)+a;
        }
        bool test(short a){
            if(p >=a)
                return true;
            else
                return false;
        }
};

template <typename T>
class C: public A{
    private:
        T alpha;

    public:
        C(short n, double x, double y): A(n, x){
            if(typeid(double)==typeid(alpha))
                alpha=n;
            else
                aplha=rand()%/(double)((x-y+1)+x)*(-1.0);
        }
        bool selected(short r){
            if(g(r)/alpha >= 1)
                return true;
            else
                return false;
        }
        double g(double k){
            return selected(k)*2;
        }
};

int main(){


}
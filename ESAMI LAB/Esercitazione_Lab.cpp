#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>

using namespace std;

class A{
    private:
        double* vec;
        short len;
        int mul;

    protected:
        double* get_ptr(short i){
            if(i >= len) return nullptr;
            return (vec + i);
        }
        int getLen(){
            return len;
        }

    public:
        A(short w, int m){
            vec=new double[w];
            double r=0.0;
            mul=m;
            for(int i=0; i<w; i++){
                do{
                    r=rand();
                }while(r%mul == 0);
                vec[i]=r;
            }
            len=w;
        }
        virtual void origin();
        void swap(double a, double b){
            int temp = a;
            a = b;
            b = temp;
        }
        void sort(bool a){
            if(a){
                int indexMin;

                for (int i = 0; i < len; i++){
                    indexMin = i;
                    for (int j = i + 1; j < len; j++){
                        if (vec[j] < vec[indexMin])
                            indexMin = j;
                    }
                    swap(vec[i], vec[indexMin]);
                    }
            }else{
                int indexMin;

                for (int i = 0; i < len; i++){
                    indexMin = i;
                    for (int j = i + 1; j < len; j++){
                        if (vec[j] > vec[indexMin])
                            indexMin = j;
                    }
                    swap(vec[i], vec[indexMin]);
                    }
            }
        }
        int factor(short q){
            int i = 1, x = 1;
            do{
                i++;
                x = x * i;
            } while (i < vec[i]);
        }
        void set(double* d, short i){
            vec[i]=*d;
        }
};

class B: public A{
    private:
        char* c;

    public:
        B(short w, int m, char v): A::A(w, m){
            c=new char[A::getLen()];
            char cr='\0';
            for(int i=0; i<A::getLen(); i++){
                do{
                    cr=rand()%('z'-'a'+1)+'a';
                }while(cr!='v');
            }
        }
        double seg_max{
            double _max = 0;
            double somma = _max;
            for (int j = 0; j < n; j++){
                if (somma > 0){
                    somma = somma + *(A::get_ptr(i));
                }
                else{
                    start = j;
                    somma = *(A::get_ptr(i));
                }
                if (somma > _max){
                    end = j;
                    _max = somma;
                }
            }
            return _max;
        }
        void origin(){
            char **w=new char*[A::getLen];
            for(int i=0; i<A::getLen(); i++){
                w[i]=new char[A::getLen()];
                for(int j=0; j<A::getLen(); j++){
                    w[i][j]=rand()%('z'-'a'+1)+'a';
                }
            }
        }
        void edit(){
            string* k=new string [A::getLen()];
            for(int i=0; i<A::getLen(); i++){
                k[i]="";
                for(int j=0; j<A::getLen(); j++){
                    k[i]+=c[i];
                }
            }
        }
};

template <class T>
class C: public A{
    private:
        double p;

    protected:
        T k;

    public:
        C(short w; int m): A::A(w,m){
            p=A::get_ptr(rand()%(A::getLen-0+1)+0);
            if(typeid(k) == typeid(double)){
                k=180*p;
            }else{
                k=m;
            }
        }
        void origin(){

        }
        void position(){
            int r=rand()%(A::getLen()-0+1)+0;
            A::set(p, r);
            A::sort(1);
            double media=0.0;
            for(int i=0; i<A::getLen(), i++){
                media+=A::get_ptr(i);
            }
            media=media/(double)A::getLen();
        }
};

template <class T>
class D:public C{
    private:
        int g;

    public:
        D(short y, int z, int g): C::C(y, z){
            this->g=g;
        }
        void reserve(){
            A::sort(0);
        }
        void quick(){
            for(int i=1; i<A::getLen(); i+=2){
                vec[i]=round(vec[i]/2);
            }
            A::sort(0);
            for(int i=0; i<A::getLen(), i++){
                media+=A::get_ptr(i);
            }
            media=media/(double)A::getLen();
        }
};
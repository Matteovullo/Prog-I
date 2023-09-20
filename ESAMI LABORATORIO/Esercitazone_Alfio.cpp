#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

class A{
    private:
        double* vec;
        short length;
        int mul;

    public:
        A(short w, int m){
            this->mul=m;
            vec=new double[w];
            for(int i=0; i<w; i++){
                double r=0.0;
                do{
                    r=rand()/(RAND_MAX)*1.0;
                }while((int)(r)%mul != 0);
                vec[i]=r;
            }
            this->length=w;
        }
        virtual void origin()=0;
        void sort(bool a){
            if(a==true){
                int k=length;
                double max=vec[0];
                double aux[length];
                int index=0;
                for(int i=0; i<length; i++){
                    for(int j=0; j<length; j++){
                        if(vec[i] > max){
                            max = vec[i];
                            index = i;
                        }
                    }
                    aux[k]=vec[index];
                    vec[index]=0.0;
                    k--;
                    max=-1254888855.0;
                }
                for(int i=0; i<length; i++){
                    vec[i]=aux[i];
                }
            }else{
                int k=length;
                double min=vec[0];
                double aux[length];
                int index=0;
                for(int i=0; i<length; i++){
                    for(int j=0; j<length; j++){
                        if(vec[i] < min){
                            min = vec[i];
                            index = i;
                        }
                    }
                    aux[k]=vec[index];
                    vec[index]=0.0;
                    k--;
                    min=222222222222222.0;
                }
                for(int i=0; i<length; i++){
                    vec[i]=aux[i];
                }
            }
        }
        int factor(short q){
            int fatt=1;
            int val=vec[q];
            int c=1;
            while(c<val){
                fatt=fatt*(fatt+1);
                c++;
            }
            return fatt;
        }
        void set(double *d, short i){
            vec[i]=*d;
        }
        double get(short index){
            return vec[index];
        }

    protected:
        double* get_ptr(short i){
            double *ptr;
            *ptr=vec[i];
            return ptr;
        }
        int get_len(){
            return length;
        }
};

class B : public A{
    private:
        char *c;

    public:
        B(short w, int m, char v) : A(w, m){
            c=new char[get_len()];
            for(int i=0; i<get_len(); i++){
                char r='\0';
                do{
                    r=rand();
                }while(r == v);
                c[i]=r;
            }
        }
        double seg_max(){
            double somma=0;
            double max_somma=somma;
            for(int i=0; i<get_len(); i++){
                for(int j=i; j<get_len(); j++){
                    somma+=*get_ptr(i);
                }
                if(somma > max_somma){
                    max_somma=somma;
                }
                somma=0.0;
            }
            return somma;
        }
        void origin(){
            char matrice[get_len()][get_len()];
            for(int i=0; i<get_len(); i++){
                for(int j=0; j<get_len(); j++){
                    matrice[i][j]=rand()%('z'-'a'+1)+'a';
                }
            }
        }
        void edit(){
            string k[get_len()];
            for(int i=0; i<get_len(); i++){
                k[i]="";
            }
            for(int i=0; i<get_len(); i++){
                if(k[i].empty() == 1){
                    for(int j=0; j<get_len(); j++){
                        int r=rand()/(get_len()+1);
                        if(k[i].find(c[r]) == string::npos){
                            k[i]+=c[r];
                        }
                    }
                }
            }
        }
};

template<class T>
class C : public A{
    private:
        double p;

    protected:
        T k;

    public:
        C(short w, int m) : A(w ,m){
            this->p=get_ptr(rand()%(get_len()+1));
            if(typeid(k) == typeid(double)){
                this->k=ceil(180*p);
            }else{
                this->k=m;
            }
        }
        void origin(){
            double q[get_len()];
            for(int i=0; i<get_len(); i++){
                q[i]=factor(vec[i]);
            }
        }
        void position(){
            set(&p , rand()%(get_len()+1));
            sort(true);
            double media=0.0;
            for(int i=0; i<get_len(); i++){
                media+=*get_ptr(i);
            }
        }
};

template<class T>
class D : public C<T>{
    private:
        int g;
    
    public:
        D(short y, int z, int g) : C<T>::C(y, z){}
        void reverse(){
            double aux[C<T>::get_len()];
            int j=C<T>::get_len();
            for(int i=0; i<C<T>::get_len(); i++){
                aux[j] = C<T>::get(i);
                j--;
            }
            for(int i=0; i<C<T>::get_len(); i++){
                aux[i] = C<T>::get(i);
            }
        }
        double quick(){
            for(int i=0; i<C<T>::get_len(); i++){
                if(C<T>::get(i)%2 != 0){
                    C<T>::set(&round(C<T>::get(i)), i);
                }
            }
            C<T>::sort(false);
            double media=0.0;
            for(int i=0; i<C<T>::get_len(); i++){
                media+=C<T>::get(i);
            }
            return media;
        }
        int MCD(int a, int b){
            if(a > b && a%b == 0){
                return b;
            }else if(b==0){
                return a;
            }else{
                do{
                    int r=a%b;
                    a=b;
                    b=r;
                }while(b==0);
                return a;
            }
        }
        void origin(){
            double vettore[C<T>::get_len()];
            for(int i=0; i<C<T>::get_len(); i++){
                vettore[i]=MCD(g, floor(C<T>::get(i)));
            }
        }
};

int main(){
    return 0;
}
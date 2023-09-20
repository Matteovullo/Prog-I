#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>

#define DIM 50

using namespace std;

class A{
    private:
        int x;

    public:
        A(int m) {
            this->x=m;
        }
        virtual double const v(int a)=0;

        virtual ostream &put(ostream &os){
        os << typeid(*this).name() << ", x=" << x;
        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        int *ptr;
        int l;

    protected:
        int const sum(int t){
            int somma=0;
            for(int i=0; i<l; i++){
                if(ptr[i] <= t){
                    somma+=ptr[i];
                }
            }
            return somma;
        }

    public:
        B(int z, int y) : A(z){
            ptr=new int[y];
            for(int i=0; i<y; i++){
                ptr[i]=rand()%(100-1+1)+1;
            }
            this->l=y;
        }
        double const v(int a){
            int s=sum(a)+1;
            return 1*1000/(double)s;
        }

        ostream &put(ostream &os){
        A::put(os);
        os << ", ptr=[ ";
        for(int i=0; i<l; i++){
            os << ptr[i] << " ";
        }
        os << "], ";
        os << ", v(50)=" << v(50);
        return os;
        }
        int &operator[](short indice){
     		return ptr[indice]; 
    	}
};

template<class T>
class C : public A{
    private:
        T k;

    public:
        C(int n) : A(n){
            if(typeid(k)==typeid(int))
                this->k=2*n;
            else
                this->k=log((1+pow(sin(n), 2)));
        }
        T const g(T w){
            return (k*(w+1));
        }
        double const v(int r){
            return g(r);
        }

        ostream &put(ostream &os){
        A::put(os);
        os << ", k=" << k << ", v(50)=" << v(50);
        return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        int n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new C<int>(n);
            break;
        case 2:
            vett[i] = new C<double>(n);
        }
    }

    //PUINTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    int media=0;
    int c=0;
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0; i<DIM; i++){
        if(typeid(vett[i]) == typeid(C<double>)){
            media+=dynamic_cast<C<double>*>(vett[i])->g(5);
            c++;
        }
        if(vett[i]->v(50) > max){
            max=vett[i]->v(50);
        }
        if(vett[i]->v(50) <
         min){
            min=vett[i]->v(50);
        }
    }

    cout << "min(v(50))=" << min << ", max(v(50))=" << max << endl;
    cout << "Avg(g(5))=" << media/(double)c;
    /*
    //PUNTO 3
    cout<<1<<") "<<*vett[2]<<"\n";
  	(*vett[2])[4]=1000; 
  	cout<<1<<") "<<*vett[2]<<"\n";
    */
    return 0;
}
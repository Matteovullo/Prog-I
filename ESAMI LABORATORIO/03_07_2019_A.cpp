#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <climits>
#include <cmath>

#define DIM 50

using namespace std;

class A{
    int *arr;
    short len;

    public:
        A(int m, int a, int b){
            arr=new int [m];
            for(int i=0; i<m; i++){
                arr[i]=rand()%(b-a+1)+a;
            }
            this->len=m;
        }
        virtual double func(short i)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", arr[";
            for(int i=0; i<len; i++){
                os  << get(i) << " ";
            }
            os << " ]";
            return os;
        }
        int &operator[](short indice){
     		return arr[indice]; 
    	}

    protected:
        double get(short i){
            return arr[i%len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A{
    double p;

    public:
        B(int m, int y, int z, double x) : A(m, y, z){
            this->p=m;
        }
        double func(short i){
            int min=get(0);
            int max=get(0);
            for(int i=0; i<getLen(); i++){
                if(get(i) > max){
                    max=get(i);
                }
                if(get(i) < min){
                    min=get(i);
                }
            }
            return (min/(double)max)+p;
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", p=" << p << ", func(3)=" << func(3);
            return os;
        }
};

class C : public A{
    char t;

    public:
        C(short n, char c, int a, int b) : A(n, a, b){
            this->t=c;
        }
        double func(short i){
            int media=0;
            int c=0;
            for(int i=0; i<getLen(); i++){
                media+=get(i);
                c++;
            }
            return media/(double)c;
        }
        string g(char c, short k){
            string s="";
            s+=t;
            s+=c;
            for(int i=0; i<k; i++){
                s+=s;
            }
            return s;
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", t=" << t << ", func(3)=" << func(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A* vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        if (rand() % 2 == 0)
            vett[i] = new B(n, rand() % 5 + 1, rand() % 11 + 10, (double)rand() / (RAND_MAX));
        else
            vett[i] = new C(n, (char)(rand() % ('z' - 'a' + 1) + 'a'), rand() % 5 + 1, rand() % 11 + 10);
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    int c=0;
    int media=0;
    int count=0;
    for(int i=0; i<DIM; i++){
        media+=vett[i]->func(3);
        c++;
        if(typeid(vett[i])==typeid(C) && count < 3){
            count++;
            cout << "i=" << i << "g('h,2)=" << dynamic_cast<C*>(vett[i])->g('h', 2) << endl;
        }
    }
    cout << "Avg(f(3))=" << media/(double)c;
    cout << endl;

    //PUNTO 3
  	cout<<1<<") "<<*vett[1]<<"\n";
  	(*vett[1])[2]=0.9; 
  	cout<<1<<") "<<*vett[1]<<"\n";

    return 0;
}
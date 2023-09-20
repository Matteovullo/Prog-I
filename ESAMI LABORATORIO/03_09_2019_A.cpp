#include <iostream>
#include <cmath>
#include <climits>
#include <typeinfo>
#define DIM 50

using namespace std;

class A{
    private:
        int *arr;
        short len;

    public:
        A(short m, int a, int b){
            len=m;
            arr=new int[len];
            for(int i=0; i<len; i++){
                arr[i]=rand()%(b-a+1)+a;
            }
        }
        virtual double func(short i)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", vec=[";
            for(int i=0; i<A::getLen(); i++){
                os << arr[i] << " ";
            }
            os << "], ";
            return os;
        }
        int operator[](int num){
            return num;
        }

    protected:
        double get(short i){
            return arr[i%len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        double p;

    public:
        B(short m, int y, int z, double x): A::A(m, y, z){
            p=x;
        }
        double func(short i){
            int max=A::get(i);
            int min=A::get(i);
            for(int i=0; i<A::getLen(); i++){
                if(A::get(i) > max)
                    max=A::get(i);
                if(A::get(i) < min)
                    min=A::get(i);
            }
            return (min/max)+p;
        }
        virtual ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", func(3)=" << func(3); 
            return os;
        }

};

class C: public A{
    private:
        char t;

    public:
        C(short n, int a, int b, char c): A::A(n, a, b){
            t=c;
        }
        double func(short i){
            int somma=0;
            for(int i=0; i<A::getLen(); i++){
                somma+=A::get(i);
            }
            return somma/A::getLen();
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
        virtual ostream& put(ostream& os){
            A::put(os);
            os << "t=" << t << ", func(3)=" << func(3); 
            return os;
        }
};

int main(){
    srand(111222333); 
    A* vett[DIM];    

    for(int i=0; i<DIM; i++){
	short n=1+rand()%10;
	if(rand()%2==0)
	  vett[i]= new B(n, rand()%5+1, rand()%11+10, (double) rand()/(RAND_MAX));
	else
	  vett[i]= new C(n, (char) (rand()%('z' - 'a' + 1) + 'a'), rand()%5+1, rand()%11+10);
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vett[i] << endl;
    }

    cout << "PUNTO 2" << endl;
    int media=0;
    for(int i=0; i<DIM; i++){
        media+=vett[i]->func(3);
        if(typeid(C)==typeid(*vett[i]))
            cout <<(dynamic_cast<C*>(vett[i]))->g('h', 2) << endl;
    }
    cout << ", Avg=" << media/(double)DIM << endl;
    
    cout << "PUNTO 3" << endl;
    cout << "vett[5]=" << *vett[5] << endl;
    cout << "vett[5]=" << (*vett[5])[5] << endl;
}
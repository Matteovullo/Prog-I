#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define DIM 50

class A{
    private:
        int *ptr;
        short len;

    public:
        A(short m, short k){
            len=m;
            ptr=new int[m];
            for(int i=0; i<m; i++){
                ptr[i]=rand()%(k-1+1)+1;
            }
        }
        int get(short i) const{
            int posto=i%len;
            return ptr[posto];
        }
        short getLen() const { return len; }

        virtual double f()=0;

        virtual ostream& put(ostream& os) {
            os << typeid(*this).name() << ", ptr=[ ";
            for(int i = 0; i < len; i++) {
                os << ptr[i] << " ";
            }
            os << "], ";
            return os;
        }

        int& operator[](int i) {
            return ptr[i % len];
        }

};

class B: public A{
    private:
        double p;

    public:
        B(short m, short k , double y): A(m, k){}
        double f(){
            int somma=0;
            for(int i=0; i<getLen(); i++){
                if(get(i)%2 == 0)
                somma+=get(i);
            }
            return somma/(double)p;
        }

        ostream& put(ostream& os) {
            A::put(os);
            os << "p=" << p << ", f()=" << f();
            return os;
        }
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class C: public A{
    private:
        char x;

    public:
        C(short n, short k, char c): A(n, k){
            x=c;
        }
        double f(){
            int somma=0, k=0;
            for(int i=0; i<getLen(); i++){
                if(get(i)%2 == 0){
                    somma+=get(i);
                    k++;
                }
            }
            if(k == 0){
                return 0.0;
            }else{
                return somma/(double)k;
            }
        }
        string g(char c) const{
            string s="";
            s+=x;
            s+=c;
            return s;
        }

        ostream& put(ostream& os) {
            A::put(os);
            os << "x=" << x << ", f()=" << f();
            return os;
        }
};

int main(){
    srand(111222333);
    A *vett[DIM];

    for (int i = 0; i < DIM; i++) {
	    short n = 1 + rand() % 10;
	    short m = 1 + rand() % 8;
	    if (rand() % 2 == 0)
		vett[i] = new B(n, m, rand() / (double)RAND_MAX + 0.05);
	    else
		vett[i] = new C(n, m, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double somma = 0;
    string concat = "";
    for(int i = 0; i < DIM; i++) {
        somma += vett[i]->f();
        if(typeid(*vett[i]) == typeid(C)) {
            concat += ((C*)(vett[i]))->g('h');
        }
    }
    cout << "Avg(f())=" << somma/DIM << ", concat=" << concat << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[5] << endl;
    (*vett[5])[0] = -1;
    cout << *vett[5] << endl;
}
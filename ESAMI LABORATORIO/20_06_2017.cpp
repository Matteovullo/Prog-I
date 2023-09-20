#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 50
#define N 5

using namespace std;

class A{
    private:
        float *x;

    public:
        A(float a) {
            x=new float[N];
            for(int i=0; i<N; i++){
                if(i==0){
                    x[i]=a;
                }else{
                    x[i]=(float)(sin((100*x[i-1])));
                }
            }
        }
        virtual float f()=0;
        float* getX(){
            return x;
        }
        ostream &put(ostream &os) const{
        os << typeid(*this).name(); 
        os << "[";
        for(int i=0; i<N; i++){
            os << x[i] << " ";
        }
        os << "]";
        return os;
        }
};

ostream& operator<<(ostream &stream, const A &a) {
		a.put(stream);
		return stream;
}

class B : public A{
    public:
        B(float f) : A(f){}
        float f(){
            float* array=getX();
            float max=array[0];
            for(int i=0; i<N; i++){
                if(array[i] > max){
                    max = array[i];
                }
            }
            return max;
        }
};

class C : public A{
    public:
        C(float f) : A(f){}
        float f(){
            float* array=getX();
            float media=0.0;
            for(int i=0; i<N; i++){
                media += array[i];
            }
            return media/N;
        }
        int gte(float thr){
            float* array=getX();
            int c=0;
            for(int i=0; i<N; i++){
                if(array[i] > thr){
                    c++;
                }
            }
            return c;
        }
};

class D{
    private:
        A* a;
        B* b;
        C c;

    public:
        D(float seed) : c(seed/3){
            if(seed>0.5){
                a=new B(seed);
            }else{
                a= new C(seed);
            }
            this->b=new B(seed/3);
        }
        float m() {
			float sum = 0;

			for(int i=0; i<N; i++) {
				if(a->getX()[i] > b->getX()[i] 
				&& a->getX()[i] > c.getX()[i])
					sum+=a->getX()[i];
				else if(b->getX()[i] > a->getX()[i] 
				&& b->getX()[i] > c.getX()[i])
					sum+=b->getX()[i];
				else
					sum+=c.getX()[i];
			}

			return sum;
		}
        float h(float thr){
            float out=c.f()/b->f();
            if(typeid(*a)==typeid(C)){
                out*=dynamic_cast<C*>(a)->gte(thr);
            }
            return out;
        }
        ostream& put(ostream &stream) const {
			stream << *a << endl << *b << endl << c;
			return stream;
		}
};

ostream& operator<<(ostream &stream, const D &d) {
		d.put(stream);
		return stream;
}

int main(){
	D *vett[DIM];
	
	srand(111222333);
	float somma = 0;
	for (int i=0; i<DIM; i++) {
		vett[i] = new D((float)rand()/RAND_MAX);

		cout << i << *vett[i] << endl;

		float h = vett[i]->h(.7);
		somma+=h;
		cout << "\t \t \t \t h(.7)=" << h << "\t m()="<<vett[i]->m()<<endl<<endl;
	}

	cout << "Punto 1) Media="<<somma/DIM<<endl;

	cout << "Punto 2) vett[4].m()+vett[5].m()="<<vett[4]->m()+vett[5]->m()<<endl;

    return 0;
}

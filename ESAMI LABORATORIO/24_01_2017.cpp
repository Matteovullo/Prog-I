#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>
#define n 5

using namespace std;

class A{
    private:
      float *x;

    public:
        A(float a){
            x=new float[n];
            for(int i=0; i<n; i++){
                if(i==0){
                    x[i]='a';
                }else{
                    x[i]=(float)(sin(100*x[i-1]));
                }
            }
        } 
        virtual float f()=0;
        float* getX(){
            return x;
        }
        ostream& put(ostream &stream) const {
			stream << "\t class "<<typeid(*this).name()<<" [ ";
			for(int i=0; i<n; i++) {
				stream << x[i] << " ";
			}
			stream << "]";
			return stream;
		}
};

ostream& operator<<(ostream &stream, const A &a) {
		a.put(stream);
		return stream;
}

class B: public A{
    public:
        B(float f): A::A(f){}
        float f(){
            float *x=A::getX();
            float max=x[0];
            for(int i=0; i<n; i++){
                if(x[i] > max) max=x[i];
            }
            return max;
        }

};

class C: public A{
    public:
        C(float t): A::A(t){}
        float f(){
            float somma=0;
            float *x=A::getX();
            for(int i=0; i<n; i++){
                somma+=x[i];
            }
            return somma/(float)n;
        }
        int gte(float thr){
            int c=0;
            float* x=A::getX();
            for(int i=0; i<n; i++){
                if(x[i] > thr)
                    c++;
            }
            return c++;
        }
};

class D{
    private:
        A* a;
        B* b;
        C c;

    public:
        D(float seed): c(seed/3){
            if(seed>0.5){
                a= new B(seed);
            }else{
                a= new C(seed);
            }
            b= new B(seed/2);
        }
        float m() {
			float sum = 0;

			for(int i=0; i<n; i++) {
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

		float h(float thr) {
			float out = c.f() / b->f();
			if(typeid(*a) == typeid(C))
				out*=((C*) a)->gte(thr);
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
	const int DIM = 50;
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
}
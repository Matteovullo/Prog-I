#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>


using namespace std;

class Myarray{
    private:
        int dim;
        short *data;

    public:
        Myarray(int i){
            this->dim=i;
            data=new short[dim];
            for(int i=0; i<dim; i++){
                data[i]=(short)(dim*(sin(dim+1)));
            }
        }
        float avg(){
            float media=0;
            for(int i=0; i<dim; i++){
                media+=data[i];
            }
            return media/dim;
        }
        int grater(int i){
            int c=0;
            for(int i=0; i<dim; i++){
                if(data[i] > i){
                    c++;
                }
            }
            return c;
        }
        ostream &output(ostream &os) const{
            os << "[";
            for(int i=0; i<dim; i++){
                os << data[i] << " ";
            }
            os << "]";
            return os;
        }
};

class A{
    private:
        int dim;

    protected:
        Myarray *x;

    public:
        A(int i) {
            this->dim=i;
            x=new Myarray(dim);
        }
        virtual float f() const=0;
        virtual ostream &put(ostream &os){
        os << "Class " << typeid(*this).name() << ", dim=" << dim;
        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    public:
        B(int i) : A(i){}
        float f() const{
            return x->avg();
        }

        ostream &put(ostream &os){
        A::put(os);
        x->output(os);
        os << "f()=" << f();
        return os;
        }
};

class C : public A{
    private:
        double w;

    public:
        C(int i, double d) : A(i){
			this->w=d;
		}
        float f() const{
            return x->grater((int)w);
        }
        float f(int i) const{ 
            return (float)w*i;
        }

        ostream &put(ostream &os){
        A::put(os);
        x->output(os);
        os << ", w=" << w << " f()=" << f() << " f(4)=" << f(4); 
        return os;
        }
};

int main() {
	const int DIM = 30;
	A* vett[DIM];

	float somma = 0;
	int conta_c = 0;

	int indice_c;
	float f4;

	srand(833274768);
	for(int i=0; i<DIM; i++) {
		int x=1+rand()%5;
		switch(x%2) {
			case 0: vett[i] = new B(x);
					break;
			case 1: vett[i] = new C(x, x/(double)RAND_MAX*10000);
		}

		somma+=vett[i]->f();

		if(typeid(*vett[i])==typeid(C)) {
			conta_c++;
			if(conta_c==5){
				indice_c=i;
				f4 = ((C*)vett[i])->f(4);
			}
		}

		cout<<i<<") "<<*vett[i]<<endl;
	}

	cout << "punto 1 : sum="<<somma<<"\t\t punto 2 : f(4)="<<f4<<" di indice "<<indice_c<<endl;
}
	
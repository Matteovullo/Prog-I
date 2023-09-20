//LIBRERIE:
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <climits>

#define DIM 50

using namespace std;


//OVERLOADING
//OVERLOAD OPERATORE <<:
class a{
		virtual ostream& put(ostream &s){
			s<<" ptr=[ ";
			for(int i=0;i<len;i++)
				s<<ptr[i]<<" ";
			s<<"]";
			return s;
			
		}
};

class b{
		ostream& put(ostream &s){
			s<<typeid(*this).name()<<" ";
			A::put(s);
			s<<"alpha= "<<alpha<<" "<<endl;	
			s<<"foo(5)= "<<foo(5)<<" "<<endl;	
			return s;
		}

};

class c{
		ostream& put(ostream &s){
			s<<typeid(*this).name()<<" ";
			A::put(s);
			s<<"   x= "<<x<<" "<<endl;
			s<<"   foo(5)= "<<foo(5)<<" "<<endl;
			s<<"   g(5)= "<<g(5)<<" "<<endl;	
			return s;
		}

};

//fuori dalle classi:

ostream &operator << (ostream &left, A &obj){//per fare overload degli operatori	
	return obj.put(left);
}

int main(){
	cout << "Punto I: " << endl;
   	for(int i=0; i<DIM; i++){
       	cout << i << ")" << *vett[i]  <<  endl;
	}
}

//OVERLOAD OPERATORE[]:
class A{
	double &operator[](short indice){
     	return ptr[indice]; 
    }
};

int main(){
	cout<<endl<<"PUNTO III:  "<<endl;
  	cout<<1<<") "<<*vett[1]<<"\n";
  	(*vett[1])[2]=0.9; 
  	cout<<1<<") "<<*vett[1]<<"\n";
}

//OVERLOAD OPERATORE()
int operator()(int i1, int i2){
			int sum = 0;
			for(int a=0; a<len; a++){
				if(a>=i1 && a<=i2)
					sum += vec[a];
			}
			return sum;
		}

cout<<"*vett[5]: "<<*vett[5]<<endl;
cout<<"vett[5](1, 3): "<<(*vett[5])(1, 3)<<endl;

//OVERLOAD OPERATORE=
Point2D &operator=(Point2D& p) {
            x=p.x;
            y=p.y;
            cout << "Operatore ="<<endl;
            return *this;
        }
};

int main() {
    Point2D p1(2,3);
    Point2D p2(4,8);
    Point2D p3=p1;
    p3 = p2;
}

//OPERATORE +
#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        double getX() {return x;}
        double getY() {return y;}
        friend Point2D operator+(Point2D, Point2D);
};

Point2D operator+(Point2D a, Point2D b){
    return Point2D(a.x+b.x, a.y+b.y);
}

int main() {
    Point2D p1(2,3);
    Point2D p2(3,3);

    Point2D p3 = p1+p2;
    cout << "("<<p3.getX() << "," << p3.getY() << ")" << endl;
}

//OVERLOAD OPERATORE ++ PREFISSO
int main(){	
	cout << "Punto III: " << endl;
	for(int i=0;i<DIM;i++){
		if(typeid(*vett[i]) == typeid(B)){
			cout<< *vett[i]<<endl;	
			B *ptr_b = dynamic_cast<B*>(vett[i]);      //passo index per index ad un puntatore a C d'appoggio 
			++(*ptr_b);
			cout<<*ptr_b<<endl;
		}
	}
}


//DENTRO LA CLASSE DOVE SI DEVE FARE L'OVERLOAD ++ PREFISSO
Class C{
		C &operator ++(){
			p++;		   //prefisso per oggetti C
			return *this;
		}  
}

//OVERLOAD OPERATORE ++ POSTFISSO
int main(){
			cout << "Punto III: " << endl;
	
			cout<< *vett[0]<<endl;	
			B *ptr_b = dynamic_cast<B*>(vett[0]);      //passo index per index ad un puntatore a C d'appoggio 
			(*ptr_b)++;
			cout<<*ptr_b<<endl;

}


//DENTRO LA CLASSE POSTFISSO
Class B{
		B &operator ++(int){
			B aux = *this;
			p++;		   //prefisso per oggetti B
			return *this;
		}   
}

//OPERATORE POSTFISSO E PREFISSO ++ E --
#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        Point2D(double _x) : x(_x), y(_x) {}
        double getX() {return x;}
        double getY() {return y;}
        Point2D &operator++() { //prefisso
            x++; //decrementa
            y++;
            return *this; //passa un riferimento a se stesso (modificato)
        }
        Point2D operator++(int) { //postfisso - parametro dummy "int" per distinguere dal caso prefisso
            Point2D aux = *this; //crea una copia
            x++; //incrementa se stesso (non la copia)
            y++;
            return aux; //passa la copia non aggiornata
        }

        friend Point2D &operator--(Point2D&); //prefisso
        friend Point2D operator--(Point2D&, int); //postfisso - con parametro dummy
        friend ostream& operator<<(ostream&, Point2D);
        
};

ostream& operator<<(ostream &s, Point2D p) {
    // inserisco una rapresentazione di p nel riferimento a ostream
    s << "(" << p.x << "," << p.y << ")";
    return s; //restituisco il riferimento
}

Point2D &operator--(Point2D& p) { //prefisso
    p.x--;
    p.y--;
    return p;
}

Point2D operator--(Point2D& p, int) { //postfisso - con parametro dummy
    Point2D aux = p;
    p.x--;
    p.y--;
    return aux;
}

int main() {
    Point2D p(2,3);
    cout << ++p << endl;
    cout << p++ << endl;
    cout << p << endl<<endl;

    cout << --p << endl;
    cout << p-- << endl;
    cout << p << endl;
}


//SOMMA O MEDIA TRA VALORI DI FUNZIONI:
//SOLITAMENTE PUNTO 2:
	cout << "Punto II: " << endl;
	int max=INT_MIN;
	int somma=0;
	
	for(int i=0;i<DIM;i++){
		if(typeid(*vett[i])==typeid(C<double>)){
			C<double>* tmp=(C<double>*)vett[i];  //dynamic_cast<C<double*>(vett[i])->funzione;
			if(tmp->g(5)>somma){
				somma=tmp->g(5);
			}
		}
	}
	
	for(int i=0;i<DIM;i++){
		if(vett[i]->foo(5)>max)
			max=vett[i]->foo(5);
	}
	cout<<"il massimo di foo(5) e': "<<max<<endl;
	cout<<endl;

	cout<<"la somma di g(5) e' : "<<somma<<endl;
	cout<<endl;

//STAMPA LA MEDIA
	cout<<"Punto II: "<<endl;
	double m=0.0;
	for(int i=0;i<DIM;i++){
		m += vett[i]->elab(3);	
	}
	cout<<"la media e': "<<m/DIM<<endl;

//CAST 
for(int i=0;i<DIM;i++){
	if(typeid(*vett[i])==typeid(c)){
		sum1+=((c*)vett[i])->g(5);
		sum1+=dynamic_cast<c*>(vett[i])->g(5);
	}
}

//TEMPLATE 
template<class T>
class C : public A {
    private:
        T y;

    public:
        C(short n, double x, double y) : A(n, x, y) {
            if(typeid(T) == typeid(short)) {
                this->y = n;
            }
            else {
                this->y = 1 + pow(cos(n), 2);
                //this->y = 1 + cos(n) * cos(n);
            }
        }
}

//UTILIZZO TEMPLATE
for(int i = 0; i < DIM; i++) {
        if(vett[i]->foo(3) > max) max = vett[i]->foo(3);
        if(typeid(*vett[i]) == typeid(C<double>)) {
            somma_g += ((C<double>*)vett[i])->g(0.5);
            count++;
        }
    }
    cout << "Max = " << max << ", " << "avg = " << somma_g/count;

//PUO SERVIRE : 
string g(char c) const{
    string r;
    r=this->x;
	r=r+c; 
    return r;
}

//CONCATENAZIONE TRA STRINGHE
string g(char c) {
	stringstream ss;
	string tmp;
	ss<<x;
	ss<<c;
	ss>>tmp;
	return tmp;
}

int main(){//stampa concatenazione stringa g('h')
	stringstream sx;
	string tmp;
	for(int i=0;i<DIM;i++){
		if(typeid(*vett[i]) == typeid(C)){
			sx<<((C*)vett[i])->g('h');
		}
	}
	sx>>tmp;
	cout<<"la stringa e': "<<tmp<<endl;
}

//STATIC
class n{
	static int count;
}
int n :: count = 0;


//FRIEND
class Point2D {
    private:
        double x, y;
    public:
        friend void normalize(Point2D &p);
        Point2D() : x(0), y(0) {}
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        double getX() const {return x;}
        double getY() const {return y;}
};

#include<cmath>
void normalize(Point2D &p) {
    double mod = sqrt(p.x*p.x + p.y*p.y);
    p.x/=mod;
    p.y/=mod;
}

//RAND
vec[i]=rand()%(b-a+1)+a;
vec[i] = (char)(rand()%((int) 'z' - (int) 'a' + 1) + (int) 'a');
//vec[i] = a + ((double)rand() / RAND_MAX) * (b - a + 1);
vec[i]=(b-a)*(1.0*rand()/RAND_MAX)+a;
vec[i] = rand()/(double)RAND_MAX;

//PERCENTUALE
percentuale = (count * 100)/(n*m);
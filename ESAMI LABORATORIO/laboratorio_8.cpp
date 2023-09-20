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
        string s;

    public:
        A(string s) {
            this->s=s;
        }
        string getS(){
            return s;
        }
        bool lunga(){
            if(s.length() > 3){
                return true;
            }else{
                return false;
            }
        }
        virtual ostream &put(ostream &os){
        os << typeid(*this).name();
        os << " stringa=" << s;
        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        int y;

    public:
        B(string s, int y) : A(s){
            this->y=y;
        }
        bool lunga(){
            if(getS().length() > y){
                return true;
            }else{
                return false;
            }
        }
        string estrai() {
			int l = y-5;
			string out = "";
			for(int i=0; i<l; i++)
				out+="*";
			return out;
		}
        ostream &put(ostream &os){
        A::put(os);
        os << " y=" << y; 
        return os;
        }
};

class C : public A{
    private:
        char c;

    public:
        C(string s, char c) : A(s){
            this->c=c;
        }
        string estrai(short x) {
			string s = getS();
			if (x<s.length())
				return s.substr(x,x+1);
			else
				return s.substr(s.length()-3);
		}
        ostream &put(ostream &os){
        A::put(os);
        os << " c=" << c;
        return os;
        }
};

class D : public C{
    private:
        int z;

    public:
        D(string s, char c, int z) : C(s, c){
            this->z=z;
        }
        string estrai() {
			string s = getS();
			if(z<s.length())
				return s.substr(z,z+1);
			else
				return s.substr(0,2);
		}
        ostream &put(ostream &os){
        A::put(os);
        os << " z=" << z;
        return os;
        }
};

int main() {
	const int DIM = 30;
	A* vett[DIM];
	int lunghi = 0;
	string str1 = "";
	string str2 = "";
	
	srand(111222333);
	for(int i=0; i<DIM; i++){
		int p = rand()%10+3;
		string str = "";
		for (int j=0; j<p; j++) str+=(char) ('A' + rand()%26);
		int a = rand()%15;
		if (rand()%2==1)
			vett[i] = new D(str, (char)('A'+rand()%26),a);
		else
			vett[i] = new B(str,a);
	}

	for (int i=0; i<DIM; i++) {
		cout << *vett[i] << endl;
		if(vett[i]->lunga())
			lunghi++;
        
        if(typeid(*vett[i])==typeid(B))
		    str1 += dynamic_cast<B*>(vett[i])->estrai();

        if(typeid(*vett[i])==typeid(D))
		    str1 += dynamic_cast<D*>(vett[i])->estrai();

		if(typeid(*vett[i])==typeid(D))
			str2+=((C*)vett[i])->estrai(4);
	}

	cout << "Punto 1: lunghi="<<lunghi<<" estrai=\""<<str1<<"\""<<endl;
	cout << "Punto 2: estrai(4)=\""<<str2<<"\""<<endl;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>

using namespace std;

class A{
    private:
        string s;

    public:
        A(string s){
            this->s=s;
        }
        string getS(){
            return s;
        }
        bool doppia(){
            for(int i=0; i<s.length(); i++){
                char c=s[i];
                for(int j=0; j<s.length(); j++){
                    if(i!=j && c==s[j]){
                        return true;
                    }
                }
            }
            return false;
        }  
        virtual string nuova()=0;

        virtual ostream &put(ostream &os){
        os << typeid(*this).name(); 
        os << " " << s;
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
        B(string s, int i) : A(s){
            this->y=i;
        }
        bool doppia(){
            string vocali="AEIOUaeiou";
            for(int i=0; i<getS().length(); i++){
                if(vocali.find((getS())[i]) != string::npos){
                for(int j=0; j<getS().length(); j++){
                    if(vocali.find((getS())[i]) != string::npos){
                        if((getS())[i] == (getS())[j]){
                            return true;
                        }
                    }
                }
                }
            }
            return false;
        }
        string nuova(){
            if(y%3 == 0){
                return getS().substr(0, 3);
            }else{
                return getS().substr(getS().length() -3, 3);
            }
        }

        ostream &put(ostream &os){
        A::put(os);
        os << ", y=" << y;
        return os;
        }
};

class C : public A{
    protected:
        char c;

    public:
        C(string s, char c) : A(s){}
        string nuova(){
            string newstring="";
            for(int i=1; i<getS().length(); i++){
                if(i==0)
                    newstring+=getS()[i];
                else
                    newstring+='*';
            }
            return newstring;
        }

        ostream &put(ostream &os){
        A::put(os);
        cout << ", c=" << c;
        return os;
        }
};

class D: public C{
    public:
        D(string s, char c) : C(s, c){}
        string nuova(short x){
            string newstring="";
            newstring+=c;
            for(int i=0; i<x; i++){
                int l=getS()[i];
                newstring+=(char)(l+1);
            }
            return newstring;
        }
};

int main() {
		const int DIM = 30;
		A* vett[DIM];

		string nuova = "";
		string nuova3 = "";
		int doppi = 0;

		srand(111222333);
		for (int i=0; i<DIM; i++) {
				int p = rand()%5+3;
				string str = "";
				for (int j=0; j<p; j++)
						str += (char) ('a' + rand()%26);

				if (rand()%2==1)
						vett[i] = new D(str, (char) ('a' + rand()%26));
				else 
						vett[i] = new B(str, rand()%15);

				cout << i << ")" << *vett[i] << endl;

				nuova += vett[i]->nuova().substr(0,2);

				if(typeid(*vett[i])==typeid(D))
						nuova3 += ((D*) vett[i])->nuova(3).substr(0,3);

				if(vett[i]->doppia())
						doppi++;
		}

		cout << "nuova()=\""<<nuova<<"\""<<endl;
		cout << "nuova(3)=\""<<nuova3<<"\""<<endl;
		cout << "doppi="<<doppi<<endl;
}